using System;
using System.Data.SqlClient;
using System.Windows.Forms;
using AuthApp;
namespace AuthApp
{
    public partial class AuthForm : Form {
        private int inerval = 5000;
        private Timer timer;
        public AuthForm()
        {
            InitializeComponent();
            label2.Visible = false;
            progressBar1.Visible = false;
            timer = new Timer();
            timer.Tick += TimerOnTick;
            textBox1.GotFocus += (sender, args) => textBox1.SelectAll();
            textBox2.GotFocus += (sender, args) => textBox2.SelectAll();
            textBox1.LostFocus += (sender, args) => textBox1.DeselectAll();
            textBox2.LostFocus += (sender, args) => textBox2.DeselectAll();
            textBox1.Click += (sender, args) => textBox1.SelectAll();
            textBox2.Click += (sender, args) => textBox2.SelectAll();
        }

        private void CurUserOnChanged(object sender, EventArgs eventArgs) {
            try {
                AuthApplication.db.Connect();
                SqlCommand comm = new SqlCommand(
                    "UPDATE Users SET Password='" + AuthApplication.CurUser.Password
                        + "' WHERE Login='" + AuthApplication.CurUser.Username + "';");
                comm.ExecuteNonQuery();
            }
            catch (SqlException ex) {
                throw ex;
            }
        }


        public void ShowMessage(string message) {
            timer.Interval = inerval;
            label2.Visible = true;
            label2.Text = message;
            timer.Start();
        }

        private void TimerOnTick(object sender, EventArgs eventArgs) {
            label2.Text = "";
            label2.Visible = false;
            timer.Stop();
        }
    
        private void button1_Click(object sender, EventArgs e)
        {
            try {
                progressBar1.Visible = true;
                progressBar1.Minimum = 0;
                progressBar1.Maximum = 100;
                progressBar1.Step = 10;
                AuthApplication.db.Connect();
                var username = textBox1.Text;
                var pwd = textBox2.Text;
                //for(int i=0; i<6; ++i) {
                //    progressBar1.PerformStep();
                //    System.Threading.Thread.Sleep(500);
                //}
                AuthApplication.CurUser = AuthApplication.db.GetUser(username, pwd);
                AuthApplication.CurUser.Changed += CurUserOnChanged;
                AuthApplication.db.connection.Close();
                SuccessForm form = new SuccessForm();
                form.Show();
                progressBar1.Visible = false;
            }
            catch(ApplicationException ex) {
                ShowMessage(ex.Message);
            }
        }

        private void linkLabel2_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e) {
            AuthApplication.registrationForm = new Registration();
            //this.Hide();
            AuthApplication.registrationForm.ShowDialog();
            //this.ShowDialog();
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e) {
            AuthApplication.recoverPwdForm = new ForgotPwd();
            AuthApplication.recoverPwdForm.ShowDialog();
        }
    }
}
