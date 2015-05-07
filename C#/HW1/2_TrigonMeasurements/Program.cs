using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_TrigonMeasurements
{
    class Program
    {
        class Point
        {
            public Point(int _x, int _y)
            {
                x = _x;
                y = _y;
            }
            protected int x;
            protected int y;
            public string getCoo()
            {
                return Convert.ToString(x) + "x" + Convert.ToString(y); 
            }
        };

        public class WrongVertexAmount : ApplicationException
        {
            public void what(){
                Console.WriteLine("Количеcтво указанных координат не совпадает с заданным количеством врешин");
            }
        }

        class Trigone
        {
            public Point vertex1;
            public Point vertex2;
            public Point vertex3;
            protected double perimeter;
            protected double square;
            public Trigone(int x1, int y1, int x2, int y2, int x3, int y3)
            {
                vertex1 = new Point(x1, y1);
                vertex2 = new Point(x2, y2);
                vertex3 = new Point(x3, y3);
                
                //Расчет периметра
                double firstLength = Math.Sqrt(Math.Pow((x2 - x1), 2) + Math.Pow((y2-y1),2));
                double secondLength = Math.Sqrt(Math.Pow((x3 - x2), 2) + Math.Pow((y3-y2),2));
                double thirdLength = Math.Sqrt(Math.Pow((x1 - x3), 2) + Math.Pow((y1-y3),2));
                perimeter = firstLength + secondLength +thirdLength;

                //Расчет площади
                double semiPerimeter = perimeter/2;
                square = Math.Pow((semiPerimeter*(semiPerimeter-firstLength)*(semiPerimeter-secondLength)*(semiPerimeter-thirdLength)), 0.5);
            }
            public double getSquare()
            {
                return square;
            }
            public double getPerimeter()
            {
                return perimeter;
            }
            public void display()
            {
                Console.WriteLine("Координаты вершин: " + vertex1.getCoo() + "; " + vertex2.getCoo() + "; " + vertex3.getCoo() + ";" +
                    "\nПериметр: " + perimeter + "\nПлощадь: " + square);
            }
        }
        static void Main(string[] args)
        {
            Trigone lol = new Trigone(2,1, 1,2, 3,2);

            lol.display();
        }
    }
}
