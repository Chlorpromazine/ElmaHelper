using ElmaHelper.Drawing;
using System;
using System.Runtime.InteropServices;
using System.Threading;

namespace ElmaHelper
{
    public class HelperMain
    {
        static public int HelperExport(string L)
        {
            Testing.Initialize();
          

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
           
            EventHandler.AddEventHandler(ElmaFunction.SetLGR, 0, new[] { "army" });

            EventHandler.AddEventHandler(ElmaFunction.SetAcceleration, 0, new[] { "1200" });
            while (true)
            {

                Draw.DrawObject(testObj2);
              
                Thread.Sleep(1000);
            }
            return 0;
        }
    }
}
