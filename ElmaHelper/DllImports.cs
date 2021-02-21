using System.Runtime.InteropServices;

namespace ElmaHelper
{
    static class DllImports
    {
        [DllImport("ElmaHelperASM.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void ModifyMemValue(int address, uint value);
    }
}
