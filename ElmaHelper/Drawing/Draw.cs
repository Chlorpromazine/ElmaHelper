using System;

namespace ElmaHelper.Drawing
{
    class Draw
    {
        public static void Initialize()
        {
            DllImports.InitDrawing();
        }

		public static void Pixel(int x, int y, int color)
        {
			DllImports.DrawPixel(x, y, (byte)color);
        }

        public static void DrawObject(DrawingObjects drawObj)
        {
        //    public string name;
        //public string parentName;
        //public int x;
        //public int y;
        //public int zOrder;
        //public bool visible;
        //todo: find a way to send c# objects to c++
            switch (drawObj)
            {
                case DrawingText text:
                    DllImports.DrawText(text.text, text.name, text.parentName, text.x, text.y, text.zOrder, text.visible, text.spaceBetweenChars);
                    break;

            }
            
        }
	}
}
