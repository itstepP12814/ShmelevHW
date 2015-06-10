//1.1	Разработать класc Поезд.
//1.2	Реализовать не менее пяти закрытых полей (различных типов), представляющих основные характеристики рассматриваемого класса. 
//1.3	Создать не менее трех методов управления классом и методы доступа к его закрытым полям. 
//1.4	Создать метод, в который передаются аргументы по ссылке. 
//1.5	Создать не менее двух статических полей  (различных типов), представляющих общие характеристики объектов данного класса.  
//1.6	Обязательным требованием является реализация нескольких перегруженных конструкторов, аргументы которых определяются студентом, исходя из специфики реализуемого класса, а так же реализация конструктора по умолчанию.
//1.7	Создать статический конструктор.  
//1.8	Создать массив (не менее 5 элементов) объектов  созданного класса. 
//1.9	Создать дополнительный метод для данного класса в другом файле, используя ключевое слово partial.

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_1_MyClass
{
    class Program
    {
        static void Main(string[] args)
        {
            Train[] trains = new Train[5];
            for (int i = 0; i < trains.Length; i++)
            {
                trains[i] = new Train();
            }
            foreach (Train key in trains)
            {
                key.printTrain();
            }
            trains[1].makeTooToo(); //Вызов из метода из partial класса
        }
    }

    partial class Train
    {
        //Поля
        private static string trainHorn;
        private static string wayType;
        private float maxSpeed;
        private float currentSpeed;
        private string trainName;
        private double heigth;
        private double width;
        private double length;
        public int x, y;

        //Конструкторы
        public Train() : this("Train") { }
        public Train(string trainName) : this(trainName, 3, 3, 50, 120, 0, 0) { }
        public Train(string _trainName, double _heigth, double _width, double _length, float _maxSpeed, int _x, int _y)
        {
            trainName = _trainName;
            heigth = _heigth;
            width = _width;
            length = _length;
            maxSpeed = _maxSpeed;
            x =_x;
            y = _y;
            currentSpeed = 0;
        }
        static Train(){ //Зачем нужен статический констуктор если можно инициализировать поля в классе?
            trainHorn = "Too-tooo!";
            wayType = "railway";
        }
        
        //Методы
        public void moveForward(ref int _x, ref int _y)
        {
            ++x; ++y;
        }
        public void moveBack(ref int _x, ref int _y)
        {
            --x; --y;
        }
        public void increaseSpeed(int percentOfIncrease)
        {
            if (percentOfIncrease <= 100 && percentOfIncrease >= 0)
            {
                currentSpeed = (percentOfIncrease / 100) * maxSpeed;
            }            
        }

        public void printTrain()
        {
            Console.WriteLine("\n");
            Console.WriteLine("Максимальная скорость: " + maxSpeed);
            Console.WriteLine("Текущая скорость: " + currentSpeed);
            Console.WriteLine("Имя поезда: " + trainName);
            Console.WriteLine("Высота поезда: " + heigth);
            Console.WriteLine("Ширина поезда: " + width);
            Console.WriteLine("Длина поезда: " + length);
            Console.WriteLine("Координата Х: " + x);
            Console.WriteLine("Координата У: " + y);
            Console.WriteLine("\n");
        }
    }
}
