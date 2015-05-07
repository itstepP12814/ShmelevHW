using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _9_NumbersPyramide
{
    class Program
    {
        static void Main(string[] args)
        {
            int first = 1;
            int last = 10;

            for (int i = first; i < last; ++i)
            {
                for (int j = 0; j < i; ++j)
                {
                    Console.Write(i);
                }
                Console.WriteLine("\n");
            }
        }
    }
}
