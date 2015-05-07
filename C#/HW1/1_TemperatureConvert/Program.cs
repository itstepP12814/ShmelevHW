using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_TemperatureConvert
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите температуру в градусах Фаренгейта: ");
            string farTemp = Console.ReadLine();
            try
            {
                int farTempInt = Convert.ToInt32(farTemp);
                int celsTempInt = (farTempInt - 32) * 5 / 9;
                Console.WriteLine(celsTempInt);
                Console.Read();
            }
            catch (System.FormatException ex)
            {
               Console.WriteLine(ex);
            }
            
        }
    }
}
