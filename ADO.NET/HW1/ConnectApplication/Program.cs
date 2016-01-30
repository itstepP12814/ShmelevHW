using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using UniversalConnect;

namespace ConnectApplication
{
    class Program
    {
        static void Main(string[] args) {
            try {
                ConnectorSQL sql = new ConnectorSQL("UKODBOOK", "People");
                sql.Connect();
                Console.WriteLine(sql.GetData("SELECT * FROM Persons"));
                Console.WriteLine();
            }
            catch(Exception ex) {
                Console.WriteLine(ex.Message + " Вызвано: " + ex.TargetSite);
                Console.ReadLine();
            }
        }
    }
}
