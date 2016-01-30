using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using PClib;
using System.Runtime.Serialization.Formatters.Binary;
using System.IO;
namespace SerializeConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            string path = "listSerial.txt";
            List<PC> pcs = new List<PC>();
            pcs.Add(new PC("Asus Transformer Book TP300ld", "359748HF874HYF89", 2));
            pcs.Add(new PC("Asus X550C", "482J2J93J0239JD", 2));
            pcs.Add(new PC("Mitac 4460", "94FH9J90923DJ9DKJ", 1));
            pcs.Add(new PC("Mitac 4460", "SFKLDF3423408923J", 1));
            pcs.Add(new PC("Mitac 4460", "CXFKJSD4324234UJK", 1));
            try
            {
                //Сериализуем массив целиком
                using (FileStream fs = new FileStream(path, FileMode.CreateNew, FileAccess.Write, FileShare.None))
                {
                    Serialize<List<PC>>(pcs, fs);
                    Console.WriteLine("Файл с данными записан.");

                };


            }
            catch (IOException ex)
            {
                using (FileStream fs = new FileStream(path, FileMode.Create, FileAccess.Write, FileShare.None))
                {
                    Serialize<List<PC>>(pcs, fs);
                    Console.WriteLine("Файл с данными перезаписан.");
                };
            }


            string objPathMatrix = System.IO.Path.GetFullPath(@"./serialObjects/obj");
            //Сериализуем массив по элементам
            for (int i = 0; i < pcs.Count; ++i)
            {
                string objPath = objPathMatrix + (int)i + (int)1 + ".txt";
                try
                {
                    using (FileStream fs = new FileStream(objPath, FileMode.CreateNew, FileAccess.Write, FileShare.None))
                    {
                        Serialize<PC>(pcs[i], fs);
                        Console.WriteLine("Файл " + System.IO.Path.GetFileName(objPath) + " с объектом записан.");
                    };
                }
                catch (IOException ex)
                {
                    using (FileStream fs = new FileStream(objPath, FileMode.Create, FileAccess.Write, FileShare.None))
                    {
                        Serialize<PC>(pcs[i], fs);
                        Console.WriteLine("Файл " + System.IO.Path.GetFileName(objPath) + " с объектом перезаписан.");
                    };
                }
            }

            //Проверяем работу свойства аргумента
            pcs[0].ModelName = "любая присваиваемая строка должна вызвать получение информации из ini файла";
            Console.WriteLine(pcs[0].ModelName);

        }
        static void Serialize<T>(T serObj, FileStream fs)
        {
            BinaryFormatter bf = new BinaryFormatter();
            bf.Serialize(fs, serObj);
        }
    }
}
