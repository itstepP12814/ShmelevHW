﻿namespace SampleProcess
{
   partial class Form1
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
         this.startBtn = new System.Windows.Forms.Button();
         this.stopBtn = new System.Windows.Forms.Button();
         this.MyProcess = new System.Diagnostics.Process();
         this.SuspendLayout();
         // 
         // startBtn
         // 
         this.startBtn.Location = new System.Drawing.Point(76, 49);
         this.startBtn.Name = "startBtn";
         this.startBtn.Size = new System.Drawing.Size(90, 43);
         this.startBtn.TabIndex = 0;
         this.startBtn.Text = "Старт";
         this.startBtn.UseVisualStyleBackColor = true;
         this.startBtn.Click += new System.EventHandler(this.startBtn_Click);
         // 
         // stopBtn
         // 
         this.stopBtn.Location = new System.Drawing.Point(76, 115);
         this.stopBtn.Name = "stopBtn";
         this.stopBtn.Size = new System.Drawing.Size(90, 45);
         this.stopBtn.TabIndex = 1;
         this.stopBtn.Text = "Стоп";
         this.stopBtn.UseVisualStyleBackColor = true;
         this.stopBtn.Click += new System.EventHandler(this.stopBtn_Click);
         // 
         // MyProcess
         // 
         this.MyProcess.StartInfo.Domain = "";
         this.MyProcess.StartInfo.LoadUserProfile = false;
         this.MyProcess.StartInfo.Password = null;
         this.MyProcess.StartInfo.StandardErrorEncoding = null;
         this.MyProcess.StartInfo.StandardOutputEncoding = null;
         this.MyProcess.StartInfo.UserName = "";
         this.MyProcess.SynchronizingObject = this;
         // 
         // Form1
         // 
         this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
         this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
         this.ClientSize = new System.Drawing.Size(278, 244);
         this.Controls.Add(this.stopBtn);
         this.Controls.Add(this.startBtn);
         this.Name = "Form1";
         this.Text = "Form1";
         this.ResumeLayout(false);

      }

      #endregion

      private System.Windows.Forms.Button startBtn;
      private System.Windows.Forms.Button stopBtn;
      private System.Diagnostics.Process MyProcess;
   }
}

