using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LongWayCar
{
    class Program
    {
        static void Main(string[] args)
        {
            Car auto = new Car();
            auto.DeadEnd += new EventHandler(auto_DeadEnd);
            auto.LowFuel += new EventHandler(auto_LowFuel);
            auto.LowOil += new EventHandler(auto_LowOil);
            auto.SoHotEngine += new EventHandler(auto_SoHotEngine);

            while (auto.movePossible)
            {
                auto.Go();
                Console.WriteLine(auto.ToString());
                System.Threading.Thread.Sleep(50);
            }
        }

        static public void auto_DeadEnd(object sender, EventArgs e)
        {
            Console.WriteLine(sender.ToString());
            Console.WriteLine("Событие: Автомобиль достиг точки назначения");
        }
        static public void auto_LowFuel(object sender, EventArgs e)
        {
            Console.WriteLine(sender.ToString());
            Console.WriteLine("Событие: Закончилось топливо");
        }
        static public void auto_LowOil(object sender, EventArgs e)
        {
            Console.WriteLine(sender.ToString());
            Console.WriteLine("Событие: Закончилось масло");
        }
        static public void auto_SoHotEngine(object sender, EventArgs e)
        {
            Console.WriteLine(sender.ToString());
            Console.WriteLine("Событие: Двигатель перегрелся");
        }
    }

    class Car
    {
        public event EventHandler SoHotEngine;
        public event EventHandler LowFuel;
        public event EventHandler LowOil;
        public event EventHandler DeadEnd;

        byte wayPosition;
        byte fuelLevel;
        byte oilLevel;
        byte engineHeat;

        public bool movePossible;
        
        public Car()
        {
            wayPosition = engineHeat = 0;
            oilLevel = fuelLevel = 100;
            movePossible = true;
        }

        public void Go()
        {
            if (movePossible == true)
            {
                wayPosition++;
                fuelLevel--;
                oilLevel--;
                engineHeat++;
                if (engineHeat == 100 && SoHotEngine != null)
                {
                    SoHotEngine(this, EventArgs.Empty); //Видимо, генерируем событие
                    movePossible = false;
                }
                if (wayPosition == 100 && DeadEnd != null)
                {
                    DeadEnd(this, EventArgs.Empty);
                    movePossible = false;
                }
                if (fuelLevel == 0 && LowFuel != null)
                {
                    LowFuel(this, EventArgs.Empty);
                    movePossible = false;
                }
                if (oilLevel == 0 && LowOil != null)
                {
                    LowOil(this, EventArgs.Empty);
                    movePossible = false;
                }
            }
        }

        public override string ToString()
        {
            string result = null;
            if (movePossible == true)
                result += "Автомобиль едет. \n";
            if(movePossible == false)
                result += "Автомобиль остановился. \n";

            result += "Масло: " + oilLevel + "% \n" + "Топливо: " + fuelLevel + "% \n" + "Пройдено пути: " + wayPosition + "% \n" + "Перегрев двигателя: " + engineHeat + "% \n\n\n";
            return result;
        }
    }
}
