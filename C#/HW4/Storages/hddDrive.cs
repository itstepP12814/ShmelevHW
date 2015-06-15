using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
namespace Storages
{
    public class hddDrive : Storage
    {
        private HddPartition[] partitionArray;
        int usbSpeed;

        public hddDrive(string name, string model, long capacity,
           int usbSpeed, int numberOfPartitions, params long[] sizeOfNextPartition)
            : base(name, model, capacity)
        {
            this.usbSpeed = usbSpeed;
            try
            {
                partitionArray = new HddPartition[numberOfPartitions];
                //Проверяем хватит ли места
                //Если указано правильное количество разделов и места хватает, либо впритык
                if (capacity >= sizeOfNextPartition.Sum() && partitionArray.Length == sizeOfNextPartition.Length)
                {
                    for (int i = 0; i < partitionArray.Length; ++i)
                    {
                        partitionArray[i] = new HddPartition(sizeOfNextPartition[i]);
                    }
                }
                //Если пользователь забыл, либо не пожелал указать размер последних разделов, то мы устанавливаем для них
                //равный размер из оставшегося свободного места.
                else
                {
                    int amountOfAdditionalPartitions = partitionArray.Length - sizeOfNextPartition.Length;
                    //Если размера хватает и нужно досоздать разделы
                    if (capacity > sizeOfNextPartition.Sum() && partitionArray.Length >= sizeOfNextPartition.Length)
                    {
                        //Считаем количество оставшихся разделов и место под каждый

                        long freeCapacity = capacity - sizeOfNextPartition.Sum();
                        long addCapacityPerAdditionalPartition = freeCapacity / amountOfAdditionalPartitions;
                        //Создаем заданные разделы
                        for (int i = 0; i < sizeOfNextPartition.Length; ++i)
                        {
                            partitionArray[i] = new HddPartition(sizeOfNextPartition[i]);
                        }
                        //Создаем высчитанные разделы
                        for (int i = sizeOfNextPartition.Length; i < sizeOfNextPartition.Length + amountOfAdditionalPartitions; ++i)
                        {
                            partitionArray[i] = new HddPartition(addCapacityPerAdditionalPartition);
                        }
                    }
                    //Все остальное - неверно
                    else
                    {
                        throw new WrongTypeArgumentException("Неверное количество разделов" + amountOfAdditionalPartitions);
                    }
                }
            }
            catch (WrongTypeArgumentException ex)
            {
                Console.WriteLine(ex.Message);
            }
        }

        public int UsbSpeed
        {
            get{return usbSpeed;}
            set{usbSpeed = value;}
        }
        class HddPartition
        {
            long partitionSize;
            long freeSpace;
            internal HddPartition(long size)
            {
                partitionSize = size;
                freeSpace = partitionSize;
            }

            public long PartitionSize
            {
                get { return partitionSize; }
            }
            public long FreeSpace
            {
                get { return freeSpace; }
                set { freeSpace = value; }
            }
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
                Console.WriteLine("Введите номер рздела для записи:");
                Console.WriteLine(getDeviceInfo());
                string answerStr = Console.ReadLine();
                int answerNum;
                if (Int32.TryParse(answerStr, out answerNum))
                {
                    if (answerNum >= 1 && answerNum <= partitionArray.Length)
                    {
                        Console.WriteLine("Начата запись на раздел " + answerNum);
                        if (partitionArray[answerNum-1].FreeSpace >= commonSize)
                        {
                            partitionArray[answerNum-1].FreeSpace -= commonSize;
                            System.Threading.Thread.Sleep(writeTime);
                            return filesToCopy.Length;
                        }
                        else
                            throw new NotEnoughSpaceException(partitionArray[answerNum-1].FreeSpace, commonSize);
                    }
                    else
                        throw new WrongTypeArgumentException(answerStr);
                }
                else
                    throw new WrongTypeArgumentException(answerStr);

                
            }
            else
                return 0;
        }

        public override string getDeviceInfo()
        {
            string resultStr = "\0";
            for (int i = 0; i < partitionArray.Length; ++i)
            {
                resultStr += i+1 + " - раздел #" + i+1 + " - общий размер: " + partitionArray[i].PartitionSize/1000000 + "МБ, свободно: " + partitionArray[i].FreeSpace/1000000 + "МБ.\n";
            }
            resultStr += "\nОбщая емкость: " + getCapacity() / 1000000 + ", свободно: " + getFreeSpace()/1000000 + "\n";
            return resultStr;
        }

        public override long getCapacity()
        {
            long resultStr = 0;
            for (int i = 0; i < partitionArray.Length; ++i)
            {
                resultStr += partitionArray[i].PartitionSize;
            }
            return resultStr;
        }

        public override long getFreeSpace()
        {
            long resultStr = 0;
            for (int i = 0; i < partitionArray.Length; ++i)
            {
                resultStr += partitionArray[i].PartitionSize;
            }
            return resultStr;
        }

    }
}