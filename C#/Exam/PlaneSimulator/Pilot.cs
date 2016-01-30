using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PlaneSimulator
{
    /// <summary>
    /// Класс, описывающий пилота (контроллер)
    /// </summary>
    class Pilot
    {
        Plane plane;
        int dispCount;
        public Pilot(Plane plane)
        {
            this.plane = plane;
            dispCount = plane.Dispatchers.Count;
        }
        /// <summary>
        /// Метод начала полета. Так же отвечает за вызовы в процессе полета и управление
        /// </summary>
        public void startFligth(){
            if (dispCount >= 2)
            {
                do
                {
                    planeView();
                    if (plane.Speed >= 1000)
                        plane.LandingGranted = true;
                    try
                    {
                        ConsoleKeyInfo command = Console.ReadKey();
                        switch (command.Key)
                        {
                            case ConsoleKey.RightArrow:
                                if (command.Modifiers != ConsoleModifiers.Shift)
                                    plane.increaseSpeed();
                                else
                                    if (command.Modifiers == ConsoleModifiers.Shift)
                                        plane.increaseSpeedForsage();
                                break;
                            case ConsoleKey.LeftArrow:
                                if (command.Modifiers != ConsoleModifiers.Shift)
                                    plane.decreaseSpeed();
                                else
                                    if (command.Modifiers == ConsoleModifiers.Shift)
                                        plane.decreaseSpeedForsage();
                                break;
                            case ConsoleKey.UpArrow:
                                if (command.Modifiers != ConsoleModifiers.Shift)
                                    plane.increaseAltitude();
                                else
                                    if (command.Modifiers == ConsoleModifiers.Shift)
                                        plane.increaseAltitudeForsage();
                                break;
                            case ConsoleKey.DownArrow:
                                if (command.Modifiers != ConsoleModifiers.Shift)
                                    plane.decreaseAltitude();
                                else
                                    if (command.Modifiers == ConsoleModifiers.Shift)
                                        plane.decreaseAltitudeForsage();
                                break;
                            case ConsoleKey.A:
                                {
                                    Random rand = new Random();
                                    plane.addDispatcher(new Dispatcher(rand.Next(-200, 200)));
                                    dispCount++;
                                }
                                break;
                            case ConsoleKey.D:
                                {
                                    plane.removeDispatcher();
                                    dispCount--;
                                }
                                break;
                            default:
                                throw new ApplicationException("Неверная команда управления.");
                                break;
                        }
                        plane.dispInformator(plane.Speed, plane.Altitude, plane.MaxSpeed);
                    }
                    catch (WrongAltitudeException ex)
                    {
                        Console.ForegroundColor = ConsoleColor.Red;
                        Console.WriteLine(ex.AltitudeInfo);
                        break;
                    }
                    catch (WrongSpeedException ex)
                    {
                        Console.ForegroundColor = ConsoleColor.Red;
                        Console.WriteLine(ex.SpeedInfo);
                        break;
                    }
                    catch (DispatcherDeleteDeniedException)
                    {
                        Console.WriteLine("Невозможно удалить диспетчера - нужно как минимум 2.");
                    }
                    catch (NotEnoughDispatchersException)
                    {
                        Console.WriteLine("Недостаточно диспетчеров для продолжения полета.");
                    }
                    catch (ApplicationException ex)
                    {
                        Console.ForegroundColor = ConsoleColor.Red;
                        Console.WriteLine(ex.Message);
                    }

                    catch (Exception ex)
                    {
                        Console.ForegroundColor = ConsoleColor.Red;
                        Console.WriteLine("Общее исключение");
                    }
                }
                while (plane.Speed > plane.MinSpeed);
            }
            else
                throw new NotEnoughDispatchersException();
        }

        /// <summary>
        /// Вывод данных о полете
        /// </summary>
        public void planeView()
        {
            Console.ForegroundColor = ConsoleColor.DarkCyan;
            Console.WriteLine("\nДанные самолета:\n Высота: {0}, Скорость: {1}\n", plane.Altitude, plane.Speed);
            if (plane.Speed >= 1000 && plane.Speed < 1100)
                Console.WriteLine("Достигнута навигационная точка. Снижайтесь.");
        }
    }
}
