using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data.SqlClient;
using System.Diagnostics.Eventing.Reader;
using System.IO;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Runtime.Serialization.Formatters.Binary;
using System.Threading.Tasks;
using System.Windows.Forms;
using UniversalConnect;

namespace AuthApp
{

    internal static class AuthApplication {
        public static User CurUser;
        public static Form authForm;
        public static Form registrationForm;
        public static Form recoverPwdForm;
        public static ConnectorDB db;
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            try {
                Application.EnableVisualStyles();
                Application.SetCompatibleTextRenderingDefault(false);
                authForm = new AuthForm();
                db = new ConnectorDB();
                db.ConnectionString = "Data Source=UKODBOOK;Initial Catalog=PhoneStore;Integrated Security=True";
                Application.Run(authForm);
            }
            catch (Exception ex) {
                MessageBox.Show(ex.Message, "Сообщение");
            }
        }

        //Метод сохранения отрабатывает при каждом изменении списка пользователей
        //public static void SaveToFile(object sender, ListChangedEventArgs listChangedEventArgs)
        //{
        //    FileStream fs = new FileStream("database.dat", FileMode.Create, FileAccess.Write);
        //    BinaryFormatter bf = new BinaryFormatter();
        //    bf.Serialize(fs, users);
        //    fs.Close();
        //}

        //public static void LoadFromFile()
        //{
        //    FileStream fs = new FileStream("database.dat", FileMode.Open, FileAccess.Read);
        //    BinaryFormatter bf = new BinaryFormatter();
        //    users = (BindingList<User>)bf.Deserialize(fs);
        //    fs.Close();
        //}
    }

    [Serializable]
    public class User {
        public event EventHandler Changed;
        public string Username {get;}
        public string Password {
            get { return password; }
            set
            {
                password = value;
                Changed(this, EventArgs.Empty);
            }
        }

        private string password;
        public string Email {get;}
        public string Firstname {get;}
        public string Lastname {get;}

        public User() {}
        public User(string username, string password, string passwordAgain, string email) : this() {
            checkUser(username, password, passwordAgain, email);
            Username = username;
            this.password = password;
            Email = email;
        }

        public User(string username, string password, string passwordAgain, string email, string firstName, string lastName):
            this(username, password, passwordAgain, email) {
            Firstname = firstName;
            Lastname = lastName;
        }

        internal bool checkUser(string username, string password)
        {
            if(username.Length == 0)
                throw new ApplicationException("Необходимо указать имя пользователя");
            if (password.Length < 6)
                throw new ApplicationException("Пароль должен быть 6 символов и более");
            return true;
        }

        internal bool checkUser(string username, string password, string passwordAgain, string email) {
            if (username.Length == 0)
                throw new ApplicationException("Необходимо указать имя пользователя");
            if (password.Length < 6)
                throw new ApplicationException("Пароль должен быть 6 символов и более");
            if(password != passwordAgain)
                throw new ApplicationException("Введенные пароли не совпадают");
            if (email.Length == 0)
                throw new ApplicationException("Необходимо указать адрес электронной почты");
            return true;
        }
    }

    public class ConnectorDB : ConnectorSQL {
        public User GetUser(string username, string password) {
            try {
                SqlCommand comm = new SqlCommand("SELECT * FROM Users " +
                    "JOIN UsersInfo ON Users.Id=UsersInfo.UserId " +
                    "WHERE Login='" + username +
                    "' AND Password='" + password + "';",
                    connection);
                SqlDataReader reader = comm.ExecuteReader();
                if(reader.HasRows) {
                    if(reader.Read()) {
                        User user = new User(
                            reader["Login"].ToString(),
                            reader["Password"].ToString(),
                            reader["Password"].ToString(),
                            reader["Email"].ToString(),
                            reader["FirstName"].ToString(),
                            reader["LastName"].ToString());
                        return user;
                    }
                }
                else {
                    throw new ApplicationException();
                }
            }
            catch(SqlException ex) {
                throw new ApplicationException();
            }
            return new User();
        }

        public void AddUser(User user) {
            try {
                string currentId = "";
                SqlCommand getSimilar = new SqlCommand("SELECT Login FROM Users WHERE Login='" + user.Username + "';", connection);
                SqlCommand insertFirstTable = new SqlCommand("INSERT INTO Users VALUES (" +
                    "'" + user.Username + "', " +
                    "'" + user.Password + "', " +
                    "'" + user.Email + "'" +
                    ");", connection);
                SqlCommand getIdOfNewItem = new SqlCommand("SELECT Id FROM Users WHERE Login='" + user.Username + "';", connection);
                SqlCommand insertSecondTable = new SqlCommand("INSERT INTO UsersInfo (FirstName, LastName, UserId) VALUES(" +
                    "'" + user.Firstname + "', " +
                    "'" + user.Lastname + "', " +
                    currentId +
                    ");", connection);
                //Проверяем, есть ли пользователь с таким же именем в базе
                SqlDataReader reader = getSimilar.ExecuteReader();
                if (reader.Read())
                    if (reader.HasRows)
                        throw new ApplicationException("Такое имя пользователя уже используется");
                reader.Close();
                //Заполняем первую таблицу
                insertFirstTable.ExecuteNonQuery();
                //Получаем данные об айди для заполнения второй таблицы
                reader = getIdOfNewItem.ExecuteReader();
                if(reader.Read()) currentId = reader["Id"].ToString();
                reader.Close();
                //Заполняем вторую таблицу
                insertSecondTable.ExecuteNonQuery();
            }
            catch (SqlException ex) {
                throw ex;
            }
            catch(ApplicationException ex) {
                throw ex;
            }
        }
    }
}
