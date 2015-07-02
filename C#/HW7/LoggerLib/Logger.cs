using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Text.RegularExpressions;
using System.Linq.Expressions;
using System.Globalization;
//Ini-config file example:
//mask={%date% - %hours%:%minutes%:%seconds%: (%messagetype%) %message%, user:%username%}
namespace LoggerLib
{
    public class Logger
    {
        string logfileName;
        string iniFile;
        string maskText;
        public enum messageType { Warning, Error, Information, Exception };
        public Logger(string logfilePath, string iniFile)
        {
            logfileName = logfilePath;
            this.iniFile = iniFile;
        }
        public string AddMessage(string message, messageType type)
        {
            createMessage(message, type);
            return message; //Возвращаем это же сообщение без изменений, удобно для вызова вида Console.WriteLine(logger.AddMessage("message"));
        }
        public void AddMessage(Exception exeption)
        {
            createMessage(exeption.Message, messageType.Exception);
        }

        private string createMessage(string mes, messageType mesType)
        {
            string resultStr = null;
            Dictionary<string,int> positions = maskParser();//Получаем позиции элементов в маске
            Dictionary<string, string> paramsValues = new Dictionary<string,string>();
            //Получаем данные по каждому параметру сообщения
            foreach(KeyValuePair<string,int> kvp in positions){
                paramsValues.Add(kvp.Key, null);
            }
            paramsValues["day"] = DateTime.Now.Day.ToString("d2");
            paramsValues["month"] = DateTime.Now.Month.ToString("d2");
            paramsValues["year"] = DateTime.Now.Year.ToString("d2");
            paramsValues["minutes"] = DateTime.Now.Minute.ToString("d2");
            paramsValues["seconds"] = DateTime.Now.Second.ToString("d2");
            paramsValues["hours"] = DateTime.Now.Hour.ToString("d2");
            paramsValues["messagetype"] = mesType.ToString();
            paramsValues["message"] = mes;
            paramsValues["username"] = Environment.UserName;
            using (FileStream fs = new FileStream(logfileName, FileMode.Append, FileAccess.Write, FileShare.ReadWrite))
            {
                StreamWriter writer = new StreamWriter(fs);
                resultStr = maskText;
                foreach (KeyValuePair<string, int> kvp in positions)
                {
                    Regex reg = new Regex("%" + kvp.Key + "%");
                    resultStr = reg.Replace(resultStr, paramsValues[kvp.Key]);
                }
                writer.WriteLine(resultStr);
                writer.Dispose();
            }
            return resultStr;            
        }

        Dictionary<string,int> maskParser()
        {
            //Dictionary describes position of parameters in mask
            Dictionary<string, int> parameters = new Dictionary<string, int>() 
            {
                {"day", 0},
                {"month", 0},
                {"year", 0},
                {"hours", 0},
                {"minutes", 0},
                {"seconds", 0},
                {"messagetype", 0},
                {"message", 0},
                {"username", 0}
            };
            //Another one collection for search
            Dictionary<string, int> params_edited = new Dictionary<string, int>(parameters) ; 
            string text;
            using (FileStream fs = new FileStream(iniFile, FileMode.Open, FileAccess.Read, FileShare.ReadWrite))
            {
                StreamReader reader = new StreamReader(fs);
                text = reader.ReadLine();
                reader.Dispose();
            }
            text = text.Substring(text.IndexOf('{'), (text.LastIndexOf('}') - text.IndexOf('{'))+1);
            text = text.TrimStart('{');
            text = text.TrimEnd('}');
            maskText = text;
            List<Match> m_collect = new List<Match>();
            int elementPosition = 0;
            foreach (KeyValuePair<string,int> kvp in parameters)
            {
                Regex reg = new Regex("%" + kvp.Key + "%");
                Match right = reg.Match(text);
                if (right.Success)
                {
                    m_collect.Add(right);
                    elementPosition++;
                    params_edited[kvp.Key] = elementPosition;
                }
            }
            return params_edited;
        }
        static string GetName<T>(Expression<Func<T>> expr)
        {
            var member = ((MemberExpression)expr.Body).Member;
            return member.Name;
        }
    }
}
