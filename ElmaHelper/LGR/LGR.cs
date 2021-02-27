using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace ElmaHelper
{
	class LGR
	{
		static string currentLgr { get; set; } = "default";

		public static List<string> lgrList;

		public static void GetLGRList()
        {
			var lgrs = Directory.GetFiles("Lgr").Select(x => x = Path.GetFileNameWithoutExtension(x)).ToList();

			lgrList = lgrs;
		}

		public static void LoadLGR(string name)
        {
			DllImports.LoadLGR(name);
        }
	}
}
