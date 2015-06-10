using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MyClassLib;
namespace TankWar
{
    class Program
    {
        static void Main(string[] args)
        {
            Tank tank1 = new Tank("Pantera");
            Tank tank2 = new Tank("T-34");
            Tank tank3 = new Tank("Pantera");
            Tank tank4 = new Tank("T-34");
            Tank tank5 = new Tank("Pantera");
            Tank tank6 = new Tank("T-34");
            Console.WriteLine(tank1.ToString());
            Console.WriteLine(tank2.ToString());
            Console.WriteLine(tank3.ToString());
            Console.WriteLine(tank4.ToString());
            Console.WriteLine(tank5.ToString());
            Console.WriteLine(tank6.ToString());
            Console.WriteLine("Бой первый. Победа за {0}", tank1 * tank2);
            Console.WriteLine("Бой второй. Победа за {0}", tank3 * tank4);
            Console.WriteLine("Бой третий. Победа за {0}", tank5 * tank6);
        }
    }
}
