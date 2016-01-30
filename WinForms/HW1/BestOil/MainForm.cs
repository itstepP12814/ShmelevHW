using System;
using System.Collections.Generic;
using System.Windows.Forms;
using System.Linq;
using System.Linq.Expressions;
namespace BestOil
{
    public partial class MainForm : Form
    {
        enum Stage {start,
            oilChoosen,
            methodChoosenValue,
            methodChoosenCost,
            allFieldsFillen,
            allReady,
            startOver
        }
        Stage OilStage { get; set; }
        Stage CafeStage { get; set; }
        private List<Control> checkboxes; 
        private List<Control> labels;
        private List<Control> textboxes;
        private decimal summ;
        private GasStation station;
        private MiniMarket market;
        public MainForm()
        {
            station = new GasStation();
            market = new MiniMarket();
            checkboxes = new List<Control>();
            labels = new List<Control>();
            textboxes = new List<Control>();
            InitializeComponent();
            textBox1.TextChanged += textBox1_TextChanged;
            comboBox1.DataSource = station.Marks;
            foreach (Control ctrl in tabPage2.Controls)
            {
                if (ctrl is CheckBox) checkboxes.Add(ctrl);
                if (ctrl is Label && ctrl.Text != "шт.") labels.Add(ctrl);
                if (ctrl is TextBox) textboxes.Add(ctrl);
            }
            ChangeOilView(Stage.start);
            ChangeMarketView(Stage.start);
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(comboBox1.SelectedIndex != -1) {
                var obj = (Gasoline)comboBox1.SelectedItem;
                label4.Text = obj.Cost.ToString();
                ChangeOilView(Stage.oilChoosen);
            }
        }

        private void ChangeOilView(Stage stg)
        {
            if(stg == Stage.start) {
                label4.Text = null;
                label10.Text = null;
                label6.Text = null;
                label13.Text = null;
                label24.Text = null;
                groupBox1.Enabled = false;
                textBox1.Enabled = false;
                textBox1.Text = null;
                button1.Enabled = false;
                button2.Visible = false;
                button3.Visible = true;
                button3.Enabled = false;
                comboBox1.SelectedIndex = -1;
                radioButton1.Checked = false;
                radioButton2.Checked = false;
            }
            if(stg == Stage.oilChoosen) {
                groupBox1.Enabled = true;
            }
            if (stg == Stage.methodChoosenValue){
                textBox1.Enabled = true;
                label10.Text = "литров";
            }
            if (stg == Stage.methodChoosenCost){
                textBox1.Enabled = true;
                label10.Text = "рублей";
            }
            if (stg == Stage.allFieldsFillen) {
                button1.Enabled = true;
            }
            if(stg == Stage.allReady) {
                button3.Enabled = true;
            }
            if(stg == Stage.startOver) {
                button2.Visible = true;
                button3.Visible = false;
            }

        }

        void ChangeMarketView(Stage stg)
        {
            if (stg == Stage.start) {
                label13.Text = null;
                label15.Text = null;
                button4.Enabled = false;

                for(int i=0; i<checkboxes.Count; ++i) {
                    checkboxes[i].Text = market.Food[i].Name;
                    CheckBox cb = (CheckBox) checkboxes[i];
                    cb.Checked = false;
                    labels[i].Text = market.Food[i].Cost.ToString();
                    textboxes[i].Enabled = false;
                    textboxes[i].Text = null;
                }

            }
            
            if (stg == Stage.allFieldsFillen)
            {
                button4.Enabled = false;
            }
            if (stg == Stage.allReady)
            {
                button4.Enabled = true;
            }
        }

        void UnblockAmountField(TextBox tb) {
            tb.Enabled = true;
        }

        void BlockAmountField(TextBox tb)
        {
            tb.Enabled = false;
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e) {
            station.ComputeBy = GasStation.ComputeType.value;
            ChangeOilView(Stage.methodChoosenValue);
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            station.ComputeBy = GasStation.ComputeType.cost;
            ChangeOilView(Stage.methodChoosenCost);
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            if(textBox1.Text.Length != 0)
                ChangeOilView(Stage.allFieldsFillen);
        }

        private void button1_Click(object sender, EventArgs e) {
            decimal numberFromForm;
            if(decimal.TryParse(textBox1.Text, out numberFromForm)) {
                Gasoline obj = (Gasoline)comboBox1.SelectedItem;
                if(station.ComputeBy == GasStation.ComputeType.cost) {
                    label24.Text = Math.Round(station.GetValueByCost(numberFromForm, obj), 3).ToString();
                    label6.Text = numberFromForm.ToString();
                    station.LocalSumm = numberFromForm;
                }
                if(station.ComputeBy == GasStation.ComputeType.value) {
                    var cost = Math.Round(station.GetCostByValue(numberFromForm, obj), 3);
                    label6.Text = cost.ToString();
                    label24.Text = numberFromForm.ToString();
                    station.LocalSumm = cost;
                }
            }
            ChangeOilView(Stage.allReady);
        }

        private void button3_Click(object sender, EventArgs e) {
            summ += station.LocalSumm + market.LocalSumm;
            label13.Text = summ.ToString();
            ChangeOilView(Stage.startOver);            
        }

        private void button2_Click(object sender, EventArgs e) {
            ChangeOilView(Stage.start);
            ChangeMarketView(Stage.start);
            station.LocalSumm = market.LocalSumm = 0;
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e) {
            if(checkBox1.Checked) UnblockAmountField(textBox2);
            else BlockAmountField(textBox2);
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e){
            if (checkBox2.Checked) UnblockAmountField(textBox3);
            else BlockAmountField(textBox3);
        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e){
            if (checkBox3.Checked) UnblockAmountField(textBox4);
            else BlockAmountField(textBox4);
        }

        private void checkBox4_CheckedChanged(object sender, EventArgs e){
            if (checkBox4.Checked) UnblockAmountField(textBox5);
            else BlockAmountField(textBox5);
        }

        private void textBox3_TextChanged(object sender, EventArgs e) {
            ChangeMarketView(textBox3.Text.Length != 0 ? Stage.allReady : Stage.allFieldsFillen);
        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {
            ChangeMarketView(textBox5.Text.Length != 0 ? Stage.allReady : Stage.allFieldsFillen);
        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {
            ChangeMarketView(textBox4.Text.Length != 0 ? Stage.allReady : Stage.allFieldsFillen);
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            ChangeMarketView(textBox2.Text.Length != 0 ? Stage.allReady : Stage.allFieldsFillen);
        }

        private void button4_Click(object sender, EventArgs e) {
            market.LocalSumm = 0;
            for(int i=0; i<checkboxes.Count; ++i) {
                CheckBox buf = (CheckBox)checkboxes[i];
                if(buf.Checked && textboxes[i].Text != null) {

                    int amount = int.Parse(textboxes[i].Text);
                    market.LocalSumm += market.GetCostByAmount(amount, market.Food[i]);

                }
            }
            label15.Text =  market.LocalSumm.ToString();
            ChangeOilView(Stage.allReady);
        }
    }
}
