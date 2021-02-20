using System;
using System.Windows.Forms;
using ElmaHelper;

namespace ElmaHelperTester
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            HelperMain.testing();
        }
    }
}
