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
    public partial class SuccessForm : Form
    {
        public SuccessForm()
        {
            InitializeComponent();
            label5.Text = label6.Text = label7.Text = "";
            var firstName = AuthApplication.CurUser.Firstname;
            var lastName = AuthApplication.CurUser.Lastname;
            var email = AuthApplication.CurUser.Email;
            firstName = firstName.Trim();
            lastName = lastName.Trim();
            label1.Text = label1.Text.Replace("Пользователь", firstName + " " + lastName);
            label5.Text = lastName;
            label6.Text = firstName;
            label7.Text = email;
        }

        private void button1_Click(object sender, EventArgs e) {
            Application.Exit();
        }
    }
}
