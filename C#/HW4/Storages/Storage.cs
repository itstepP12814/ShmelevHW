using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Storages
{
    public class MainBlock
    {
        static void Main()
        {
            try
            {
                Storage[] storages = new Storage[3];
                storages[0] = new dvdDrive("dvd1", "LG", 0, "singleside", 430000, 230000);
                storages[1] = new FlashDrive("MyFlash", "SiliconPower 548574", 4000000000, "usb3");
                storages[2] = new hddDrive("MyDrive", "Hitachi 45765", 500000000000, 30000000, 3, 200000000000, 200000000000);
                
                long amountOfFiles = 565000000000 / 780000000;
                File[] files = new File[amountOfFiles];
                for (int i=0; i<amountOfFiles; ++i)
                {
                    files[i] = new File(780000000);
                }
                Console.WriteLine("Вы собираетесь скопировать файлы:  ");
                foreach (File file in files)
                {
                    Console.WriteLine(file.ToString());
                }
                Console.WriteLine("Подключены следующие устройства: ");
                foreach (Storage storage in storages)
                {
                    Console.WriteLine(storage.getDeviceInfo());
                }
            }
            catch (NotEnoughSpaceException ex)
            {
                Console.WriteLine(ex.NotEnoughBytes);
            }
            catch (WrongTypeArgumentException ex)
            {
                Console.WriteLine("Неверно сделан выбор, вы указали: " + ex.WrongArgumentName);
            }
        }
    }

    public class File
    {
        int size;
        string filename;
        public File(int size)
        {
            Random rand = new Random(1000 - 9999);
            string randstr = Convert.ToString(rand.Next());
            this.filename = randstr;
            this.size = size;
        }
        public int Size
        {
            get { return size; }
        }
        public override string ToString()
        {
            return filename + " (" + size + "bytes)";
        }
    }
    public abstract class Storage
    {
        string name;
        string model;
        long capacity;
        public Storage(string name, string model, long capacity) : this(name, capacity){
            this.model = model;
        }
        public Storage(string name, long capacity)
        {
            this.name = name;
            this.capacity = capacity;
            this.model = "UNDEFINED";
        }
        public virtual string Name
        {
            get;
            set;
        }
        public virtual string Model
        {
            get;
            set;
        }
        public virtual int Capacity
        {
            get;
            set;
        }
        public virtual long getCapacity()
        {
            throw new System.NotImplementedException();
        }
        public virtual long getFreeSpace()
        {
            throw new System.NotImplementedException();
        }
        public virtual int copyToDevice(params File [] files)
        {
            throw new System.NotImplementedException();
        }
        public virtual string getDeviceInfo()
        {
            throw new System.NotImplementedException();
        }

    }

    //Пользовательское исключение отнаследованное от стандартного
    class WrongTypeArgumentException : ApplicationException
    {
        public WrongTypeArgumentException(): base() { }
        public WrongTypeArgumentException(String message): base(message) {
            wrongArgumentName = message;
        }
        public WrongTypeArgumentException(String message,
        Exception innerException): base(message, innerException) { }
        public WrongTypeArgumentException(
        System.Runtime.Serialization.SerializationInfo info,
        System.Runtime.Serialization.StreamingContext context): base(info, context) { }

        private string wrongArgumentName;
        public string WrongArgumentName
        {
            get
            {
                return wrongArgumentName;
            }
        }
    }

    class NotEnoughSpaceException : ApplicationException
    {
        public NotEnoughSpaceException() : base() { }
        public NotEnoughSpaceException(String message)
            : base(message)
        {
            this.message = message;
        }
        public NotEnoughSpaceException(long freeSpace, int commonFilesSize)
        {
            notEnoughBytes = freeSpace - commonFilesSize;
        }
        public NotEnoughSpaceException(String message,
        Exception innerException)
            : base(message, innerException) { }
        public NotEnoughSpaceException(
        System.Runtime.Serialization.SerializationInfo info,
        System.Runtime.Serialization.StreamingContext context)
            : base(info, context) { }

        private long notEnoughBytes;
        string message;
        public string NotEnoughBytes
        {
            get
            {
                return "Не хватает" + notEnoughBytes +" байт свободного места";
            }
        }
    }
}