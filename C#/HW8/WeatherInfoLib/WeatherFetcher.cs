using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.IO;
using System.Text.RegularExpressions;
using iniReaderLib;
namespace WeatherInfoLib
{
    public class WeatherFetcher
    {
        public Dictionary<string, string> cities;
        public WeatherFetcher(string iniPath)
        {
            IniReader iniReader = new IniReader();
            cities = iniReader.Read(iniPath);
        }

        public List<DayWeatherInfo> fetchWeather(string cityName)
        {
            List<DayWeatherInfo> foundInfo = new List<DayWeatherInfo>();
            foreach (KeyValuePair<string, string> kvp in cities)
            {
                if (kvp.Value == cityName)
                {
                    string xmlPath = "http://informer.gismeteo.by/rss/" + kvp.Key + ".xml";
                    XmlDocument doc = new XmlDocument();
                    doc.Load(xmlPath);
                    XmlNodeList nodes = doc.GetElementsByTagName("item");
                    foreach (XmlNode node in nodes)
                    {
                        string title = node.ChildNodes[0].InnerText;
                        string info = node.ChildNodes[2].InnerText;
                        Match nameAndDate = Regex.Match(title, @"(\w+): (\w+) (\d\d) (\w{3,}), (\w{3,})");
                        Match tempPressWind = Regex.Match(info, @"\w*,{0,1} *\w+ (\d\d)..(\d\d) \w, \w+ (\d{3})..(\d{3}) [\w\s.]{0,}, \w+ ([\w-]*), (\d{1,3})");
                        if (nameAndDate.Success && tempPressWind.Success)
                        {
                            GroupCollection groupsND = nameAndDate.Groups;
                            GroupCollection groupsTPW = tempPressWind.Groups;

                            string nameOfCity = groupsND[1].Value; //Получаем имя города
                            //Получаем дату текущего узла XML
                            DateTime date = new DateTime(DateTime.Now.Year, monthInterpretate(groupsND[4].Value), Int32.Parse(groupsND[3].Value));
                            if (kvp.Value == nameOfCity)
                            { //Если город, который содержится в узле - искомый
                                bool found = false;
                                foreach (DayWeatherInfo day in foundInfo)
                                {
                                    //Сравниваем существующую дату с имеющимися датами
                                    if (day.getDate == date)
                                    {
                                        //Добавляем новый период для этого дня
                                        day.AddPeriod(groupsND[2].Value, Int32.Parse(groupsTPW[2].Value), Int32.Parse(groupsTPW[1].Value), Int32.Parse(groupsTPW[3].Value), Int32.Parse(groupsTPW[4].Value), Int32.Parse(groupsTPW[6].Value), groupsTPW[5].Value);
                                        found = true;
                                    }
                                }
                                if (found == false) //Если не нашли дату, пишем
                                {
                                    DayWeatherInfo newDay = new DayWeatherInfo(nameOfCity, date);
                                    //Добавляем новый период для этого дня
                                    newDay.AddPeriod(groupsND[2].Value, Int32.Parse(groupsTPW[2].Value), Int32.Parse(groupsTPW[1].Value), Int32.Parse(groupsTPW[3].Value), Int32.Parse(groupsTPW[4].Value), Int32.Parse(groupsTPW[6].Value), groupsTPW[5].Value);
                                    foundInfo.Add(newDay);
                                }
                            }
                        }
                    }
                }
            }
            return foundInfo;
        }
        static int monthInterpretate(string month)
        {
            List<string> mon = new List<string>() { "Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec" };
            for (int i = 0; i < 12; ++i)
                if (mon[i].Contains(month))
                    return i;
            throw new FormatException();
        }
    }

    public class DayWeatherInfo
    {
        public Dictionary<string, PeriodInfo> info;
        int maxPeriods;
        int curNumOfPeriods;
        string cityName;
        DateTime dateTime;
        public DateTime getDate { get { return dateTime; } }
        public DayWeatherInfo(string cityName, DateTime dateTime)
        {
            info = new Dictionary<string, PeriodInfo>();
            this.dateTime = dateTime;
            maxPeriods = 4;
            curNumOfPeriods = 0;
            this.cityName = cityName;
        }
        public void AddPeriod(string period, int maxTemp, int minTemp,
            int minPressure, int maxPressure, int windSpeed, string windDirection)
        {
            if (curNumOfPeriods < 4)
            {
                PeriodInfo periodInfo = new PeriodInfo(maxTemp,
                    minTemp, minPressure, maxPressure, windSpeed, windDirection, period);
                info.Add(period, periodInfo);
                curNumOfPeriods++;
            }
        }
    }
    public class PeriodInfo
    {
        int maxTemp;
        int minTemp;
        int minPressure;
        int maxPressure;
        int windSpeed;
        string windDirection;
        string period;
        public int MaxTemp { get { return maxTemp; } }
        public int MinTemp { get { return minTemp; } }
        public int MinPressure { get { return minPressure; } }
        public int MaxPressure { get { return maxPressure; } }
        public int WindSpeed { get { return windSpeed; } }
        public string WindDirection { get { return windDirection; } }
        public string Period { get { return period; } }
        public PeriodInfo(int maxTemp, int minTemp, int minPressure, int maxPressure, int windSpeed, string windDirection, string period)
        {
            this.maxTemp = maxTemp;
            this.minTemp = minTemp;
            this.minPressure = minPressure;
            this.maxPressure = maxPressure;
            this.windSpeed = windSpeed;
            this.windDirection = windDirection;
            this.period = period;
        }
    }
}
