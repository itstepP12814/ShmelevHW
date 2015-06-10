/*Разработать программу, моделирующую танковый бой.  В танковом
 * бою участвуют 5 танков «Т-34» и 5 танков «Pantera». Каждый 
 * танк («Т-34» и «Pantera») описываются параметрами: «Боекомплект»,  
 * «Уровень брони», «Уровень маневренности». Значение данных параметров 
 * задаются случайными числами от 0 до 100. Каждый танк участвует в парной
 * битве, т.е. первый танк «Т-34» сражается с первым танком «Pantera» 
 * и т.д. Победа присуждается тому танку, который превышает противника
 * по двум и более параметрам из трех (пример: см. программу).  Основное
 * требование:  сражение (проверку на победу в бою) реализовать путем
 * перегрузки оператора «*» (произведение).*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MyClassLib;
namespace TankWar
{
    class TankWar
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
