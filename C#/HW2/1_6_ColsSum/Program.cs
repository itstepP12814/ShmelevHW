//Дан двумерный массив размерностью 5х5, заполненный случайными числами 
//из диапазона от 0 до 100. Найти максимальные элементы каждого столбца.
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace _1_6_ColsSum
{
    class Program
    {
        static void Main(string[] args)
        {
            Random randGen = new Random();
            //int[][] array = new int[5][5];
            int[][] array = new int[5][];
            for (int i = 0; i < array.Length; i++)
            {
                array[i] = new int[5];
                for (int j = 0; j < array[i].Length; j++)
                {
                    array[i][j] = randGen.Next(100);
                    Thread.Sleep(10);
                    Console.Write(array[i][j] + " ");
                }
                    Console.WriteLine("\n");
            }
            //Считаем цифры в колонках
            Console.WriteLine("Сумма цифр по строкам:");
            for (int i = 0; i < array.GetLength(0); i++)
            {
                Console.WriteLine("Строка №{0}: {1}", i+1, array[i].Sum());
            }
        }
    }
}
