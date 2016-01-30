namespace EmailClient
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
            this.components = new System.ComponentModel.Container();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.RecipientTreeView = new System.Windows.Forms.TreeView();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.addCategoryMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.removeCategoryMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.button3 = new System.Windows.Forms.Button();
            this.contextMenuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(12, 476);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(136, 29);
            this.button1.TabIndex = 1;
            this.button1.Text = "Добавить категорию";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(167, 476);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(136, 29);
            this.button2.TabIndex = 2;
            this.button2.Text = "Удалить";
            this.button2.UseVisualStyleBackColor = true;
            // 
            // RecipientTreeView
            // 
            this.RecipientTreeView.ContextMenuStrip = this.contextMenuStrip1;
            this.RecipientTreeView.Location = new System.Drawing.Point(13, 12);
            this.RecipientTreeView.Name = "RecipientTreeView";
            this.RecipientTreeView.Size = new System.Drawing.Size(334, 431);
            this.RecipientTreeView.TabIndex = 3;
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.contextMenuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.addCategoryMenuItem,
            this.removeCategoryMenuItem});
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(300, 64);
            // 
            // addCategoryMenuItem
            // 
            this.addCategoryMenuItem.Name = "addCategoryMenuItem";
            this.addCategoryMenuItem.Size = new System.Drawing.Size(299, 30);
            this.addCategoryMenuItem.Text = "Добавить подкатегорию";
            this.addCategoryMenuItem.Click += new System.EventHandler(this.addCategoryMenuItem_Click);
            // 
            // removeCategoryMenuItem
            // 
            this.removeCategoryMenuItem.Name = "removeCategoryMenuItem";
            this.removeCategoryMenuItem.Size = new System.Drawing.Size(299, 30);
            this.removeCategoryMenuItem.Text = "Удалить подкатегорию";
            this.removeCategoryMenuItem.Click += new System.EventHandler(this.removeCategoryMenuItem_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(357, 244);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(136, 29);
            this.button3.TabIndex = 4;
            this.button3.Text = "Удалить";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(850, 517);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.RecipientTreeView);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Name = "MainForm";
            this.Text = "Email Client";
            this.contextMenuStrip1.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.TreeView RecipientTreeView;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem addCategoryMenuItem;
        private System.Windows.Forms.ToolStripMenuItem removeCategoryMenuItem;
        private System.Windows.Forms.Button button3;
    }
}

