// ElmaHelperASM.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "ElmaHelperASM.h"
#include <iostream>
#include "Memory.h"
#include <metahost.h>
#pragma comment(lib, "mscoree.lib")

#define dllexp __declspec(dllexport)

extern "C"
{
    using namespace std;
    DWORD dllexp fnElmaHelperASM()
    {
        cout << "ok" << endl;
        ICLRMetaHost* metaHost = NULL; //Declare our CLR Meta Host value as a NULL
        ICLRRuntimeInfo* runtimeInfo = NULL; //Declare our CLR Runtime Info as a Null
        ICLRRuntimeHost* runtimeHost = NULL; //Delcare our CLR HOST as a NULL

        if (CLRCreateInstance(CLSID_CLRMetaHost, IID_ICLRMetaHost, (LPVOID*)&metaHost) == S_OK) //If Creating CLR Instance with follow parameters is successful
            if (metaHost->GetRuntime(L"v4.0.30319", IID_ICLRRuntimeInfo, (LPVOID*)&runtimeInfo) == S_OK) //If getting Runtime version is successful
                if (runtimeInfo->GetInterface(CLSID_CLRRuntimeHost, IID_ICLRRuntimeHost, (LPVOID*)&runtimeHost) == S_OK) //If getting the interface with the follow parameters is successful
                    if (runtimeHost->Start() == S_OK) //Start the CLR (If it is successful)
                    {
                        DWORD pReturnValue; //Declare our return value as a DWORD

                        //Invoke our method through CLR host using following parameters
                        runtimeHost->ExecuteInDefaultAppDomain(L"D:\\elma test\\ElmaHelper.dll", L"ElmaHelper.HelperMain", L"HelperExport", L"Helper", &pReturnValue);

                        //OPTIONAL: You can keep the CLR Opened depending on your needs
                        runtimeInfo->Release();
                        metaHost->Release();
                        runtimeHost->Release();
                    }
        return 0;
    }


	
	void dllexp testing(unsigned int testVar)
	{
		cout << "ok" << endl;
		//0x00453B20
		MemPatchInt((BYTE*)0x00453B20, &testVar);
	}

}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		//RedirectIOToConsole(); //debug

		CreateThread(NULL, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(fnElmaHelperASM), 0, 0, NULL);

		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		//run = false;
		break;
	}
	return TRUE;
}
