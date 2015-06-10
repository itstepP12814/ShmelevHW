using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_3_PalindromCheck
{
    class Program
    {
        static void Main(string[] args)
        {
            string palindrom;
            bool answer = false;
            Console.WriteLine("Введите слово и мы проверим, является ли оно палиндромом:");
            palindrom = Console.ReadLine();
            for (int i = 0, j = palindrom.Length; i < (palindrom.Length / 2) && j > palindrom.Length/2; ++i, --j)
            {
                if (palindrom[i] == palindrom[j-1])
                {
                    answer = true;
                }
                else
                {
                    answer = false;
                }
            }
            if (answer==true)
            {
                Console.WriteLine("Введенное слово - палиндром");
            }
            else
            {
                Console.WriteLine("Введенное слово - обычное");
            }
        }
    }
}
