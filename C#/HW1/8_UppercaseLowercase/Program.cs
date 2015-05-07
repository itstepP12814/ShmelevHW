using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _8_UppercaseLowercase
{
    class Program
    {
        static void Main(string[] args)
        {
            ConsoleKeyInfo curKey = new ConsoleKeyInfo();
            Console.WriteLine("Введенные вами символы будут в другом регистре:");
            while (curKey.KeyChar != '\n')
            {
                curKey = Console.ReadKey(true);
                if (curKey.KeyChar != '\n')
                {
                    char curChar = curKey.KeyChar;
                    if (curChar >= 97 && curChar <= 122)
                    {
                        curChar -= (char)32;
                        Console.Write(curChar);
                    }
                    else
                    {
                        if (curChar >= 65 && curChar <= 90)
                        {
                            curChar += (char)32;
                            Console.Write(curChar);
                        }
                        else
                        {
                            Console.Write(curChar);
                        }
                    }
                }
            }
            Console.WriteLine("\n");
        }
    }
}
