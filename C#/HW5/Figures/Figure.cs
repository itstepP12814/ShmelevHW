using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Figures
{
    abstract class Figure
    {
        readonly static char templateChar = '*'; 
        int height;
        int width;
        protected char[,] points;
        System.ConsoleColor color;
        public Figure(int height, int width, System.ConsoleColor color) : this(height, width)
        {
            this.color = color;
        }
        public Figure(int height, int width)
        {
            this.points = new char[height, width];
            this.height = height;
            this.width = width;
            this.color = ConsoleColor.White;
        }

        public char TemplateChar { get { return templateChar; } }
        public ConsoleColor Color { get { return color; } set { color = value; } }
        public virtual void print()
        {
            for (int i = 0; i < points.GetLength(0); ++i)
            {
                for (int j = 0; j < points.GetLength(1); ++j)
                {
                    Console.Write(points[i, j]);
                }
                Console.Write("\n");
            }
        }

    }

    class Rectangle : Figure
    {
        public Rectangle(int height, int width)
            : base(height, width)
        {
           
            for (int i = 0; i < height; ++i)
            {
                if (i == 0 || i == height - 1)
                {
                    for(int j=0; j < width; ++j)
                    {
                        points[i,j] = TemplateChar;
                    }
                }
                else
                {
                    points[i, 0] = TemplateChar;
                    points[i, width-1] = TemplateChar;
                }
                    
            }
        }
        public Rectangle(int height, int width, ConsoleColor color)
            : this(height, width)
        {
            this.Color = color;
            Console.ForegroundColor = color;
            //Как избавиться от повторения этой строчки во всех констукторах классов потомков?
        }

    }

    class Rhombus : Figure
    {
        public Rhombus(int height, int width)
            : base(height, width)
        {
            bool reverse = false;
            int leftBorder;
            int rightBorder;
            leftBorder = rightBorder = width / 2;
            for (int i = 0; i < height; ++i)
            {
                  for(int j=leftBorder; j<rightBorder; ++j){
                      points[i,j] = TemplateChar;
                  }
                  if (leftBorder == 0 && rightBorder == width - 1)
                      reverse = true;
                  if (reverse == false && leftBorder > 0 && rightBorder < width)
                  {
                      leftBorder--;
                      rightBorder++;
                  }
                  else
                  {
                      if (reverse == true)
                      {
                          leftBorder++;
                          rightBorder--;
                      }
                  }
            }
        }
        public Rhombus(int height, int width, ConsoleColor color)
            : this(height, width)
        {
            this.Color = color;
            Console.ForegroundColor = color;
            //Как избавиться от повторения этой строчки во всех констукторах классов потомков?
        }

    }

    class Trigon : Rhombus
    {
        public Trigon(int height, int width)
            : base(height*2, width*2)
        {
            char[,] old_points = points;
            points = new char[height, width];
            for (int i = 0; i < width; ++i)
            {
                for (int j = 0; j < height; ++j)
                {
                    points[i, j] = old_points[i, j];
                }
            }
        }
        public Trigon(int height, int width, ConsoleColor color)
            : this(height, width)
        {
            this.Color = color;
            Console.ForegroundColor = color;
            //Как избавиться от повторения этой строчки во всех констукторах классов потомков?
        }
    }

    class Trapeze : Figure
    {
        public Trapeze(int height, int width)
            : base(height, width)
        {
            int leftBorder;
            int rightBorder;
            leftBorder = (int)(width * (0.3));
            rightBorder = (int)(width * (0.7));
            for (int i = 0; i < height; ++i)
            {
                for (int j = leftBorder; j < rightBorder; ++j)
                {
                    points[i, j] = TemplateChar;
                }
                if (leftBorder > 0 && rightBorder < width)
                {
                    leftBorder--;
                    rightBorder++;
                }
            }
        }
        public Trapeze(int height, int width, ConsoleColor color)
            : this(height, width)
        {
            this.Color = color;
            Console.ForegroundColor = color;
            //Как избавиться от повторения этой строчки во всех констукторах классов потомков?
        }
    }
    //Многоугольник делать не стал, из-за недостатка времени
}
