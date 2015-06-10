using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_4_WordCounter
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите предложение и мы подсчитаем сколько в нем слов:");
            string str = Console.ReadLine();
            string[] words = str.Split(" ".ToCharArray());
            Console.WriteLine("Ваше предложение состоит из " + words.Length + " слов.");
        }
    }
}
