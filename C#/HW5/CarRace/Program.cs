using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CarRace
{
    class Program
    {
        static void Main(string[] args)
        {
            PathMap paths = new PathMap(1000, 5);
            while (!paths.Over)
            {
                paths.pusher();
                Console.WriteLine(paths.ToString());
                System.Threading.Thread.Sleep(1000);
            }
        }
    }

    class Car
    {
        public event EventHandler Finished; 
        int speed;
        string name;
        int wayProgress;
        int wayLength;
        public Car(string name, int wayLength)
        {
            this.name = name;
            wayProgress = 1;
            this.wayLength = wayLength;
        }
        public void Go()
        {
            Random rand = new Random();
            speed = rand.Next(500, 1000); //метры в секунду
            System.Threading.Thread.Sleep(20);
            wayProgress += speed;
            if (wayProgress >= wayLength)
                if(Finished != null)
                Finished(this, EventArgs.Empty);
        }
        public override string ToString()
        {
            return name + ": \n" + "\tПройдено: " + wayProgress + "% пути\n\tСкорость: " + (speed/1000)*60*60 + "км/ч\n";
        }

        public string CarName { get { return name; } }
    }

    class PathMap
    {
        public Car[] cars;
        public delegate void goToAll();
        public goToAll pusher;
        int length;
        bool over;
        public bool Over { get { return over; } }
        public PathMap(int lengthMeters, int numberOfCars)
        {
            this.length = lengthMeters;
            cars = new Car[numberOfCars];
            over = false;
            for (int i = 0; i < cars.Length; ++i)
            {
                cars[i] = new Car("Car #" + i, length);
                //Все методы движения автомобилей будут присывоены одному делегату и будут вызываться через него вместе.
                pusher += new goToAll(cars[i].Go);
            }
            //Подписываем класс на событие финиша
            EventHandler finishChecker = new EventHandler(raceFinished);
        }
        public override string ToString()
        {
            string result = null;
            foreach (Car car in cars)
            {
                result += car.ToString();
            }
            return result;
        }

        void raceFinished(object sender, EventArgs e)
        {
            Car winCar = (Car)sender;
            Console.WriteLine("Гонка окончена, победитель: " + winCar.CarName);
            over = true;
        }
    }
}