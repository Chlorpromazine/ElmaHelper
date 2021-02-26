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

        private void ElmaHelperTester_Load(object sender, EventArgs e)
        {
            LGR.GetLGRList();
            LgrComboBox.DataSource = LGR.lgrList;
        }

        private void LoadLgrBtn_Click(object sender, EventArgs e)
        {
            LGR.LoadLGR(LgrComboBox.SelectedItem.ToString());
        }
    }
}
