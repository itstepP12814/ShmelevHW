using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PlaneSimulator
{
    /// <summary>
    /// Класс, описывающий самолет
    /// </summary>
    class Plane
    {
        /// <summary>
        /// Делегат для оповещения диспетчеров о проведении полета
        /// </summary>
        /// <param name="planeSpeed">Скорость самолета</param>
        /// <param name="planeAltitude">Высота самолета</param>
        /// <param name="maxSpeed">Максимальная скорость самолета</param>
        public delegate void notifyDispatchers(int planeSpeed, int planeAltitude, int maxSpeed);

        public notifyDispatchers dispInformator;

        int speed;
        int altitude;
        int maxSpeed;
        int minSpeed;
        int maxAltitude;
        int minAltitude;
        bool landingGranted;
        int dispCount;

        List<Dispatcher> dispatchers;
        public bool LandingGranted { get { return landingGranted; } set { landingGranted = value; } }
        public List<Dispatcher> Dispatchers { get { return dispatchers; } }
        public int Speed { get { return speed; } }
        public int Altitude { get { return altitude; } }
        public int MaxSpeed { get { return maxSpeed; } }
        public int MinSpeed { get { return minSpeed; } }
        public int MinAltitude { get { return minAltitude; } }
        public int MaxAltitude { get { return maxAltitude; } }
        
        public Plane()
        {
            this.speed = 0;
            this.altitude = 0;
            this.maxSpeed = 1200;
            this.minSpeed = 0;
            this.minAltitude = 0;
            this.maxAltitude = 10000;
            dispatchers = new List<Dispatcher>();
            landingGranted = false;
            dispCount = Dispatchers.Count;
        }
        /// <summary>
        /// Добавление нового диспетчера
        /// </summary>
        /// <param name="disp">Объект диспетчера</param>
        public void addDispatcher(Dispatcher disp)
        {
            dispatchers.Add(disp);
            dispInformator += new notifyDispatchers(disp.getRecommendedAltitude);
        }
        /// <summary>
        /// Удаление диспетчера из наблюдения за полетом
        /// </summary>
        internal void removeDispatcher()
        {
            if (dispCount > 2)
            {
                foreach (Dispatcher disp in dispatchers)
                {
                    if (disp.DispatcherDisabled != true)
                    {
                        disp.DispatcherDisabled = true;
                        break;
                    }
                }
            }
            else
                throw new DispatcherDeleteDeniedException();
        }

        /// <summary>
        /// Увеличение скорости самолета
        /// </summary>
        public void increaseSpeed()
        {
            if (speed + 50 < maxSpeed)
                speed += 50;
        }
        /// <summary>
        /// Увеличение скорости самолета форсажем
        /// </summary>
        public void increaseSpeedForsage()
        {
            if (speed + 150 < maxSpeed)
                speed += 150;
        }
        /// <summary>
        /// Уменьшение скорости самолета
        /// </summary>
        public void decreaseSpeed()
        {
            if (speed - 50 > minSpeed)
                speed -= 50;
            else
            {
                if (altitude != minAltitude)
                {
                    speed -= 50;
                    throw new WrongSpeedException(minSpeed, maxSpeed, speed);
                }
                speed -= 50;
            }
        }
        /// <summary>
        /// Уменьшение скорости самолета форсажем
        /// </summary>
        public void decreaseSpeedForsage()
        {
            if (speed - 150 > minSpeed)
                speed -= 150;
            else
            {
                speed -= 150;
                throw new WrongSpeedException(minSpeed, maxSpeed, speed);
            }
        }
        /// <summary>
        /// Увеличение высоты самолета
        /// </summary>
        public void increaseAltitude()
        {
            if (altitude + 250 < maxAltitude)
                altitude += 250;
        }
        /// <summary>
        /// Увеличение высоты полета самолета форсажем
        /// </summary>
        public void increaseAltitudeForsage()
        {
            if (altitude + 500 < maxAltitude)
                altitude += 500;
        }
        /// <summary>
        /// Уменьшение высоты полета самолета
        /// </summary>
        public void decreaseAltitude()
        {
            if (altitude - 250 > minAltitude)
                altitude -= 250;
            else
            {
                if (landingGranted == false)
                {
                    altitude -= 250;
                    throw new WrongAltitudeException(minAltitude, maxAltitude, altitude);
                }
                else
                    altitude -= 250;
            }
        }
        /// <summary>
        /// Уменьшение высоты полета самолета форсажем
        /// </summary>
        public void decreaseAltitudeForsage()
        {
            if (altitude - 500 > minAltitude)
                altitude -= 500;
            else
            {
                if (landingGranted == false)
                {
                    altitude -= 500;
                    throw new WrongAltitudeException(minAltitude, maxAltitude, altitude);
                }
                else
                    altitude -= 500;
            }
        }
    }
}
