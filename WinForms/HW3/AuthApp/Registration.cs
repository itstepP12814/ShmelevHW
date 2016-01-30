using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AuthApp
{
    public partial class Registration : Form
    {
        public Registration()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e) {
            try {
                var user = new User(textBox1.Text, textBox2.Text, textBox3.Text, textBox6.Text, textBox4.Text, textBox5.Text);
                AuthApplication.CurUser = user;
                AuthApplication.db.Connect();
                AuthApplication.db.AddUser(user);
                AuthApplication.db.connection.Close();

                this.DialogResult = DialogResult.OK;
            }
            catch(ApplicationException ex) {
                MessageBox.Show(ex.Message, "Ошибка");
            }
        }
        private void button2_Click(object sender, EventArgs e) {
            this.DialogResult = DialogResult.Cancel;
        }
    }
}
