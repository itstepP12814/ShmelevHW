using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
namespace Storages
{
    public class dvdDrive : Storage
    {
        public dvdDrive(string name, string model, int capacity,
            string driveType, int readSpeed, int writeSpeed)
            : base(name, model, capacity)
        {
            this.ReadSpeed = readSpeed;
            this.WriteSpeed = writeSpeed;
            this.Type = driveType;
        }
        dvdType type;
        int readSpeed;
        int writeSpeed;
        int freeSpace;
        enum dvdType
        {
            SINGLE_SIDE, DOUBLE_SIDE
        }

        public int ReadSpeed
        {
            get { return readSpeed; }
            set { readSpeed = value; }
        }

        public string Type
        {
            get { return typeReturn(); }
            set
            {
                try
                {
                    if (value.ToLower() == "singleside" || value.ToLower() == "single_side" || value.ToLower() == "single-side")
                    {
                        type = dvdType.SINGLE_SIDE;
                        Capacity = freeSpace = 470000000;
                    }
                    else
                    {
                        if (value.ToLower() == "doubleside" || value.ToLower() == "double_side" || value.ToLower() == "double-side")
                        {
                            type = dvdType.DOUBLE_SIDE;
                            Capacity = freeSpace = 900000000;
                        }
                        else
                            throw new WrongTypeArgumentException(value);
                    }
                }
                catch (WrongTypeArgumentException ex)
                {
                    Console.WriteLine("Ошибка: Выбран неверный тип носителя: {0}", ex.WrongArgumentName);
                }
            }
        }

        private string typeReturn()
        {
            if (type == dvdType.SINGLE_SIDE)
                return "SingleSide";
            else
                return "DoubleSide";
        }

        public int WriteSpeed
        {
            get { return writeSpeed; }
            set { writeSpeed = value; }
        }

        public override int copyToDevice(params File[] filesToCopy)
        {
            //Определение общего размера файлов
            int commonSize = 0;
            foreach(File file in filesToCopy){
                commonSize+=file.Size;    
            }
            int writeTime = (commonSize / writeSpeed) * 1000;
            Console.WriteLine("Запись файлов займет {0} секунд, продолжить? (Y/N)", writeTime / 1000);
            string answer = Console.ReadLine();
            if (answer.ToLower() == "y")
            {
                if (freeSpace >= commonSize)
                {
                    freeSpace -= commonSize;
                    System.Threading.Thread.Sleep(writeTime);
                    return filesToCopy.Length;
                }
                else
                    throw new NotEnoughSpaceException(freeSpace, commonSize);
            }
            else
                return 0;
        }
        public override long getCapacity()
        {
            return Capacity;
        }
        public override long getFreeSpace()
        {
            return freeSpace;
        }

        public override string getDeviceInfo()
        {
            string temp = "DVD-привод: " + Model + ", скорость чтения: " + readSpeed + ", скорость записи: " + writeSpeed + ", свободно: " + freeSpace + ", тип носителя: ";
            if (type == dvdType.SINGLE_SIDE)
                temp += "односторонний";
            else
                temp += "двухсторонний";
            return temp;
        }
    }

}