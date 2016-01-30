using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using PClib;
using System.Runtime.Serialization.Formatters.Binary;
using System.IO;
namespace DeserializeConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            List<PC> pcs;
            try
            {
                string path = System.IO.Path.GetFullPath(@"..\..\..\SerializeConsoleApp\bin\Debug\listSerial.txt");
                using (FileStream fs = new FileStream(path, FileMode.Open, FileAccess.Read, FileShare.None))
                {
                    BinaryFormatter bf = new BinaryFormatter();
                    object ret = bf.Deserialize(fs);
                    pcs = (List<PC>)ret;
                }
                foreach (PC pc in pcs)
                {
                    Console.WriteLine(pc.modelName);
                    pc.powerOn();
                }

                foreach (PC pc in pcs)
                {
                    Console.WriteLine(pc.modelName);
                    pc.powerOff();
                }
            }
            catch (IOException)
            {
                Console.WriteLine("Проблема чтения файла");
            }
        }
    }
}
