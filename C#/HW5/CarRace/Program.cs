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
            Console.WriteLine("Дистанция: " + paths.Length + "м.\nАвтомобили на старте:\n");
            foreach (Car car in paths.cars)
            {
                Console.WriteLine(car.CarName);
            }
            Console.WriteLine("Намите любую клавишу для старта");
            Console.ReadKey();
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
            speed = rand.Next(30, 50); //метры в секунду
            System.Threading.Thread.Sleep(20);
            wayProgress += speed;
            if (wayProgress >= wayLength)
                if(Finished != null)
                Finished(this, EventArgs.Empty);
        }
        public override string ToString()
        {
            double speedkm = (double)((double)speed/(double)1000)*(double)60*(double)60; // O_o в переменную попадает 0, почему?
            return name + ": \n" + "\tПройдено: " + ((double)wayProgress/(double)wayLength)*(double)100 + "% пути\n\tСкорость: " + speedkm + "км/ч\n";
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
        public int Length { get {return length;} }
        public PathMap(int lengthMeters, int numberOfCars)
        {
            this.length = lengthMeters;
            cars = new Car[numberOfCars];
            over = false;
            for (int i = 0; i < cars.Length; ++i)
            {
                cars[i] = new Car("Car #" + (int)(i+1), length);
                //Все методы движения автомобилей будут присывоены одному делегату и будут вызываться через него вместе.
                pusher += new goToAll(cars[i].Go);
                //Здесь мы каждому событию каждого автомобиля присваиваем один универсальный обработчик
                cars[i].Finished += new EventHandler(raceFinished);
            }
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