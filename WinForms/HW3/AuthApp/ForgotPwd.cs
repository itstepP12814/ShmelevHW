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
    public partial class ForgotPwd : Form
    {
        public ForgotPwd()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try {
                if(textBox1.Text.Length == 0 || textBox2.Text.Length == 0 || textBox3.Text.Length == 0)
                    throw new ApplicationException("Заполнены не все поля для восстановления пароля");
                if(textBox2.Text != textBox3.Text)
                    throw new ApplicationException("Пароли не совпадают");

                if(AuthApplication.CurUser.Email == textBox1.Text) {
                    AuthApplication.CurUser.Password = textBox2.Text;
                }
                MessageBox.Show("Пароль успешно изменен", "Успееех");
                DialogResult = DialogResult.OK;
            }
            catch(ApplicationException ex) {
                MessageBox.Show(ex.Message, "Сообщение");
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            DialogResult = DialogResult.Cancel;
        }
    }
}
