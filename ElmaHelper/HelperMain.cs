using System.Runtime.InteropServices;

namespace ElmaHelper
{
    public class HelperMain
    {
        [DllExport("HelperExport", CallingConvention.Cdecl)]
        static public void HelperExport()
        {
            testing();
        }


        [DllImport("ElmaHelperASM.dll")]
        public static extern void testing();
    }
}
