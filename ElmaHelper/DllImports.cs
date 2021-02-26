using System;
using System.Runtime.InteropServices;
using System.Linq;

namespace ElmaHelper
{
    static class DllImports
    {
        #region Memory

        public static void ModifyMemValue(int address, string value)
        {
            var byteArray = value.ToCharArray().Select(c => (byte)c).ToArray();

            ModifyMemValueEx(address, byteArray, value.Length);
        }

        public static void ModifyMemValue<T>(int address, T value) where T : struct
        {
            //Dynamic way of getting a byte array from a struct template. 
            //Reflection might be a bit slow, need to test this later.
            var byteArray = (byte[])typeof(BitConverter).GetMethod("GetBytes", new[] { typeof(T) }).Invoke(null, new object[] { value });

            ModifyMemValueEx(address, byteArray, byteArray.Length);
        }

        [DllImport("ElmaHelperASM.dll", EntryPoint = "ModifyMemValue", CallingConvention = CallingConvention.Cdecl)]
        public static extern void ModifyMemValueEx(int address, byte[] value, int size);

        [DllImport("ElmaHelperASM.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void AddJump(int destAddr, int srcAddr, int nops = 0);

        [DllImport("ElmaHelperASM.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void AddCall(int destAddr, int srcAddr, int nops = 0);

        #endregion

        #region Drawing

        [DllImport("ElmaHelperASM.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void InitDrawing();

        [DllImport("ElmaHelperASM.dll", EntryPoint = "DrawTxt", CallingConvention = CallingConvention.Cdecl)]
        public static extern void DrawText(string text, string name, string parentName, int x, int y, int zOrder, bool visible, int spaceBetweenChars);

        [DllImport("ElmaHelperASM.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void DrawLine(string name, string parentName, int x, int y, int x2, int y2, int color, int zOrder, bool visible, bool arrow = false);

        [DllImport("ElmaHelperASM.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void DrawCircle(string name, string parentName, int x, int y, int rad, int color, int zOrder, bool visible);

        [DllImport("ElmaHelperASM.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void DrawRect(string name, string parentName, int x, int y, int x2, int y2, int color, int zOrder, bool visible);

        [DllImport("ElmaHelperASM.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void RemoveDrawObject(string name);

        #endregion

        #region LGR

        [DllImport("ElmaHelperASM.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void InitLGR();

        [DllImport("ElmaHelperASM.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void LoadLGR(string name);

        #endregion
    }
}
