using System;

namespace ElmaHelper.Drawing
{
    class Draw
    {
        public static void DrawObject(DrawingObjects drawObj)
        {
            //todo: find a way to send c# objects to c++
            switch (drawObj)
            {
                case DrawingText text:
                    DllImports.DrawText(text.text, text.name, text.parentName, text.x, text.y, text.zOrder, text.visible, text.spaceBetweenChars);
                    break;
                case DrawingLine line:
                    DllImports.DrawLine(line.name, line.parentName, line.x, line.y, line.x2, line.y2, line.color, line.zOrder, line.visible);
                    break;
                case DrawingCircle circle:
                    DllImports.DrawCircle(circle.name, circle.parentName, circle.x, circle.y, circle.rad, circle.color, circle.zOrder, circle.visible);
                    break;
                case DrawingRect rect:
                    DllImports.DrawRect(rect.name, rect.parentName, rect.x, rect.y, rect.x2, rect.y2, rect.color, rect.zOrder, rect.visible);
                    break;
                case DrawingArrow line:
                    DllImports.DrawLine(line.name, line.parentName, line.x, line.y, line.x2, line.y2, line.color, line.zOrder, line.visible, true);
                    break;
            }
        }

        public static void RemoveDrawObject(string name)
        {
            DllImports.RemoveDrawObject(name);
        }

        public static void RemoveDrawObject(DrawingObjects obj)
        {
            DllImports.RemoveDrawObject(obj.name);
        }

    }
}
