using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Threading.Tasks;
using System.Windows.Forms;
using BankApplication;
using BankMap.Views;

namespace BankMap
{
    static class Program
    {
        public static DataBaseOperator db;
        public static AddService AddServiceForm;
        public static AddMarker AddMarkerForm;
        public static AddBank AddBankForm;
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            try
            {
                Application.EnableVisualStyles();
                Application.SetCompatibleTextRenderingDefault(false);
                db = new DataBaseOperator();
                Application.Run(new MainForm());
            }
            catch (WebException ex)
            {
                MessageBox.Show("Нет доступа к интернету: " + ex.Message, "Ошибка", MessageBoxButtons.OK);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }

    class NoCoordinatesException : ApplicationException
    {
        public NoCoordinatesException() : base() { }
        public NoCoordinatesException(String message) : base(message) { }
        public NoCoordinatesException(String message, Exception innerException) : base(message, innerException) { }
        public NoCoordinatesException(System.Runtime.Serialization.SerializationInfo info, System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }

    class FieldNotFilledException : ApplicationException
    {
        public FieldNotFilledException() : base() { }
        public FieldNotFilledException(String message) : base(message) { }
        public FieldNotFilledException(String message, Exception innerException) : base(message, innerException) { }
        public FieldNotFilledException(System.Runtime.Serialization.SerializationInfo info, System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }

    class NoTemporaryMarkerOnMapException : ApplicationException
    {
        public NoTemporaryMarkerOnMapException() : base() { }
        public NoTemporaryMarkerOnMapException(String message) : base(message) { }
        public NoTemporaryMarkerOnMapException(String message, Exception innerException) : base(message, innerException) { }
        public NoTemporaryMarkerOnMapException(System.Runtime.Serialization.SerializationInfo info, System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }
}
