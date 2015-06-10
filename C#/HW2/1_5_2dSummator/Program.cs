//Дан двумерный массив размерностью 5х5, заполненный случайными числами
//из диапазона от -100 до 100. Определить сумму элементов массива, 
//расположенных между минимальным и максимальным элементами.
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_5_2dSummator
{
    class Program
    {
        static void Main(string[] args)
        {
            int[,] array = {{3,1,2,3,4},{4,7,5,8,7}};

            var max = (from int x in array select x).Max(); //Способ с использованием LINQ
            var min = (from int x in array select x).Min();

            int end_i, end_j, start_i, start_j; //Индексы максимума и минимума
            end_i = end_j = start_i = start_j = -1;
            //Узнаем индексы
            for (int i = 0; i < array.GetLength(0); ++i)
            {
                for(int j=0; j<array.GetLength(1); ++j)
                {
                    if (array[i, j] == max)
                    {
                        end_i = i;
                        end_j = j;
                    }
                    else
                      {
                        if (array[i, j] == min)
                        {
                            start_i = i;
                            start_j = j;
                        }
                    }
                }
            }

            //Выбираем числа из диапазона
            int[] resultArray = new int[array.GetLength(1) * array.Rank];
            if (end_i != -1)
            {
                int counter = 0;
                
                for (int i = start_i; i <= end_i; ++i)
                {
                    int endPoint = array.GetLength(1);
                    int j = 0;
                    if (i == start_i)
                    {
                        j = start_j;
                    }
                    if (i == end_i)
                    {
                        endPoint = end_j+1;
                    }
                    for (; j < endPoint; ++j)
                    {
                        resultArray[counter] = array[i, j];
                        counter++;
                    }
                }
            }
            //вывод
            Console.WriteLine("Минимум: " + min + ", максимум: " + max + "\nСумма чисел из диапазона массива:");

            foreach (int key in resultArray)
            {
                Console.Write(key + "+");
            }
                Console.Write("=" + resultArray.Sum() + "\n");
        }
    }
}
