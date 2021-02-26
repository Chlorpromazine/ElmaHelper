
namespace ElmaHelper
{
    partial class ElmaHelperTester
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.LgrComboBox = new System.Windows.Forms.ComboBox();
            this.LoadLgrBtn = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // LgrComboBox
            // 
            this.LgrComboBox.FormattingEnabled = true;
            this.LgrComboBox.Location = new System.Drawing.Point(33, 44);
            this.LgrComboBox.Name = "LgrComboBox";
            this.LgrComboBox.Size = new System.Drawing.Size(121, 21);
            this.LgrComboBox.TabIndex = 3;
            // 
            // LoadLgrBtn
            // 
            this.LoadLgrBtn.Location = new System.Drawing.Point(192, 44);
            this.LoadLgrBtn.Name = "LoadLgrBtn";
            this.LoadLgrBtn.Size = new System.Drawing.Size(75, 23);
            this.LoadLgrBtn.TabIndex = 4;
            this.LoadLgrBtn.Text = "Load LGR";
            this.LoadLgrBtn.UseVisualStyleBackColor = true;
            this.LoadLgrBtn.Click += new System.EventHandler(this.LoadLgrBtn_Click);
            // 
            // ElmaHelperTester
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(305, 108);
            this.Controls.Add(this.LoadLgrBtn);
            this.Controls.Add(this.LgrComboBox);
            this.Name = "ElmaHelperTester";
            this.Text = "ElmaHelperTester";
            this.Load += new System.EventHandler(this.ElmaHelperTester_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ComboBox LgrComboBox;
        private System.Windows.Forms.Button LoadLgrBtn;
    }
}