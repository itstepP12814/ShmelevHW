using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PlaneSimulator
{
    /// <summary>
    /// Класс описывающий диспетчера
    /// </summary>
    class Dispatcher
    {
        int failPoints;
        int weatherNum;
        int lastRecommendedAltitude;
        bool dispDisabled;
        /// <summary>
        /// Количество штрафных очков данного диспетчера
        /// </summary>
        public int FailPoints { get { return failPoints; } }
        /// <summary>
        /// Указывает, отключен ли диспетчер от управления самолетом (безопасное удаление)
        /// </summary>
        public bool DispatcherDisabled { get { return dispDisabled; } set { dispDisabled = value; } }
        public Dispatcher(int weatherNum)
        {
            this.weatherNum = weatherNum;
            failPoints = 0;
        }
        /// <summary>
        /// Получение рекомендаций диспетчера
        /// </summary>
        /// <param name="planeSpeed">Скорость самолета</param>
        /// <param name="planeAltitude">Высота самолета</param>
        /// <param name="maxSpeed">Максимальная скорость самолета</param>
        public void getRecommendedAltitude(int planeSpeed, int planeAltitude, int maxSpeed)
        {
            if (dispDisabled != true)
            {
                try
                {
                    if (planeAltitude > lastRecommendedAltitude + 300 && planeAltitude <= lastRecommendedAltitude + 600
                        || planeAltitude < lastRecommendedAltitude - 300 && planeAltitude >= lastRecommendedAltitude - 600)
                        failPoints += 25;
                    if (planeAltitude > lastRecommendedAltitude + 600 && planeAltitude <= lastRecommendedAltitude + 1000
                        || planeAltitude < lastRecommendedAltitude - 600 && planeAltitude >= lastRecommendedAltitude - 1000)
                        failPoints += 50;
                    if (planeAltitude > lastRecommendedAltitude + 1000 || planeAltitude < lastRecommendedAltitude - 1000)
                        throw new WrongAltitudeException(lastRecommendedAltitude-planeAltitude);
                    if (failPoints >= 1000)
                        throw new BadPilotException();
                    if (planeSpeed > maxSpeed)
                    {
                        failPoints += 50;
                        throw new MaxSpeedReachedException();
                    }
                    lastRecommendedAltitude = 7 * planeSpeed - weatherNum;
                    Console.ForegroundColor = ConsoleColor.DarkGreen;
                    Console.Write("\nРекомендуемая высота: " + lastRecommendedAltitude + "м. ");
                    if (failPoints == 0)
                        Console.ForegroundColor = ConsoleColor.DarkGray;
                    else
                        Console.ForegroundColor = ConsoleColor.Red;
                    Console.Write("Штрафые очки: " + failPoints);
                }
                catch (BadPilotException)
                {
                    Console.ForegroundColor = ConsoleColor.Red;
                    Console.WriteLine("\nПилот непригоден к полетам.");
                }
                catch (MaxSpeedReachedException)
                {
                    Console.ForegroundColor = ConsoleColor.Red;
                    Console.WriteLine("\nПревышена максимально допустимая скорость. Срочно сбросьте скорость.");
                }
            }
        }
    }
}
