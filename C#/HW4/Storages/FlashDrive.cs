using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
namespace Storages
{
    public class FlashDrive : Storage
    {
        public FlashDrive(string name, string model, long capacity, 
            string type) : base(name, model, capacity)
        {
            TypeOfUSB = type;
            UsbSpeed = usbSpeed;
            this.freeSpace = capacity;
            
        }
        usbType type;
        long freeSpace;
        int usbSpeed;
        enum usbType { USB2, USB3 };
        public string TypeOfUSB
        {
            get { return typeReturn(); }
            set
            {
                try
                {
                    if (value.ToLower() == "usb2" || value.ToLower() == "usb_2" || value.ToLower() == "usb-2")
                    {
                        type = usbType.USB2;
                        usbSpeed = 2000000;
                    }
                    else
                    {
                        if (value.ToLower() == "usb3" || value.ToLower() == "usb_3" || value.ToLower() == "usb-3")
                        {
                            type = usbType.USB3;
                            usbSpeed = 30000000;
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
            if (type == usbType.USB2)
                return "USB 2.0";
            else
                return "USB 3.0";
        }
        public int UsbSpeed
        {
            get{return usbSpeed;}
            set{usbSpeed = value;}
        }

        public override int copyToDevice(params File[] filesToCopy)
        {
            //Определение общего размера файлов
            int commonSize = 0;
            foreach (File file in filesToCopy)
            {
                commonSize += file.Size;
            }
            int writeTime = (commonSize / usbSpeed) * 1000;
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
            string temp = "Flash-накопитель: " + Model + ", скорость чтения/записи: " + usbSpeed + ", свободно: " + freeSpace + ", тип носителя: ";
            if (type == usbType.USB2)
                temp += "USB 2.0";
            else
                temp += "UBS 3.0";
            return temp;
        }
    }

}