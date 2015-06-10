//Заполнить квадратную матрицу размером N x N по спирали 
//(N – нечётное число). Число 1 ставится в центр матрицы,
//а затем массив заполняется по спирали против часовой 
//стрелки значениями по возрастанию.
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_7_SpiralMatrixFill
{
    class Coo
    {
        public int x, y;
        public Coo(int _x, int _y)
        {
            x = _x;
            y = _y;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            int size = 7;
            int[,] arr = new int[size, size];
            Coo startPoint = new Coo(size/2, size/2);
            int counter = 2;
            int moveNum = 1;
            int i = startPoint.y;
            int j = startPoint.x;
            arr[i, j] = 1;
            while (i < arr.GetLength(0) && j < arr.GetLength(1)-1 || counter < arr.Length+1)
            {
                switch (moveNum)
                {
                    case 1: ++j; //Двигаемся вправо
                        break;
                    case 2: --i; //Двигаемся вверх
                        break;
                    case 3: --j; //Двигаемся влево
                        break;
                    case 4: ++i; //Двигаемся вниз
                        break;
                    default:
                        moveNum = 1;
                        ++j;
                        break;
                }
                if (arr[i,j] == 0)
                {
                    arr[i, j] = counter;
                    ++counter;
                    ++moveNum;
                }
                else
                {
                    //Делаем шаг назад
                    switch (moveNum)
                    {
                        case 1: --j;
                            break;
                        case 2: ++i;
                            break;
                        case 3: ++j;
                            break;
                        case 4: --i;
                            break;
                        default:
                            break;
                    }
                    if (moveNum == 1)
                        moveNum = 4;
                    else
                        --moveNum;
                }
            }
            Console.WriteLine("Спирально заполненный массив:");
            for (int a = 0; a < arr.GetLength(0); ++a)
            {
                for (int b = 0; b < arr.GetLength(1); ++b)
                {
                    Console.Write(arr[a, b] + " ");
                }
                Console.WriteLine("\n");
            }
        }
    }
}
