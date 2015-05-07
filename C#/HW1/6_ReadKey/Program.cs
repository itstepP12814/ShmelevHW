using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _6_ReadKey
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Пожалуйста, введите слово или фразу(не забудьте поставить точку):");
            ConsoleKeyInfo currentKey;
            int spaceCounter = 0;
            string superLine ="";
            while (!superLine.EndsWith("."))
            {
                currentKey = Console.ReadKey();
                superLine += currentKey.KeyChar.ToString();
                if (superLine.EndsWith(" "))
                {
                    ++spaceCounter;
                }
            }
            Console.WriteLine("\nВы ввели: " + superLine + "\nВ этой фразе у вас " + spaceCounter + " пробелов.\nПришло время прощаться. Bye.");
        }
    }
}
