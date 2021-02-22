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
                text = "test",
                name = "testName",
                parentName = "",
                x = 50,
                y = 50,
                zOrder = 100,
                visible = true
            };
            Draw.DrawObject(testObj);

            return 0;
        }
    }
}
