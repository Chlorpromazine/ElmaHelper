using System;
using System.Windows.Forms;

namespace ElmaHelper
{
    public partial class ElmaHelperTester : Form
    {
        public ElmaHelperTester()
        {
            InitializeComponent(); 
            SetStyle(ControlStyles.Selectable, false);
        }

        private void Testing_Click(object sender, EventArgs e)
        {
            HelperMain.testing(0);
        }

        private void TestingRight_Click(object sender, EventArgs e)
        {
            HelperMain.testing(1);
        }
    }
}
