using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MobileStore {
    internal static class StoreProgram {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        private static void Main() {
            //try {
                Application.EnableVisualStyles();
                Application.SetCompatibleTextRenderingDefault(false);
                Application.Run(new MobileStoreForm());
            //}
            //catch(Exception ex) {
             //   MessageBox.Show(ex.Message);
            //}
        }
    }

    [Serializable]
    public class Phone {
        public string Model { get; set; }
        public string OS { get; set; }
        public string Cost { get; set; }
        public string Processor { get; set; }
        public string ImagePath { get; set; }
        public List<Option> AdditionalOptions { get; set; }

        public Phone() {
            AdditionalOptions = new List<Option>();
        }
        public Phone(string model, string os, string processor, string cost) {
            Model = model;
            OS = os;
            Cost = cost;
            Processor = processor;
            ImagePath = null;
        }

        public Phone(string model, string os, string processor, string cost, List<Option> options) : 
            this(model, os, processor, cost) {
            AdditionalOptions = options;
        }

        public Phone(string model, string os, string processor, string cost, string imgPath) :
            this(model, os, processor, cost)
        {
            ImagePath = imgPath;
            AdditionalOptions = new List<Option>();
        }

        public Phone(string model, string os, string processor, string cost, string imgPath, List<Option> options) :
            this(model, os, processor, cost, imgPath)
        {
            AdditionalOptions = options;
        }

        public override string ToString() {
            return Model +" " + OS;
        }

        public static void SaveToFile(IEnumerable<Phone> PhoneDB)
        {
            FileStream fs = new FileStream("database.dat", FileMode.Create, FileAccess.Write);
            BinaryFormatter bf = new BinaryFormatter();
            bf.Serialize(fs, PhoneDB);
            fs.Close();
        }

        public static IEnumerable<Phone> LoadFromFile()
        {
            FileStream fs = new FileStream("database.dat", FileMode.Open, FileAccess.Read);
            BinaryFormatter bf = new BinaryFormatter();
            IEnumerable<Phone> obj = (IEnumerable<Phone>)bf.Deserialize(fs);
            fs.Close();
            return obj;
        }
    }

    [Serializable]
    public class Option
    {
        public Option(string name) {
            Name = name;
        }
        public Option() { }
        public string Name { get; set; }

        public override string ToString() {
            return Name;
        }
    }
}
