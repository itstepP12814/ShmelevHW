using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _4_SquareProcessor
{
    class Program
    {
        protected static int width;
        protected static int heigth;
        protected static int innerSquareSide;
        static void Main(string[] args)
        {
            try
            {
                Console.WriteLine("Введите ширину прямоугольника: ");
                width = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("Введите высоту прямоугольника: ");
                heigth = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("Введите длину стороны вписываемого квадрата: ");
                innerSquareSide = Convert.ToInt32(Console.ReadLine());
                int squaresAmount = 0;
                int mainSquare = width * heigth;
                int innerSquare = innerSquareSide * innerSquareSide;
                if (mainSquare >= innerSquare)
                {
                    while (mainSquare >= innerSquareSide)
                    {
                        mainSquare -= innerSquare;
                        ++squaresAmount;
                    }
                    Console.WriteLine("В обозначенный квадрат впишется: " + squaresAmount + " квадратов");
                }
                else
                {
                    throw new Exception("Не впишется ни один квадрат");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex);
            }
        }
    }
}
