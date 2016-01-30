namespace MusicInfoXMLReader
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
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.файлToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.loadAlbumsBtn = new System.Windows.Forms.ToolStripMenuItem();
            this.loadProducersBtn = new System.Windows.Forms.ToolStripMenuItem();
            this.filterMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.filter1 = new System.Windows.Forms.ToolStripMenuItem();
            this.filter2 = new System.Windows.Forms.ToolStripMenuItem();
            this.filter3 = new System.Windows.Forms.ToolStripMenuItem();
            this.filter4 = new System.Windows.Forms.ToolStripMenuItem();
            this.filter5 = new System.Windows.Forms.ToolStripMenuItem();
            this.filter6 = new System.Windows.Forms.ToolStripMenuItem();
            this.filter7 = new System.Windows.Forms.ToolStripMenuItem();
            this.filter8 = new System.Windows.Forms.ToolStripMenuItem();
            this.filter9 = new System.Windows.Forms.ToolStripMenuItem();
            this.filter10 = new System.Windows.Forms.ToolStripMenuItem();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(12, 49);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.Size = new System.Drawing.Size(1334, 567);
            this.dataGridView1.TabIndex = 0;
            // 
            // button1
            // 
            this.button1.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.button1.Location = new System.Drawing.Point(45, 641);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(141, 38);
            this.button1.TabIndex = 1;
            this.button1.Text = "Альбомы";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.button2.Location = new System.Drawing.Point(229, 641);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(148, 38);
            this.button2.TabIndex = 2;
            this.button2.Text = "Продюсеры";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.файлToolStripMenuItem,
            this.filterMenu});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1358, 33);
            this.menuStrip1.TabIndex = 3;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // файлToolStripMenuItem
            // 
            this.файлToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.loadAlbumsBtn,
            this.loadProducersBtn});
            this.файлToolStripMenuItem.Name = "файлToolStripMenuItem";
            this.файлToolStripMenuItem.Size = new System.Drawing.Size(104, 29);
            this.файлToolStripMenuItem.Text = "Загрузить";
            // 
            // loadAlbumsBtn
            // 
            this.loadAlbumsBtn.Name = "loadAlbumsBtn";
            this.loadAlbumsBtn.Size = new System.Drawing.Size(385, 30);
            this.loadAlbumsBtn.Text = "Загрузить альбомы из файла...";
            this.loadAlbumsBtn.Click += new System.EventHandler(this.loadAlbumsBtn_Click);
            // 
            // loadProducersBtn
            // 
            this.loadProducersBtn.Name = "loadProducersBtn";
            this.loadProducersBtn.Size = new System.Drawing.Size(385, 30);
            this.loadProducersBtn.Text = "Загрузить продюссеров из файла...";
            this.loadProducersBtn.Click += new System.EventHandler(this.loadProducersBtn_Click);
            // 
            // filterMenu
            // 
            this.filterMenu.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.filter1,
            this.filter2,
            this.filter3,
            this.filter4,
            this.filter5,
            this.filter6,
            this.filter7,
            this.filter8,
            this.filter9,
            this.filter10});
            this.filterMenu.Name = "filterMenu";
            this.filterMenu.Size = new System.Drawing.Size(149, 29);
            this.filterMenu.Text = "Отфильтровать";
            // 
            // filter1
            // 
            this.filter1.Name = "filter1";
            this.filter1.Size = new System.Drawing.Size(1004, 30);
            this.filter1.Text = "1. Список всех артистов, который выпустили свои альбомы после распада СССР";
            this.filter1.Click += new System.EventHandler(this.filter1_Click);
            // 
            // filter2
            // 
            this.filter2.Name = "filter2";
            this.filter2.Size = new System.Drawing.Size(1004, 30);
            this.filter2.Text = "2. Список стран";
            this.filter2.Click += new System.EventHandler(this.filter2_Click);
            // 
            // filter3
            // 
            this.filter3.Name = "filter3";
            this.filter3.Size = new System.Drawing.Size(1004, 30);
            this.filter3.Text = "3. Список наименований альбомов, выпущенных в США, упорядоченных по году выпуска";
            this.filter3.Click += new System.EventHandler(this.filter3_Click);
            // 
            // filter4
            // 
            this.filter4.Name = "filter4";
            this.filter4.Size = new System.Drawing.Size(1004, 30);
            this.filter4.Text = "4. Суммарная стоимость альбомов за страну";
            this.filter4.Click += new System.EventHandler(this.filter4_Click);
            // 
            // filter5
            // 
            this.filter5.Name = "filter5";
            this.filter5.Size = new System.Drawing.Size(1004, 30);
            this.filter5.Text = "5. Список компаний и количество альбомов за год, года упорядочены по возрастанию";
            this.filter5.Click += new System.EventHandler(this.filter5_Click);
            // 
            // filter6
            // 
            this.filter6.Name = "filter6";
            this.filter6.Size = new System.Drawing.Size(1004, 30);
            this.filter6.Text = "6. Наименование альбома и продюсера, получившего самое большое вознаграждение за " +
    "вклад в развитие";
            this.filter6.Click += new System.EventHandler(this.filter6_Click);
            // 
            // filter7
            // 
            this.filter7.Name = "filter7";
            this.filter7.Size = new System.Drawing.Size(1004, 30);
            this.filter7.Text = "7. Количество альбомов каждого продюсера в период  между годами выхода альбома 19" +
    "88 – 1990 гг";
            this.filter7.Click += new System.EventHandler(this.filter7_Click);
            // 
            // filter8
            // 
            this.filter8.Name = "filter8";
            this.filter8.Size = new System.Drawing.Size(1004, 30);
            this.filter8.Text = "8. Фамилию продюсера получившего вознаграждение последним";
            this.filter8.Click += new System.EventHandler(this.filter8_Click);
            // 
            // filter9
            // 
            this.filter9.Name = "filter9";
            this.filter9.Size = new System.Drawing.Size(1004, 30);
            this.filter9.Text = "9. Информацию о самом дешевом альбоме (название альбома, исполнителя и продюсера)" +
    "";
            this.filter9.Click += new System.EventHandler(this.filter9_Click);
            // 
            // filter10
            // 
            this.filter10.Name = "filter10";
            this.filter10.Size = new System.Drawing.Size(1004, 30);
            this.filter10.Text = "10. Полная информация об альбомах, по году выхода альбома, стоимости  альбома, на" +
    "именованию альбома";
            this.filter10.Click += new System.EventHandler(this.filter10_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1358, 691);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "MainForm";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem файлToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem filterMenu;
        private System.Windows.Forms.ToolStripMenuItem filter1;
        private System.Windows.Forms.ToolStripMenuItem filter2;
        private System.Windows.Forms.ToolStripMenuItem filter3;
        private System.Windows.Forms.ToolStripMenuItem filter4;
        private System.Windows.Forms.ToolStripMenuItem filter5;
        private System.Windows.Forms.ToolStripMenuItem filter6;
        private System.Windows.Forms.ToolStripMenuItem filter7;
        private System.Windows.Forms.ToolStripMenuItem filter8;
        private System.Windows.Forms.ToolStripMenuItem filter9;
        private System.Windows.Forms.ToolStripMenuItem filter10;
        private System.Windows.Forms.ToolStripMenuItem loadAlbumsBtn;
        private System.Windows.Forms.ToolStripMenuItem loadProducersBtn;
    }
}

