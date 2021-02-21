
namespace ElmaHelper
{
    public class HelperMain
    {
        static public int HelperExport(string L)
        {
           
            Testing.Initialize();
            while (true)
            {
                DllImports.ModifyMemValue(0x00453B20, 0);
                System.Threading.Thread.Sleep(1000);
                DllImports.ModifyMemValue(0x00453B20, 1);
                System.Threading.Thread.Sleep(1000);

            }
            return 0;
        }


    }
}
