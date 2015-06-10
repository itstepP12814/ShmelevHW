/*В С # индексация начинается с нуля, но в некоторых языках программирования 
 * это не так. Например, в Turbo Pascal индексация массиве начинается с 1.
 * Напишите класс RangeOfArray, который  позволяет работать с массивом 
 * такого типа, в котором индексный диапазон устанавливается пользователем.
 * Например, в диапазоне от 6 до 10, или от -9 до 15.
Подсказка:  В классе можно объявить две переменных, которые будут содержать
 * верхний и нижний индекс допустимого диапазона.
*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RevolutionArray
{
    class MainBlock
    {
        static void Main(string[] args)
        {
            try
            {
                RangeOfArray<int> array = new RangeOfArray<int>(4, 8);

                array[4] = 24375648;
                array[7] = 44747474;
                Console.WriteLine(array[4]);
                Console.WriteLine(array[7]);

                Console.ReadLine();
            }
            catch (IndexOutOfRangeException ex)
            {
                Console.WriteLine("Имеет место проблема размерности массива.");
            }
        }
    }

    class RangeOfArray <T>
    {
        int minBorder;
        int maxBorder;
        int diapason;
        private T[] innerArray;

        public RangeOfArray(int min, int max)
        {
            minBorder = min;
            maxBorder = max;
            diapason = max - min; //Реальный максимальный размер массива
            innerArray = new T[diapason];
        }

        //Индексатор в виде шаблона, ведь мы не знаем какой тип данных будет использовать пользователь
        public T this[int user_pos]
        {
            get
            {
                int pos = user_pos - diapason;
                //Сдедовало бы дописать методы для сравнения других типов
                if (pos >= innerArray.Length || pos > diapason || pos < 0)
                    throw new IndexOutOfRangeException();
                else
                    return (T)innerArray[pos];
            }
            set
            {
                int pos = user_pos - diapason;
                innerArray[pos] = (T)value;
            }
        }
    }
}
