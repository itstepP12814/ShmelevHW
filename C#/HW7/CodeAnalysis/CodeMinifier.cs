using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using LoggerLib;

namespace CodeAnalysis
{
    class CodeMinifier
    {
        static void Main(string[] args)
        {
            try{
                using(
                //Читаем файл
                    FileStream fs = new FileStream(@"victim.cs", FileMode.Open,
                        FileAccess.ReadWrite, FileShare.ReadWrite)){
                    StreamReader reader = new StreamReader(fs);
                    string text = reader.ReadToEnd(); //Считываем все содержимое
                    text = text.ToLower(); //Переводим в нижний регистр
                    List<string> words_old = new List<string>();
                    words_old.AddRange(text.Split(' ')); //Делим по словам
                    text = null;
                    for (int i = 0; i < words_old.Count; ++i)
                    {
                        
                        //words[i] = words[i].Replace('\n', ' ');
                        words_old[i] = words_old[i].Replace('\r', ' '); //Убираем переводы каретки
                        words_old[i].Trim();
                    }
                    List<string> words = new List<string>();
                    for (int i = 0; i < words_old.Count; ++i)
                    {
                        if (words_old[i] != "")
                        {
                            words.Add(words_old[i]); //Переписываем в другой массив непустые строки
                        }
                    }
                    reader.Dispose();
                    for (int i = 0; i < words.Count; ++i)
                        text += words[i] + " ";
                    List<string> lines;
                    lines = new List<string>();
                    lines.AddRange(text.Split('\n')); //Разбиваем по строкам

                    using(
                        FileStream fs_w = new FileStream(@"result.cs", FileMode.Create, FileAccess.Write, FileShare.ReadWrite))
                    {
                        
                        StreamWriter writer = new StreamWriter(fs_w);
                        for (int i = 0; i < lines.Count; ++i)
                        {
                            writer.WriteLine(lines[i]);
                        }
                        Console.WriteLine("Обработанный код записан в файл result.cs по пути: " + Path.GetDirectoryName("result.cs"));
                        writer.Dispose();
                    }
                        Console.WriteLine("Нажмите любую клавишу, чтобы переставить строки в файле в обратном порядке :D");
                        Console.ReadKey();
                    using (
                        FileStream fs_w = new FileStream(@"result.cs", FileMode.Create, FileAccess.Write, FileShare.ReadWrite))
                    {
                        Console.Write("\r");
                        StreamWriter writer = new StreamWriter(fs_w);
                        for (int i = lines.Count - 1; i >= 0; --i)
                        {
                            writer.WriteLine(lines[i]);
                        }
                        writer.Dispose();
                        Console.WriteLine("Строки переставлены. Я не знаю зачем.");
                    }
                }
            }
            catch(FileNotFoundException ex){
                Console.WriteLine("Исходный файл не найден.");
            }
        }
    }
}
