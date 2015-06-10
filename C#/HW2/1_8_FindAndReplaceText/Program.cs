//Пользователь вводит текст, строку для поиска и строку для
//замены. Реализовать поиск в тексте заданной строки и замены
//ее на заданную подстроку. 
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_8_FindAndReplaceText
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите текст:");
            string userText = Console.ReadLine();
            Console.WriteLine("Введите искомый текст:");
            string findIt = Console.ReadLine();
            int searchSize = findIt.Length;
            int foundSize = userText.Replace(findIt, "").Length;
            int count = (userText.Length - foundSize) / searchSize;
            if (count != 0)
            {
                Console.WriteLine("Найдено " + count + " совпадений.\n");
                Console.WriteLine("Введите текст для замены:");
                string replaceOn = Console.ReadLine();
                Console.WriteLine(userText.Replace(findIt, replaceOn));
            }
            else{
                Console.WriteLine("Не найдено совпадений.");
            }
        }
    }
}
