namespace ElmaHelper
{
    public struct FuncName
    {
        public static implicit operator FuncName(string value)
        {
            return new FuncName(value);
        }

        public static implicit operator string(FuncName value)
        {
            return value.Name;
        }

        FuncName(string name)
        {
            Name = name;
        }

        private string Name;
    }

    public class ElmaFunction
    {
        public static readonly FuncName SetLGR = "SetLGR";
        public static readonly FuncName SetAcceleration = "SetAcceleration";
    }

    
}