using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WeatherInfoLib;
namespace WeatherInfo
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                WeatherFetcher fetcher = new WeatherFetcher("config.ini");
                Console.WriteLine("Доступен показ погоды для следующих городов:");
                foreach (KeyValuePair<string, string> kvp in fetcher.cities)
                {
                    Console.Write(kvp.Value + " | ");
                }
                Console.WriteLine("\n\nВведите название города для которого вы хотите получить погоду: ");
                string answer = Console.ReadLine();

                List<DayWeatherInfo> weathers = fetcher.fetchWeather(answer);
                if (weathers != null)
                {
                    foreach (DayWeatherInfo weather in weathers)
                    {
                        Console.WriteLine("Погода для г. " + answer + " на " + weather.getDate);

                        foreach (KeyValuePair<string, PeriodInfo> kvp in weather.info)
                        {
                            Console.WriteLine(@"{0}
Температура: от {1} до {2} градусов по Цельсию
Атмосферное давление от {3} до {4} мм.рт.ст.
Ветер {5} м/c, направление - {6}
", kvp.Value.Period, kvp.Value.MinTemp, kvp.Value.MaxTemp, kvp.Value.MinPressure, kvp.Value.MaxPressure, kvp.Value.WindSpeed, kvp.Value.WindDirection);
                        }
                    }
                    Console.ReadLine();
                }
                else
                {
                    throw new ApplicationException("Погода для г. " + answer + " не найдена.");
                }
            }
            catch (System.Net.WebException)
            {
                Console.WriteLine("Невозможно получить данные, возможно отсутствует подключение к интернету.");
            }
            catch (ApplicationException ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
    }

    
}
