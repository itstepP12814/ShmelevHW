using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstApp
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите ваше имя:");
            string name;
            name = Console.ReadLine();
            if (name == "")
            {
                Console.WriteLine("Здравствуй, Юзер!");
            }
            else
            {
                Console.WriteLine("Здравствуй, " + name + "!"); 
            }
        }
    }
}
