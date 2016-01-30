using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MobileStore
{
    public partial class MobileStoreForm : Form
    {
        ObservableCollection<Phone> phones;
        private event EventHandler SomethingChanged;
        private List<Option> allOptions;
        private string savedMessage = "Сохранено";
        private string standartMessage;
        private bool FirstClick;
        public MobileStoreForm() {
            InitializeComponent();
            phones = new ObservableCollection<Phone>(){
                new Phone("IPhone 6", "iOS", "A4", "850", @"pic/iphone6.jpg", new List<Option>() {
                    new Option("GPS"),
                    new Option("ГЛОНАСС"),
                    new Option("LTE"),
                    new Option("WiFi")
                }),
                new Phone("IPhone 5s", "iOS", "A3", "580", @"pic/iphone5.jpg", new List<Option>() {
                    new Option("GPS"),
                    new Option("ГЛОНАСС"),
                    new Option("LTE"),
                    new Option("WiFi")
                }),
                new Phone("Samsung Galaxy S4", "Android 5", "Qualcomm Snapdragon 801", "510", @"pic/samsung.jpg", new List<Option>() {
                    new Option("GPS"),
                    new Option("ГЛОНАСС"),
                    new Option("LTE"),
                    new Option("WiFi"),
                    new Option("AMOLED")
                }),
                new Phone("Huawei G700", "Android 4", "Mediatek T6768", "290", @"pic/huawei.jpg", new List<Option>() {
                    new Option("GPS"),
                    new Option("LTE"),
                    new Option("WiFi")
                })
            };
            allOptions = new List<Option>() {
                new Option("GPS"),
                new Option("ГЛОНАСС"),
                new Option("LTE"),
                new Option("WiFi"),
                new Option("AMOLED")
            };
            standartMessage = label12.Text;
            listBox1.DataSource = phones;
            checkedListBox1.ItemCheck += checkedListBox1_Check;

            //События при изменении полей редактирования
            textBox1.TextChanged += TextBox1_TextChanged;
            textBox2.TextChanged += TextBox2_TextChanged;
            textBox3.TextChanged += TextBox3_TextChanged;
            textBox6.TextChanged += TextBox6_TextChanged;
            textBox4.TextChanged += TextBox4_TextChanged;

            //Вывод информации о то что информация сохранена
            SomethingChanged += MobileStoreForm_SomethingChanged;
        }

        private void MobileStoreForm_SomethingChanged(object sender, EventArgs e) {
            label12.Text = savedMessage;
            label12.ForeColor = Color.DarkGreen;
        }

        private void MobileStoreForm_NothingChanged(object sender, EventArgs e)
        {
            //Do nothing
        }

        private void TextBox4_TextChanged(object sender, EventArgs e)
        {
            Phone phone = (Phone)listBox1.SelectedItem;
            phone.Cost = textBox4.Text;
            SomethingChanged(sender, e);
        }

        private void TextBox6_TextChanged(object sender, EventArgs e)
        {
            Phone phone = (Phone)listBox1.SelectedItem;
            phone.ImagePath = textBox6.Text;
            SomethingChanged(sender, e);
        }

        private void TextBox3_TextChanged(object sender, EventArgs e)
        {
            Phone phone = (Phone)listBox1.SelectedItem;
            phone.Processor = textBox3.Text;
            SomethingChanged(sender, e);
        }

        private void TextBox2_TextChanged(object sender, EventArgs e)
        {
            Phone phone = (Phone)listBox1.SelectedItem;
            phone.OS = textBox2.Text;
            listBox1.DataSource = null;
            listBox1.DataSource = phones;
            SomethingChanged(sender, e);
        }

        private void TextBox1_TextChanged(object sender, EventArgs e)
        {
            Phone phone = (Phone)listBox1.SelectedItem;
            phone.Model = textBox1.Text;
            listBox1.DataSource = null;
            listBox1.DataSource = phones;
            SomethingChanged(sender, e);
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e) {
            label12.Text = standartMessage;
            label12.ForeColor = Color.Black;
            Phone lb = (Phone)listBox1.SelectedItem;
            if(tabControl1.SelectedTab == tabPage1) {
                //Если в списке есть телефоны
                if(lb != null) {
                    label4.Text = lb.Model;
                    label6.Text = lb.OS;
                    label8.Text = lb.Processor;
                    label10.Text = lb.Cost;
                    if(lb.ImagePath != null) {
                        pictureBox1.ImageLocation = lb.ImagePath;
                    }
                    listBox2.DataSource = lb.AdditionalOptions;
                }
                //Если все телефоны удалены
                else {
                    label10.Text = label8.Text = label6.Text = label4.Text = null;
                    pictureBox1.Image = pictureBox1.ErrorImage;
                    listBox2.DataSource = null;
                }
            }
            else {
                if (tabControl1.SelectedTab == tabPage2)
                {
                    if(lb != null) {
                        SomethingChanged -= MobileStoreForm_SomethingChanged;
                        SomethingChanged += MobileStoreForm_NothingChanged;
                        textBox1.Text = lb.Model;
                        textBox2.Text = lb.OS;
                        textBox3.Text = lb.Processor;
                        textBox4.Text = lb.Cost;
                        if(lb.ImagePath != null) {
                            textBox6.Text = lb.ImagePath;
                        }
                        UpdateAdditionalList(lb);
                        checkedListBox1.DataSource = allOptions;
                        SomethingChanged -= MobileStoreForm_NothingChanged;
                        SomethingChanged += MobileStoreForm_SomethingChanged;
                    }
                }
            }
        }

        void UpdateAdditionalList(Phone lb) {
            checkedListBox1.DataSource = null;
            //Записываем в список все существующие опции
            checkedListBox1.DataSource = allOptions;
            checkedListBox1.ItemCheck -= checkedListBox1_Check;//Временно отключаем событие чека
            for (int i = 0; i < checkedListBox1.Items.Count; ++i)
            {
                Option ob = (Option)checkedListBox1.Items[i];
                for (int j = 0; j < lb.AdditionalOptions.Count; ++j)
                {
                    if (ob.Name == lb.AdditionalOptions[j].Name)
                    {
                        checkedListBox1.SetItemChecked(i, true);
                    }
                }
            }
            checkedListBox1.ItemCheck += checkedListBox1_Check;//Включаем событие чека
        }
        private void button1_Click(object sender, EventArgs e)
        {
            if(listBox1.SelectedIndex != -1) {
                phones.Remove((Phone)listBox1.SelectedItem);
                listBox1.DataSource = null;
                listBox1.DataSource = phones;
                listBox1.Show();
                listBox1.SelectedIndex = -1;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (listBox1.SelectedIndex != -1)
            {
                phones = null;
                listBox1.DataSource = null;
                listBox1.DataSource = phones;
                listBox1.Show();
                listBox1.SelectedIndex = -1;
            }
        }

        private void button3_Click(object sender, EventArgs e) {
            Phone.SaveToFile(phones);
        }

        private void button4_Click(object sender, EventArgs e) {
            phones = (ObservableCollection<Phone>)Phone.LoadFromFile();
            listBox1.DataSource = null;
            listBox1.DataSource = phones;
        }

        private void checkedListBox1_Check(object sender, EventArgs e) {
            //try {
                Phone phone = (Phone)listBox1.SelectedItem;
                int checkboxId = checkedListBox1.SelectedIndex;
                Option checkboxItem = (Option)checkedListBox1.SelectedItem;

                if(phone != null) {
                    //Убирается галочка
                    if(checkedListBox1.GetItemChecked(checkboxId)) {
                        for(int i = 0; i < phone.AdditionalOptions.Capacity; ++i) {
                        if(phone.AdditionalOptions.Count != 0) { 
                            if(phone.AdditionalOptions[i].Name == checkboxItem.Name) {
                                phone.AdditionalOptions.RemoveAt(i);
                                break;
                            }
                          }
                        }
                    }
                    //Ставится галочка
                    else {
                        phone.AdditionalOptions.Add(checkboxItem);
                    }
                }
            //}
            //catch(Exception ex) {
             //   MessageBox.Show(ex.Message);
            //}
        }

        void ClearEditableFields()
        {
            Phone phone = (Phone)listBox1.SelectedItem;
            textBox1.Text = textBox2.Text = textBox3.Text = textBox6.Text = textBox4.Text = textBox5.Text = String.Empty;
            for (int i = 0; i < checkedListBox1.Items.Count; ++i)
            {
                phone.AdditionalOptions.Clear();
                checkedListBox1.SetItemChecked(i, false);
            }
        }

        private void button6_Click(object sender, EventArgs e) {
            Phone phone = (Phone)listBox1.SelectedItem;
            Option obj = (Option)checkedListBox1.SelectedItem;
            if(phone != null && obj != null) {
                for(int i = 0; i < allOptions.Count; ++i) {
                    if(obj.Name == allOptions[i].Name) {
                        allOptions.RemoveAt(i);
                        break;
                    }
                }
                UpdateAdditionalList(phone);
                SomethingChanged(this, EventArgs.Empty);
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            if (!string.IsNullOrEmpty(textBox5.Text)) {
                allOptions.Add(new Option(textBox5.Text));
                UpdateAdditionalList((Phone)listBox1.SelectedItem);
                SomethingChanged(this, EventArgs.Empty);
            }
        }

        private void button7_Click(object sender, EventArgs e) {
            ClearEditableFields();
            SomethingChanged(this, EventArgs.Empty);
        }

        private void button8_Click(object sender, EventArgs e) {
            phones.Add(new Phone());
            listBox1.DataSource = null;
            listBox1.DataSource = phones;
            listBox1.SelectedIndex = listBox1.Items.Count - 1;
        }
    }
}
