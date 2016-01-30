namespace MdiExample
{
    partial class MainForm
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
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.файлToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.инструментыToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.ColorsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.BrushesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.WorkAreaToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.окнаToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.справкаToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.режим1ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.режим2ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.файлToolStripMenuItem,
            this.инструментыToolStripMenuItem,
            this.окнаToolStripMenuItem,
            this.справкаToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.MdiWindowListItem = this.окнаToolStripMenuItem;
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(900, 33);
            this.menuStrip1.TabIndex = 1;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // файлToolStripMenuItem
            // 
            this.файлToolStripMenuItem.Name = "файлToolStripMenuItem";
            this.файлToolStripMenuItem.Size = new System.Drawing.Size(65, 29);
            this.файлToolStripMenuItem.Text = "Файл";
            // 
            // инструментыToolStripMenuItem
            // 
            this.инструментыToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.ColorsToolStripMenuItem,
            this.BrushesToolStripMenuItem,
            this.WorkAreaToolStripMenuItem});
            this.инструментыToolStripMenuItem.Name = "инструментыToolStripMenuItem";
            this.инструментыToolStripMenuItem.Size = new System.Drawing.Size(134, 29);
            this.инструментыToolStripMenuItem.Text = "Инструменты";
            // 
            // ColorsToolStripMenuItem
            // 
            this.ColorsToolStripMenuItem.Name = "ColorsToolStripMenuItem";
            this.ColorsToolStripMenuItem.Size = new System.Drawing.Size(233, 30);
            this.ColorsToolStripMenuItem.Text = "Цвета";
            this.ColorsToolStripMenuItem.Click += new System.EventHandler(this.ColorsToolStripMenuItem_Click);
            // 
            // BrushesToolStripMenuItem
            // 
            this.BrushesToolStripMenuItem.Name = "BrushesToolStripMenuItem";
            this.BrushesToolStripMenuItem.Size = new System.Drawing.Size(233, 30);
            this.BrushesToolStripMenuItem.Text = "Кисти";
            // 
            // WorkAreaToolStripMenuItem
            // 
            this.WorkAreaToolStripMenuItem.Name = "WorkAreaToolStripMenuItem";
            this.WorkAreaToolStripMenuItem.Size = new System.Drawing.Size(233, 30);
            this.WorkAreaToolStripMenuItem.Text = "Рабочая область";
            // 
            // окнаToolStripMenuItem
            // 
            this.окнаToolStripMenuItem.Name = "окнаToolStripMenuItem";
            this.окнаToolStripMenuItem.Size = new System.Drawing.Size(66, 29);
            this.окнаToolStripMenuItem.Text = "Окна";
            // 
            // справкаToolStripMenuItem
            // 
            this.справкаToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.режим1ToolStripMenuItem,
            this.режим2ToolStripMenuItem});
            this.справкаToolStripMenuItem.Name = "справкаToolStripMenuItem";
            this.справкаToolStripMenuItem.Size = new System.Drawing.Size(175, 29);
            this.справкаToolStripMenuItem.Text = "Режим просмотра";
            // 
            // режим1ToolStripMenuItem
            // 
            this.режим1ToolStripMenuItem.Name = "режим1ToolStripMenuItem";
            this.режим1ToolStripMenuItem.Size = new System.Drawing.Size(211, 30);
            this.режим1ToolStripMenuItem.Text = "Режим 1";
            this.режим1ToolStripMenuItem.Click += new System.EventHandler(this.режим1ToolStripMenuItem_Click);
            // 
            // режим2ToolStripMenuItem
            // 
            this.режим2ToolStripMenuItem.Name = "режим2ToolStripMenuItem";
            this.режим2ToolStripMenuItem.Size = new System.Drawing.Size(211, 30);
            this.режим2ToolStripMenuItem.Text = "Режим 2";
            this.режим2ToolStripMenuItem.Click += new System.EventHandler(this.режим2ToolStripMenuItem_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(900, 537);
            this.Controls.Add(this.menuStrip1);
            this.IsMdiContainer = true;
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "MainForm";
            this.Text = "Form1";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem файлToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem инструментыToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem ColorsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem BrushesToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem WorkAreaToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem окнаToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem справкаToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem режим1ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem режим2ToolStripMenuItem;
    }
}

