using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MyClassLib;
namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            Tank loly = new Tank("Pantera");
            Console.WriteLine(loly.ToString());
        }
    }
}
