// ElmaHelperASM.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "ElmaHelperASM.h"
#include <iostream>
#include "Memory.h"
#include <metahost.h>
#pragma comment(lib, "mscoree.lib")

#define dllexp __declspec(dllexport)

extern "C" DWORD dllexp fnElmaHelperASM()
{
    ICLRMetaHost* metaHost = NULL; 
    ICLRRuntimeInfo* runtimeInfo = NULL; 
    ICLRRuntimeHost* runtimeHost = NULL; 

    if (CLRCreateInstance(CLSID_CLRMetaHost, IID_ICLRMetaHost, (LPVOID*)&metaHost) == S_OK) 
        if (metaHost->GetRuntime(L"v4.0.30319", IID_ICLRRuntimeInfo, (LPVOID*)&runtimeInfo) == S_OK) 
            if (runtimeInfo->GetInterface(CLSID_CLRRuntimeHost, IID_ICLRRuntimeHost, (LPVOID*)&runtimeHost) == S_OK)
                if (runtimeHost->Start() == S_OK)
                {
                    DWORD pReturnValue; 

                    //Invoke our method through CLR host using following parameters
                    runtimeHost->ExecuteInDefaultAppDomain(L"ElmaHelper.dll", L"ElmaHelper.HelperMain", L"HelperExport", L"Helper", &pReturnValue);

                    runtimeInfo->Release();
                    metaHost->Release();
                    runtimeHost->Release();
                }
    return 0;
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(NULL, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(fnElmaHelperASM), 0, 0, NULL);
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
