namespace BankMap
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
            this.gMapControl = new GMap.NET.WindowsForms.GMapControl();
            this.addOnlyContextMenu = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.addBankBranchBtn = new System.Windows.Forms.ToolStripMenuItem();
            this.removeAddContextMenu = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.addBankBranchBtn2 = new System.Windows.Forms.ToolStripMenuItem();
            this.removeBankBranchBtn = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.файлToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.addServiceName = new System.Windows.Forms.ToolStripMenuItem();
            this.addNewBankBtn = new System.Windows.Forms.ToolStripMenuItem();
            this.label1 = new System.Windows.Forms.Label();
            this.comboBoxCur = new System.Windows.Forms.ComboBox();
            this.bestSellBtn = new System.Windows.Forms.Button();
            this.showAllBtn = new System.Windows.Forms.Button();
            this.bestBuyBtn = new System.Windows.Forms.Button();
            this.nearestBranchBtn = new System.Windows.Forms.Button();
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.toolStripAddBank = new System.Windows.Forms.ToolStripButton();
            this.toolStripAddService = new System.Windows.Forms.ToolStripButton();
            this.toolStripRefreshMap = new System.Windows.Forms.ToolStripButton();
            this.toolStripRefreshRates = new System.Windows.Forms.ToolStripButton();
            this.toolStripZoomIn = new System.Windows.Forms.ToolStripButton();
            this.toolStripZoomOut = new System.Windows.Forms.ToolStripButton();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.filterMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.bankFilterMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.serviceFilterMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.addOnlyContextMenu.SuspendLayout();
            this.removeAddContextMenu.SuspendLayout();
            this.menuStrip1.SuspendLayout();
            this.toolStrip1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // gMapControl
            // 
            this.gMapControl.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.gMapControl.Bearing = 0F;
            this.gMapControl.CanDragMap = true;
            this.gMapControl.EmptyTileColor = System.Drawing.Color.Navy;
            this.gMapControl.GrayScaleMode = false;
            this.gMapControl.HelperLineOption = GMap.NET.WindowsForms.HelperLineOptions.DontShow;
            this.gMapControl.LevelsKeepInMemmory = 5;
            this.gMapControl.Location = new System.Drawing.Point(303, 61);
            this.gMapControl.MarkersEnabled = true;
            this.gMapControl.MaxZoom = 2;
            this.gMapControl.MinZoom = 2;
            this.gMapControl.MouseWheelZoomType = GMap.NET.MouseWheelZoomType.MousePositionAndCenter;
            this.gMapControl.Name = "gMapControl";
            this.gMapControl.NegativeMode = false;
            this.gMapControl.PolygonsEnabled = true;
            this.gMapControl.RetryLoadTile = 0;
            this.gMapControl.RoutesEnabled = true;
            this.gMapControl.ScaleMode = GMap.NET.WindowsForms.ScaleModes.Integer;
            this.gMapControl.SelectedAreaFillColor = System.Drawing.Color.FromArgb(((int)(((byte)(33)))), ((int)(((byte)(65)))), ((int)(((byte)(105)))), ((int)(((byte)(225)))));
            this.gMapControl.ShowTileGridLines = false;
            this.gMapControl.Size = new System.Drawing.Size(772, 542);
            this.gMapControl.TabIndex = 0;
            this.gMapControl.Zoom = 0D;
            this.gMapControl.OnMarkerClick += new GMap.NET.WindowsForms.MarkerClick(this.gMapControl_OnMarkerClick);
            this.gMapControl.MouseClick += new System.Windows.Forms.MouseEventHandler(this.gMapControl_MouseClick);
            // 
            // addOnlyContextMenu
            // 
            this.addOnlyContextMenu.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.addOnlyContextMenu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.addBankBranchBtn});
            this.addOnlyContextMenu.Name = "addOnlyContextMenu";
            this.addOnlyContextMenu.Size = new System.Drawing.Size(265, 34);
            // 
            // addBankBranchBtn
            // 
            this.addBankBranchBtn.Name = "addBankBranchBtn";
            this.addBankBranchBtn.Size = new System.Drawing.Size(264, 30);
            this.addBankBranchBtn.Text = "Добавить отделение";
            // 
            // removeAddContextMenu
            // 
            this.removeAddContextMenu.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.removeAddContextMenu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.addBankBranchBtn2,
            this.removeBankBranchBtn});
            this.removeAddContextMenu.Name = "addOnlyContextMenu";
            this.removeAddContextMenu.Size = new System.Drawing.Size(265, 64);
            // 
            // addBankBranchBtn2
            // 
            this.addBankBranchBtn2.Name = "addBankBranchBtn2";
            this.addBankBranchBtn2.Size = new System.Drawing.Size(264, 30);
            this.addBankBranchBtn2.Text = "Добавить отделение";
            // 
            // removeBankBranchBtn
            // 
            this.removeBankBranchBtn.Name = "removeBankBranchBtn";
            this.removeBankBranchBtn.Size = new System.Drawing.Size(264, 30);
            this.removeBankBranchBtn.Text = "Удалить отделение";
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.файлToolStripMenuItem,
            this.filterMenu});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1087, 33);
            this.menuStrip1.TabIndex = 2;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // файлToolStripMenuItem
            // 
            this.файлToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.addServiceName,
            this.addNewBankBtn});
            this.файлToolStripMenuItem.Name = "файлToolStripMenuItem";
            this.файлToolStripMenuItem.Size = new System.Drawing.Size(102, 29);
            this.файлToolStripMenuItem.Text = "Добавить";
            // 
            // addServiceName
            // 
            this.addServiceName.Name = "addServiceName";
            this.addServiceName.Size = new System.Drawing.Size(346, 30);
            this.addServiceName.Text = "Добавить название вида услуг";
            this.addServiceName.Click += new System.EventHandler(this.addServiceName_Click);
            // 
            // addNewBankBtn
            // 
            this.addNewBankBtn.Name = "addNewBankBtn";
            this.addNewBankBtn.Size = new System.Drawing.Size(346, 30);
            this.addNewBankBtn.Text = "Добавить название банка";
            this.addNewBankBtn.Click += new System.EventHandler(this.addNewBankBtn_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(25, 134);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(149, 20);
            this.label1.TabIndex = 3;
            this.label1.Text = "Выберите валюту:";
            // 
            // comboBoxCur
            // 
            this.comboBoxCur.FormattingEnabled = true;
            this.comboBoxCur.Location = new System.Drawing.Point(29, 158);
            this.comboBoxCur.Name = "comboBoxCur";
            this.comboBoxCur.Size = new System.Drawing.Size(103, 28);
            this.comboBoxCur.TabIndex = 4;
            // 
            // bestSellBtn
            // 
            this.bestSellBtn.Location = new System.Drawing.Point(29, 204);
            this.bestSellBtn.Name = "bestSellBtn";
            this.bestSellBtn.Size = new System.Drawing.Size(233, 33);
            this.bestSellBtn.TabIndex = 5;
            this.bestSellBtn.Text = "Лучший курс (продажа)";
            this.bestSellBtn.UseVisualStyleBackColor = true;
            this.bestSellBtn.Click += new System.EventHandler(this.bestSellBtn_Click);
            // 
            // showAllBtn
            // 
            this.showAllBtn.Location = new System.Drawing.Point(29, 91);
            this.showAllBtn.Name = "showAllBtn";
            this.showAllBtn.Size = new System.Drawing.Size(233, 33);
            this.showAllBtn.TabIndex = 6;
            this.showAllBtn.Text = "Показать все отделения";
            this.showAllBtn.UseVisualStyleBackColor = true;
            this.showAllBtn.Click += new System.EventHandler(this.showAllBtn_Click);
            // 
            // bestBuyBtn
            // 
            this.bestBuyBtn.Location = new System.Drawing.Point(29, 243);
            this.bestBuyBtn.Name = "bestBuyBtn";
            this.bestBuyBtn.Size = new System.Drawing.Size(233, 33);
            this.bestBuyBtn.TabIndex = 7;
            this.bestBuyBtn.Text = "Лучший курс (покупка)";
            this.bestBuyBtn.UseVisualStyleBackColor = true;
            this.bestBuyBtn.Click += new System.EventHandler(this.bestBuyBtn_Click);
            // 
            // nearestBranchBtn
            // 
            this.nearestBranchBtn.Location = new System.Drawing.Point(29, 322);
            this.nearestBranchBtn.Name = "nearestBranchBtn";
            this.nearestBranchBtn.Size = new System.Drawing.Size(233, 61);
            this.nearestBranchBtn.TabIndex = 8;
            this.nearestBranchBtn.Text = "Самое близкое к маркеру отделение";
            this.nearestBranchBtn.UseVisualStyleBackColor = true;
            this.nearestBranchBtn.Click += new System.EventHandler(this.nearestBranchBtn_Click);
            // 
            // toolStrip1
            // 
            this.toolStrip1.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripAddBank,
            this.toolStripAddService,
            this.toolStripRefreshMap,
            this.toolStripRefreshRates,
            this.toolStripZoomIn,
            this.toolStripZoomOut});
            this.toolStrip1.Location = new System.Drawing.Point(0, 33);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.toolStrip1.Size = new System.Drawing.Size(1087, 31);
            this.toolStrip1.TabIndex = 10;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // toolStripAddBank
            // 
            this.toolStripAddBank.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripAddBank.Image = global::BankMap.Properties.Resources.add121;
            this.toolStripAddBank.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripAddBank.Margin = new System.Windows.Forms.Padding(10, 1, 0, 2);
            this.toolStripAddBank.Name = "toolStripAddBank";
            this.toolStripAddBank.Size = new System.Drawing.Size(28, 28);
            this.toolStripAddBank.Text = "Добавить банк";
            this.toolStripAddBank.Click += new System.EventHandler(this.toolStripAddBank_Click);
            // 
            // toolStripAddService
            // 
            this.toolStripAddService.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripAddService.Image = global::BankMap.Properties.Resources.add1211;
            this.toolStripAddService.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripAddService.Margin = new System.Windows.Forms.Padding(10, 1, 0, 2);
            this.toolStripAddService.Name = "toolStripAddService";
            this.toolStripAddService.Size = new System.Drawing.Size(28, 28);
            this.toolStripAddService.Text = "Добавить вид услуг";
            this.toolStripAddService.Click += new System.EventHandler(this.toolStripAddService_Click);
            // 
            // toolStripRefreshMap
            // 
            this.toolStripRefreshMap.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripRefreshMap.Image = global::BankMap.Properties.Resources.update3;
            this.toolStripRefreshMap.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripRefreshMap.Margin = new System.Windows.Forms.Padding(10, 1, 0, 2);
            this.toolStripRefreshMap.Name = "toolStripRefreshMap";
            this.toolStripRefreshMap.Size = new System.Drawing.Size(28, 28);
            this.toolStripRefreshMap.Text = "Обновить карту";
            this.toolStripRefreshMap.Click += new System.EventHandler(this.toolStripRefreshMap_Click);
            // 
            // toolStripRefreshRates
            // 
            this.toolStripRefreshRates.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripRefreshRates.Image = global::BankMap.Properties.Resources.dollars61;
            this.toolStripRefreshRates.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripRefreshRates.Margin = new System.Windows.Forms.Padding(10, 1, 0, 2);
            this.toolStripRefreshRates.Name = "toolStripRefreshRates";
            this.toolStripRefreshRates.Size = new System.Drawing.Size(28, 28);
            this.toolStripRefreshRates.Text = "Обновить курсы валют";
            this.toolStripRefreshRates.Click += new System.EventHandler(this.toolStripRefreshRates_Click);
            // 
            // toolStripZoomIn
            // 
            this.toolStripZoomIn.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripZoomIn.Image = global::BankMap.Properties.Resources.plus79;
            this.toolStripZoomIn.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.toolStripZoomIn.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripZoomIn.Margin = new System.Windows.Forms.Padding(20, 1, 0, 2);
            this.toolStripZoomIn.Name = "toolStripZoomIn";
            this.toolStripZoomIn.Size = new System.Drawing.Size(28, 28);
            this.toolStripZoomIn.Text = "Приблизить";
            this.toolStripZoomIn.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.toolStripZoomIn.Click += new System.EventHandler(this.toolStripZoomIn_Click);
            // 
            // toolStripZoomOut
            // 
            this.toolStripZoomOut.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripZoomOut.Image = global::BankMap.Properties.Resources.minus104;
            this.toolStripZoomOut.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.toolStripZoomOut.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripZoomOut.Margin = new System.Windows.Forms.Padding(10, 1, 0, 2);
            this.toolStripZoomOut.Name = "toolStripZoomOut";
            this.toolStripZoomOut.Size = new System.Drawing.Size(28, 28);
            this.toolStripZoomOut.Text = "Отдалить";
            this.toolStripZoomOut.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.toolStripZoomOut.Click += new System.EventHandler(this.toolStripZoomOut_Click);
            // 
            // pictureBox1
            // 
            this.pictureBox1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.pictureBox1.Image = global::BankMap.Properties.Resources.currency_symbol;
            this.pictureBox1.Location = new System.Drawing.Point(29, 413);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(256, 256);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox1.TabIndex = 9;
            this.pictureBox1.TabStop = false;
            // 
            // filterMenu
            // 
            this.filterMenu.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.bankFilterMenu,
            this.serviceFilterMenu});
            this.filterMenu.Name = "filterMenu";
            this.filterMenu.Size = new System.Drawing.Size(83, 29);
            this.filterMenu.Text = "Фильтр";
            // 
            // bankFilterMenu
            // 
            this.bankFilterMenu.Name = "bankFilterMenu";
            this.bankFilterMenu.Size = new System.Drawing.Size(211, 30);
            this.bankFilterMenu.Text = "По банку";
            // 
            // serviceFilterMenu
            // 
            this.serviceFilterMenu.Name = "serviceFilterMenu";
            this.serviceFilterMenu.Size = new System.Drawing.Size(211, 30);
            this.serviceFilterMenu.Text = "По услуге";
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1087, 615);
            this.Controls.Add(this.toolStrip1);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.nearestBranchBtn);
            this.Controls.Add(this.bestBuyBtn);
            this.Controls.Add(this.showAllBtn);
            this.Controls.Add(this.bestSellBtn);
            this.Controls.Add(this.comboBoxCur);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.menuStrip1);
            this.Controls.Add(this.gMapControl);
            this.MainMenuStrip = this.menuStrip1;
            this.MinimumSize = new System.Drawing.Size(1109, 671);
            this.Name = "MainForm";
            this.Text = "Карта отделений банков г. Минска";
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.addOnlyContextMenu.ResumeLayout(false);
            this.removeAddContextMenu.ResumeLayout(false);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private GMap.NET.WindowsForms.GMapControl gMapControl;
        private System.Windows.Forms.ContextMenuStrip addOnlyContextMenu;
        private System.Windows.Forms.ToolStripMenuItem addBankBranchBtn;
        private System.Windows.Forms.ContextMenuStrip removeAddContextMenu;
        private System.Windows.Forms.ToolStripMenuItem addBankBranchBtn2;
        private System.Windows.Forms.ToolStripMenuItem removeBankBranchBtn;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem файлToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem addServiceName;
        private System.Windows.Forms.ToolStripMenuItem addNewBankBtn;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox comboBoxCur;
        private System.Windows.Forms.Button bestSellBtn;
        private System.Windows.Forms.Button showAllBtn;
        private System.Windows.Forms.Button bestBuyBtn;
        private System.Windows.Forms.Button nearestBranchBtn;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripButton toolStripAddBank;
        private System.Windows.Forms.ToolStripButton toolStripAddService;
        private System.Windows.Forms.ToolStripButton toolStripRefreshMap;
        private System.Windows.Forms.ToolStripButton toolStripRefreshRates;
        private System.Windows.Forms.ToolStripButton toolStripZoomIn;
        private System.Windows.Forms.ToolStripButton toolStripZoomOut;
        private System.Windows.Forms.ToolStripMenuItem filterMenu;
        private System.Windows.Forms.ToolStripMenuItem bankFilterMenu;
        private System.Windows.Forms.ToolStripMenuItem serviceFilterMenu;
    }
}

