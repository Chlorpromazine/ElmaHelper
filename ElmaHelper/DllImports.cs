﻿using System;
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

        [DllImport("ElmaHelperASM.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void DrawPixel(int x, int y, byte color);

        [DllImport("ElmaHelperASM.dll", EntryPoint = "DrawTxt", CallingConvention = CallingConvention.Cdecl)]
        public static extern void DrawText(string text, string name, string parentName, int x, int y, int zOrder, bool visible, int spaceBetweenChars);

        [DllImport("ElmaHelperASM.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void RemoveDrawObject(string name);
        #endregion 
    }
}
