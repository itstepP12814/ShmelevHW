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
                return Convert.ToString(x) + ", " + Convert.ToString(y); 
            }
        };

        public class WrongVertexAmount : ApplicationException
        {
            public void what(){
                Console.WriteLine("Количеcтво указанных координат не совпадает с заданным количеством врешин");
            }
        }

        class Figure
        {
            public int numberOfVertex;
            private List<Point> trigonePoints = new List<Point>();
            public Figure(int vortexNum, params Point[] points){ //params позволяем передать произвольное число аргументов
                try{
                    numberOfVertex = vortexNum;
                    if (points.Length == vortexNum)
                    {
                        for (int i = 0; i < points.Length; ++i)
                        {
                            trigonePoints.Add(points[i]); //Добавляем все точки
                        }
                    }
                    else
                    {
                        throw new WrongVertexAmount();
                    }
                }
                catch(WrongVertexAmount ex){
                    ex.what();
                }
            }
            public void display()
            {
                string coordinates = "";
                foreach(Point curPoint in trigonePoints){
                    coordinates += curPoint.getCoo() + "; ";
                }
                Console.WriteLine("Вершин: " + numberOfVertex + ". Координаты вершин: " + coordinates);
            }
        }
        static void Main(string[] args)
        {
            Point a = new Point(1,1);
            Point b = new Point(2,2);
            Point c = new Point(3,3);

            Figure lol = new Figure(3, a, b, c);
            lol.display();
        }
    }
}
