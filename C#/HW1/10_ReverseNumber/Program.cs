using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _10_ReverseNumber
{
    class Program
    {
        static void Main(string[] args)
        {
            int number = 456;
            Console.WriteLine("Исходное число: " + number);
            Console.Write("Это же число наоборот: ");
            string strNumber = number.ToString();

            for (int i = strNumber.Length-1; i >= 0; --i)
            {
                Console.Write(strNumber[i]);
            }
            Console.WriteLine();
        }
    }
}
