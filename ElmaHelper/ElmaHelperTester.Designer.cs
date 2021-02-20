
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
            this.TestingLeft = new System.Windows.Forms.Button();
            this.TestingRight = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // TestingLeft
            // 
            this.TestingLeft.Location = new System.Drawing.Point(273, 240);
            this.TestingLeft.Name = "TestingLeft";
            this.TestingLeft.Size = new System.Drawing.Size(75, 23);
            this.TestingLeft.TabIndex = 0;
            this.TestingLeft.Text = "turn left";
            this.TestingLeft.UseVisualStyleBackColor = true;
            this.TestingLeft.Click += new System.EventHandler(this.Testing_Click);
            // 
            // TestingRight
            // 
            this.TestingRight.Location = new System.Drawing.Point(440, 240);
            this.TestingRight.Name = "TestingRight";
            this.TestingRight.Size = new System.Drawing.Size(75, 23);
            this.TestingRight.TabIndex = 1;
            this.TestingRight.Text = "turn right";
            this.TestingRight.UseVisualStyleBackColor = true;
            this.TestingRight.Click += new System.EventHandler(this.TestingRight_Click);
            // 
            // ElmaHelperTester
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.TestingRight);
            this.Controls.Add(this.TestingLeft);
            this.Name = "ElmaHelperTester";
            this.Text = "ElmaHelperTester";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button TestingLeft;
        private System.Windows.Forms.Button TestingRight;
    }
}