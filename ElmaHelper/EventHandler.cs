using System.Collections.Generic;

namespace ElmaHelper
{
    class EventHandler
    {
        public static void AddEventHandler(int type, int trigger, string[] args)
        {
            var argStr = string.Join("|", args);

            DllImports.AddEventHandler(type, trigger, argStr);
        }
    }
}
