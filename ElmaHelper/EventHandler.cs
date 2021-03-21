namespace ElmaHelper
{
    class EventHandler
    {
        public static void AddEventHandler(FuncName type, int trigger, string[] args)
        {
            var argStr = string.Join("|", args);

            DllImports.AddEventHandler(type, trigger, argStr);
        }
    }
}
