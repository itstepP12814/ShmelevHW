//Даны 2 массива размерности M и N соответственно. Необходимо
//переписать в третий массив общие элементы первых двух массивов
//без повторений.

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_2_NoDuplicate
{
    class Program
    {
        static void Main(string[] args)
        {

            int[] arr1 = {10,5,4,6,7,4,5,4,5,7,8,2,4};
            int[] arr2 = {6,3,22,6,7,88,6,3,46,5,32,2,5,3,34};
            int[] arr3 = new int[0];

            //Ищем дубликаты
            foreach (int key in arr1)
            {
                int check = Array.IndexOf(arr3, key);
                if (check == -1)
                {
                    int found = Array.IndexOf(arr2, key);
                    if (found != -1)
                    {
                        Array.Resize(ref arr3, arr3.Length + 1);
                        arr3[arr3.Length - 1] = key;
                    }
                }
                
            }
            //Вывод
            Console.WriteLine("Общие элементы:");
            foreach (int key in arr3)
            {
                Console.Write(key);
            }
            Console.WriteLine("\n");


        }
    }
}
