namespace ElmaHelper.Drawing
{
    class DrawingObjects
    {
		public string name;
		public string parentName;
		public int x;
		public int y;
		public int zOrder;
		public bool visible;
	}

	class DrawingText : DrawingObjects
	{
		public int spaceBetweenChars = -1000; //default
		public string text;

	}

	class DrawingLine : DrawingObjects
	{
		public int x2;
		public int y2;
		public double maxLength;
		public double minLength;
		public byte color;
	}

	class DrawingLineArrow : DrawingObjects
	{
		public int x2;
		public int y2;
		public double maxLength;
		public double minLength;
		public byte color;
	};

	class DrawingRect : DrawingObjects
	{
		public int x2;
		public int y2;
		public byte color;
	};

	class DrawingCircle : DrawingObjects
	{
		public int rad;
		public byte color;
	};



}
