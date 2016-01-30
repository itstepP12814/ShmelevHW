namespace MainProcessApp
{
   partial class MainProcessWindow
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
         this.listBox1 = new System.Windows.Forms.ListBox();
         this.label1 = new System.Windows.Forms.Label();
         this.label2 = new System.Windows.Forms.Label();
         this.listBox2 = new System.Windows.Forms.ListBox();
         this.startBtn = new System.Windows.Forms.Button();
         this.stopBtn = new System.Windows.Forms.Button();
         this.closeWindowBtn = new System.Windows.Forms.Button();
         this.refreshBtn = new System.Windows.Forms.Button();
         this.runCalcBtn = new System.Windows.Forms.Button();
         this.SuspendLayout();
         // 
         // listBox1
         // 
         this.listBox1.FormattingEnabled = true;
         this.listBox1.ItemHeight = 20;
         this.listBox1.Location = new System.Drawing.Point(68, 112);
         this.listBox1.Name = "listBox1";
         this.listBox1.Size = new System.Drawing.Size(259, 304);
         this.listBox1.TabIndex = 0;
         // 
         // label1
         // 
         this.label1.AutoSize = true;
         this.label1.Location = new System.Drawing.Point(68, 51);
         this.label1.Name = "label1";
         this.label1.Size = new System.Drawing.Size(157, 20);
         this.label1.TabIndex = 1;
         this.label1.Text = "Available Assemblies";
         // 
         // label2
         // 
         this.label2.AutoSize = true;
         this.label2.Location = new System.Drawing.Point(455, 51);
         this.label2.Name = "label2";
         this.label2.Size = new System.Drawing.Size(147, 20);
         this.label2.TabIndex = 3;
         this.label2.Text = "Started Assemblies";
         // 
         // listBox2
         // 
         this.listBox2.FormattingEnabled = true;
         this.listBox2.ItemHeight = 20;
         this.listBox2.Location = new System.Drawing.Point(455, 112);
         this.listBox2.Name = "listBox2";
         this.listBox2.Size = new System.Drawing.Size(263, 304);
         this.listBox2.TabIndex = 2;
         // 
         // startBtn
         // 
         this.startBtn.Location = new System.Drawing.Point(150, 448);
         this.startBtn.Name = "startBtn";
         this.startBtn.Size = new System.Drawing.Size(75, 37);
         this.startBtn.TabIndex = 4;
         this.startBtn.Text = "start";
         this.startBtn.UseVisualStyleBackColor = true;
         // 
         // stopBtn
         // 
         this.stopBtn.Location = new System.Drawing.Point(231, 448);
         this.stopBtn.Name = "stopBtn";
         this.stopBtn.Size = new System.Drawing.Size(75, 37);
         this.stopBtn.TabIndex = 5;
         this.stopBtn.Text = "Stop";
         this.stopBtn.UseVisualStyleBackColor = true;
         // 
         // closeWindowBtn
         // 
         this.closeWindowBtn.Location = new System.Drawing.Point(312, 448);
         this.closeWindowBtn.Name = "closeWindowBtn";
         this.closeWindowBtn.Size = new System.Drawing.Size(128, 37);
         this.closeWindowBtn.TabIndex = 6;
         this.closeWindowBtn.Text = "Close window";
         this.closeWindowBtn.UseVisualStyleBackColor = true;
         // 
         // refreshBtn
         // 
         this.refreshBtn.Location = new System.Drawing.Point(446, 448);
         this.refreshBtn.Name = "refreshBtn";
         this.refreshBtn.Size = new System.Drawing.Size(75, 37);
         this.refreshBtn.TabIndex = 7;
         this.refreshBtn.Text = "Refresh";
         this.refreshBtn.UseVisualStyleBackColor = true;
         // 
         // runCalcBtn
         // 
         this.runCalcBtn.Location = new System.Drawing.Point(527, 448);
         this.runCalcBtn.Name = "runCalcBtn";
         this.runCalcBtn.Size = new System.Drawing.Size(101, 37);
         this.runCalcBtn.TabIndex = 8;
         this.runCalcBtn.Text = "Run calc";
         this.runCalcBtn.UseVisualStyleBackColor = true;
         // 
         // Form1
         // 
         this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
         this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
         this.ClientSize = new System.Drawing.Size(776, 555);
         this.Controls.Add(this.runCalcBtn);
         this.Controls.Add(this.refreshBtn);
         this.Controls.Add(this.closeWindowBtn);
         this.Controls.Add(this.stopBtn);
         this.Controls.Add(this.startBtn);
         this.Controls.Add(this.label2);
         this.Controls.Add(this.listBox2);
         this.Controls.Add(this.label1);
         this.Controls.Add(this.listBox1);
         this.Name = "Form1";
         this.Text = "Form1";
         this.ResumeLayout(false);
         this.PerformLayout();

      }

      #endregion

      private System.Windows.Forms.ListBox listBox1;
      private System.Windows.Forms.Label label1;
      private System.Windows.Forms.Label label2;
      private System.Windows.Forms.ListBox listBox2;
      private System.Windows.Forms.Button startBtn;
      private System.Windows.Forms.Button stopBtn;
      private System.Windows.Forms.Button closeWindowBtn;
      private System.Windows.Forms.Button refreshBtn;
      private System.Windows.Forms.Button runCalcBtn;
   }
}

