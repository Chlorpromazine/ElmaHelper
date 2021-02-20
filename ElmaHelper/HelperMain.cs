using System;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace ElmaHelper
{
    public class HelperMain
    {
        static public int HelperExport(string L)
        {
           
            Testing.Initialize();
            while (true)
            {
                testing(0);
                System.Threading.Thread.Sleep(1000);
                testing(1);
                System.Threading.Thread.Sleep(1000);

            }
            return 0;
        }


        [DllImport("ElmaHelperASM.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void testing(uint testVar);
    }
}
