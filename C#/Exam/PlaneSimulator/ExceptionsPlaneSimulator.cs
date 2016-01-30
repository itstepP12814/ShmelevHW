using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PlaneSimulator
{
    /// <summary>
    /// Исключение, возникающее при превышении установленных пределов высот
    /// </summary>
    class WrongAltitudeException : ApplicationException
    {
        public WrongAltitudeException() : base() { }
        public WrongAltitudeException(int minAltitude, int maxAltitude, int currentAltitude)
        {
            if (currentAltitude >= maxAltitude)
                altitudeInfo = "Достигнута максимальная высота.";
            else
                if (currentAltitude <= minAltitude)
                    altitudeInfo = "Самолет разбился.";
                else
                    altitudeInfo = "Ложное срабатываqние";
        }
        public WrongAltitudeException(int wrongAltitude)
        {
            altitudeInfo = "Самолет разбился из-за превышения порога в " + wrongAltitude + "м.";
        }
        public WrongAltitudeException(String message,
        Exception innerException)
            : base(message, innerException) { }
        public WrongAltitudeException(
        System.Runtime.Serialization.SerializationInfo info,
        System.Runtime.Serialization.StreamingContext context)
            : base(info, context) { }

        private string altitudeInfo;
        public string AltitudeInfo
        {
            get
            {
                return altitudeInfo;
            }
        }
    }

    /// <summary>
    /// Исключение, возникающее при превышении установленных пределов скорости
    /// </summary>
    class WrongSpeedException : ApplicationException
    {
        public WrongSpeedException() : base() { }
        public WrongSpeedException(int minSpeed, int maxSpeed, int currentSpeed)
        {
            if (currentSpeed >= maxSpeed)
                speedInfo = "Достигнута максимальная скорость.";
            else
                if (currentSpeed <= minSpeed)
                    speedInfo = "Самолет разбился.";
                else
                    speedInfo = "Ложное срабатываение";
        }
        public WrongSpeedException(String message,
        Exception innerException)
            : base(message, innerException) { }
        public WrongSpeedException(
        System.Runtime.Serialization.SerializationInfo info,
        System.Runtime.Serialization.StreamingContext context)
            : base(info, context) { }

        private string speedInfo;
        public string SpeedInfo
        {
            get
            {
                return speedInfo;
            }
        }
    }
    /// <summary>
    /// Исключение, возникающее при обнаружении профессиональной некомпетентности пилота
    /// </summary>
    class BadPilotException : ApplicationException
    {
        public BadPilotException() : base() { }
        public BadPilotException(String message,
        Exception innerException)
            : base(message, innerException) { }
        public BadPilotException(
        System.Runtime.Serialization.SerializationInfo info,
        System.Runtime.Serialization.StreamingContext context)
            : base(info, context) { }
    }
    /// <summary>
    /// Исключение, возникающее при достижении максимальной скорости самолета
    /// </summary>
    class MaxSpeedReachedException : ApplicationException
    {
        public MaxSpeedReachedException() : base() { }
        public MaxSpeedReachedException(String message,
        Exception innerException)
            : base(message, innerException) { }
        public MaxSpeedReachedException(
        System.Runtime.Serialization.SerializationInfo info,
        System.Runtime.Serialization.StreamingContext context)
            : base(info, context) { }
    }
    /// <summary>
    /// Исключение, возникающее при обнаружении количества диспетчеров ниже допустимого
    /// </summary>
    class NotEnoughDispatchersException : ApplicationException
    {
        public NotEnoughDispatchersException() : base() { }
        public NotEnoughDispatchersException(String message,
        Exception innerException)
            : base(message, innerException) { }
        public NotEnoughDispatchersException(
        System.Runtime.Serialization.SerializationInfo info,
        System.Runtime.Serialization.StreamingContext context)
            : base(info, context) { }
    }
    /// <summary>
    /// Исключение, возникающее при невозможности удалить диспетчера
    /// </summary>
    class DispatcherDeleteDeniedException : NotEnoughDispatchersException
    {
        public DispatcherDeleteDeniedException() : base() { }
        public DispatcherDeleteDeniedException(String message,
        Exception innerException)
            : base(message, innerException) { }
        public DispatcherDeleteDeniedException(
        System.Runtime.Serialization.SerializationInfo info,
        System.Runtime.Serialization.StreamingContext context)
            : base(info, context) { }
    }
}
