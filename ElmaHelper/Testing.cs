using System.Threading.Tasks;
using System.Windows.Forms;

namespace ElmaHelper
{
    public static class Testing
    {
        //Initializes the testing form and does the even loop.
        public static void Initialize()
        {
            Task.Run(() => 
            {
                var testerForm = new ElmaHelperTester();
                testerForm.Show();

                while (true)
                {
                    Application.DoEvents();
                    System.Threading.Thread.Sleep(1);
                }
            });

        }
    }
}
