using ElmaHelper.Drawing;
using System.Threading;

namespace ElmaHelper
{
    public class HelperMain
    {
        static public int HelperExport(string L)
        {
            Testing.Initialize();
            Draw.Initialize();
            LGR.Initialize();
          

            var testObj2 = new DrawingLine
            {
                name = "testName2",
                parentName = "",
                x = 1111,
                y = 222,
                x2 = 123,
                y2 = 312,
                zOrder = 311,
                visible = true,
                color = 231
            };

            

            while (true)
            {

                Draw.DrawObject(testObj2);
              
                Thread.Sleep(1000);
            }
            return 0;
        }
    }
}
