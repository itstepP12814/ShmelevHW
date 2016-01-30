using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using iniReaderLib;
namespace PClib
{

    public sealed class ParametersIniOnlyAttribute : System.Attribute
    {
       public string iniFilePath;
    }

    [Serializable]
    public class PC
    {
        public string modelName;
        public string serialNumber;
        public int coreNumber;

        [ParametersIniOnly(iniFilePath = "configModelName.ini")]        
        public string ModelName 
        { 
            get { return modelName;}
            set
            {
               Type ttype = ModelName.GetType();
               ParametersIniOnlyAttribute atrrib = (ParametersIniOnlyAttribute)Attribute.GetCustomAttribute(ttype, typeof(ParametersIniOnlyAttribute));
               if (atrrib != null)
               {
                   IniReader iniReader = new IniReader();
                   iniReader.Read(atrrib.iniFilePath);
                   iniReader.GetKeyValueStr(null, "ModelName", "Undefined");
               }
            }
        }

        public PC()
        {
            this.modelName = "Undefined";
            this.serialNumber = "Undefined";
            this.coreNumber = 0;
        }
        public PC(string modelName, string serialNumber, int coreCount)
        {
            this.modelName = modelName;
            this.serialNumber = serialNumber;
            this.coreNumber = coreCount;
        }

        public void powerOn()
        {
            for (int i = 0; i < 100; ++i)
            {
                System.Threading.Thread.Sleep(50);
                Console.WriteLine("Loading " + i + "%");
            }
            Console.WriteLine("Компьютер готов к работе. \nВас приветствует CorchOS.");
        }
        public void powerOff()
        {
            Console.WriteLine("Завершение программ.");
            System.Threading.Thread.Sleep(1000);
            Console.WriteLine("Завершение работы фоновых приложений.");
            System.Threading.Thread.Sleep(1000);
            Console.WriteLine("Завершение работы ядра операционной системы.");
            System.Threading.Thread.Sleep(1000);
            Console.WriteLine("Отключение питания.");
            System.Threading.Thread.Sleep(100);
            Console.WriteLine("Питание отключено.");
        }
        public void reboot()
        {
            powerOff();
            powerOn();
        }
    }
}
