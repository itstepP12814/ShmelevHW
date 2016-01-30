using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Windows.Forms;
using BankApplication;

namespace BankMap.Views
{
    public partial class AddMarker : Form
    {
        public DPoint MarkerDPoint { get; private set; }
        private bool MarkerAdded { get; set; }
        public int MarkerId { get; set; }
        public AddMarker(DPoint markerPoint)
        {
            InitializeComponent();
            MarkerDPoint = markerPoint;
            Closing += OnClosing;
            listBoxServicesInfo.DataSource = Program.db.GetServicesNames();
            comboBoxBank.DataSource = Program.db.GetBanks();
            MarkerId = -1;
            removeBtn.Enabled = false;
        }

        public AddMarker(DPoint markerPoint, int markerId) : this(markerPoint)
        {
            MarkerId = markerId;
            var bankBranch = Program.db.GetBankBranchById(markerId);
            comboBoxBank.Text = Program.db.GetBankById(bankBranch.Bank_Id).Name;
            textBoxBranchNumber.Text = bankBranch.Name;
            textBoxAddress.Text = bankBranch.Address;
            breakTextBox.Text = bankBranch.BreakTime;

            if(bankBranch.OpenDate.Value != null)
                dateTimePickerOpenDate.Value = bankBranch.OpenDate.Value;

            richTextBoxOperatorAdditionalInformation.Text = bankBranch.OperatorInfo;
            textBoxPhone.Text = bankBranch.PhoneNumber;
            var services = bankBranch.ServicesSet.ToList();
            for (int i = 0; i < listBoxServicesInfo.Items.Count; ++i)
            {
                ServicesNames ob = listBoxServicesInfo.Items[i] as ServicesNames;
                for (int j = 0; j < bankBranch.ServicesSet.Count; ++j)
                {
                    if (ob.Name == services[j].Name)
                    {
                        listBoxServicesInfo.SetItemChecked(i, true);
                    }
                }
            }
            textBoxWorkTime.Text = bankBranch.WorkTime;
            removeBtn.Enabled = true;
        }

        private void addBankButton_Click(object sender, EventArgs e)
        {
            if (MarkerDPoint == null)
            {
                throw new NoCoordinatesException();
            }
            if(comboBoxBank.SelectedItem == null
                || string.IsNullOrEmpty(textBoxBranchNumber.Text)
                || listBoxServicesInfo.CheckedItems.Count == 0)
                throw new FieldNotFilledException();
            Bank bankItem = (Bank)comboBoxBank.SelectedItem;
            
            //Если мы редактируем обьект
            if (MarkerId != -1)
            {
                Program.db.EditBankBranch(MarkerId, branchForEdit =>
                {
                    CreateBranchFromForm(ref branchForEdit);
                });
            }
            //Если добавляем новый
            else
            {
                BankBranch branchItem = new BankBranch();
                CreateBranchFromForm(ref branchItem);
                Program.db.AddBankBranchAsync(branchItem, bankItem);
            }
            Close();
        }

        void CreateBranchFromForm(ref BankBranch newBankBranch)
        {
            newBankBranch.Name = textBoxBranchNumber.Text;
            newBankBranch.Address = textBoxAddress.Text;
            newBankBranch.BreakTime = breakTextBox.Text;
            newBankBranch.OpenDate = dateTimePickerOpenDate.Value;
            newBankBranch.OperatorInfo = richTextBoxOperatorAdditionalInformation.Text;
            newBankBranch.PhoneNumber = textBoxPhone.Text;
            foreach (var checkedItem in listBoxServicesInfo.CheckedItems)
            {
                ServicesNames checkBox = (ServicesNames)checkedItem;
                newBankBranch.ServicesSet.Add(new Services() { Name = checkBox.Name });
            }
            newBankBranch.WorkTime = textBoxWorkTime.Text;
            newBankBranch.Xpos = MarkerDPoint.X;
            newBankBranch.Ypos = MarkerDPoint.Y;
        }

        private void OnClosing(object sender, CancelEventArgs cancelEventArgs)
        {
            if (MarkerAdded)
                DialogResult = DialogResult.OK;
            else
                DialogResult = DialogResult.Abort;

        }

        private void removeBtn_Click(object sender, EventArgs e)
        {
            Program.db.RemoveBankBranch(MarkerId);
            Close();
        }
    }
}
