using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Figures
{
    class Program
    {
        static void Main(string[] args)
        {
            Rectangle rect1 = new Rectangle(10, 15, ConsoleColor.Cyan);
            rect1.print();
            Rhombus rh1 = new Rhombus(11, 11, ConsoleColor.DarkGreen);
            rh1.print();
            Trigon tr1 = new Trigon(10, 10, ConsoleColor.Red);
            tr1.print();
            Trapeze ItsA_Trap = new Trapeze(10, 40, ConsoleColor.DarkMagenta);
            ItsA_Trap.print();
        }
    }
}
