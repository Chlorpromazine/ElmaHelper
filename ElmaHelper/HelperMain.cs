using ElmaHelper.Drawing;

namespace ElmaHelper
{
    public class HelperMain
    {
        static public int HelperExport(string L)
        {
            Testing.Initialize();
            Draw.Initialize();

           
            var testObj = new DrawingText
            {
                text = "test1231",
                name = "testName",
                parentName = "",
                x = 123,
                y = 123,
                zOrder = 1,
                visible = true
            };
            Draw.DrawObject(testObj);

            var testObj2 = new DrawingText
            {
                text = "abcdef",
                name = "testName2",
                parentName = "",
                x = 111,
                y = 222,
                zOrder = 2,
                visible = true
            };
            Draw.DrawObject(testObj2);

            return 0;
        }
    }
}
