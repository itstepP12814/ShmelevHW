//Объявить одномерный (5 элементов ) массив с именем A и двумерный 
//массив (3 строки, 4 столбца) дробных чисел с именем B. Заполнить 
//одномерный массив А числами, введенными с клавиатуры пользователем,
//а двумерный массив В случайными числами с помощью циклов. Вывести на
//экран значения массивов: массива А в одну  строку, массива В – в виде
//матрицы. Найти в данных массивах максимальный элемент, минимальный 
//элемент, сумму всех элементов, произведение всех элементов, сумму 
//четных элементов массива А, сумму нечетных столбцов массива В. 

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_1_FillArrays
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] A = new int[0];
            float[,] B = new float[10,10];

            Console.WriteLine("Введите числа, разделяя их запятой");
            string tempStr = Console.ReadLine();
            string[] tempArray = tempStr.Split(",".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            //Заполняем массив А
            foreach (string str in tempArray)
            {
                int number;
                if(Int32.TryParse(str, out number)){
                    Array.Resize(ref A, A.Length+1);
                    A[A.Length-1] = number;
                }
            }
            //Заполняем массив В
            Random rand = new Random();
            for (int i = 0; i < B.GetLength(0); ++i)
            {
                for (int j = 0; j < B.GetLength(1); ++j) //Единица тут указывает на то, что мы получаем размерность второго измерения массива
                {
                    B[i,j] = rand.Next(100); //Генерируем случайное число до 100
                }
            }
            //Вывод
            Console.WriteLine("Масссив А:");
            foreach (int key in A)
            {
                Console.Write(key);
            }
            Console.WriteLine("\n");
            Console.WriteLine("Массив В:");
            for (int i = 0; i < B.GetLength(0); ++i)
            {
                for (int j = 0; j < B.GetLength(1); ++j)
                {
                    Console.Write(B[i, j] + " ");
                }
                Console.WriteLine("\n");
            }
            Console.WriteLine("\n");
        }
    }
}
