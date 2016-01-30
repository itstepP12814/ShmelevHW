using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Odbc;
using System.Data.OleDb;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UniversalConnect {
    internal interface IMultiConnector {
        string ConnectionString { get; }
        string ProviderName { get; }
        ConnectionState State { get; }
        void Connect();
        string GetData(string Command);
    }

    public class ConnectorSQL : IMultiConnector {
        public string ConnectionString
        {
            get { return connectionString; }
            set { connectionString = value; }
        }

        private string connectionString;

        public string ProviderName
        {
            get { return providerName; }
        }

        private string providerName;

        public ConnectionState State
        {
            get { return state; }
        }

        private ConnectionState state;
        public SqlConnection connection;

        public ConnectorSQL() {
            providerName = "System.Data.SqlClient";
        }

        public ConnectorSQL(string server, string dbname) {
            connectionString = "Data Source = " + server + "; Initial Catalog = " + dbname + "; Integrated Security = True;";
            providerName = "System.Data.SqlClient";
        }

        public void Connect() {
            state = ConnectionState.Connecting;
            connection = new SqlConnection();
            connection.ConnectionString = connectionString;
            connection.Open();
            state = ConnectionState.Open;
        }

        public string GetData(string Command) {
            state = ConnectionState.Fetching;
            SqlCommand com = new SqlCommand(Command, connection);
            SqlDataReader reader = com.ExecuteReader();
            string result = null;
            while(reader.Read() != false) {
                for(int i = 0; i < reader.FieldCount; ++i) {
                    result += reader[i] + " ";
                }
                result += "\n";
            }
            return result;
        }

        public SqlDataReader CommandExecute(string Command)
        {
            state = ConnectionState.Fetching;
            SqlCommand com = new SqlCommand(Command, connection);
            SqlDataReader reader = com.ExecuteReader();
            return reader;
        }
    }

    public class ConnectorOleDB : IMultiConnector {
        public string ConnectionString
        {
            get { return connectionString; }
        }

        private string connectionString;

        public string ProviderName
        {
            get { return providerName; }
        }

        private string providerName;

        public ConnectionState State
        {
            get { return state; }
        }

        private ConnectionState state;
        private OleDbConnection connection;

        public ConnectorOleDB(string dbname) {
            connectionString = "Provider= Microsoft.Jet.OLE; data source = " + dbname + ";";
            providerName = "Microsoft.Jet.OLE";
        }

        public void Connect() {
            state = ConnectionState.Connecting;
            connection = new OleDbConnection();
            connection.ConnectionString = connectionString;
            connection.Open();
            state = ConnectionState.Open;
        }

        public string GetData(string Command) {
            state = ConnectionState.Fetching;
            var com = new OleDbCommand(Command, connection);
            var reader = com.ExecuteReader();
            string result = null;
            while(reader.Read() != false) {
                for(int i = 0; i < reader.FieldCount; ++i) {
                    result += reader[i] + " ";
                }
                result += "\n";
            }
            return result;
        }

        public class ConnectorODBC : IMultiConnector {
            public string ConnectionString
            {
                get { return connectionString; }
            }

            private string connectionString;

            public string ProviderName
            {
                get { return providerName; }
            }

            private string providerName;

            public ConnectionState State
            {
                get { return state; }
            }

            private ConnectionState state;
            private OdbcConnection connection;

            public ConnectorODBC(string dbname) {
                connectionString = "Dsn=" + dbname + ";";
                providerName = "System.Data.ODBC";
            }

            public void Connect() {
                state = ConnectionState.Connecting;
                connection = new OdbcConnection();
                connection.ConnectionString = connectionString;
                connection.Open();
                state = ConnectionState.Open;
            }

            public string GetData(string Command) {
                state = ConnectionState.Fetching;
                var com = new OdbcCommand(Command, connection);
                var reader = com.ExecuteReader();
                string result = null;
                while(reader.Read() != false) {
                    for(int i = 0; i < reader.FieldCount; ++i) {
                        result += reader[i] + " ";
                    }
                    result += "\n";
                }
                return result;
            }

        }
    }
}
