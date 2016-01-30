using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PlaneSimulator
{
    class Program
    {
        static void Main(string[] args)
        {
            Plane plane = new Plane();
            try
            {
                Random rand = new Random();
                plane.addDispatcher(new Dispatcher(rand.Next(-200, 200)));
                plane.addDispatcher(new Dispatcher(rand.Next(-200, 200)));
                Console.WriteLine("Симулятор полета.\n\nНажмите любую клавишу, чтобы запустить двигатель.");
                Console.ReadKey();
                Console.Write("");
                Console.WriteLine("Чтобы добавлять диспетчеров нажимайте А, чтобы удалять - D");
                Pilot pilot = new Pilot(plane);
                pilot.startFligth();
            }
            finally
            {
                int dispNumber = 0;
                int pointsSum = 0;
                Console.WriteLine("\n\nПолет окончен.\nШтрафные очки:");
                foreach (Dispatcher dispatcher in plane.Dispatchers)
                {
                    pointsSum = dispatcher.FailPoints;
                    Console.WriteLine("\tДиспетчер " + ++dispNumber + ": " + dispatcher.FailPoints);
                }
                Console.WriteLine("Общая сумма штрафных очков: " + pointsSum);
                Console.ReadLine();
            }
        }
    }
}
