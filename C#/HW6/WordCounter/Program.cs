using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WordCounter
{
    class Program
    {
        static void Main(string[] args)
        {
            Dictionary<string, int> count = new Dictionary<string,int>();
            string text = "Вот дом, Который построил Джек. А это пшеница, Которая в темном чулане хранится В доме, Который построил Джек. А это веселая птица-синица, Которая часто ворует пшеницу, Которая в темном чулане хранится В доме, Который построил Джек.";
            string [] words = text.Split(' ');
            for (int i = 0; i < words.Length; ++i)
            {
                //Выпиливаем все знаки препинания, которые "прилеплены" к словам
                string[] temp = null;
                words[i] = words[i].ToLower();
                if (words[i].Contains(','))
                    temp = words[i].Split(',');
                else
                    if (words[i].Contains('.'))
                        temp = words[i].Split('.');
                    else
                        if (words[i].Contains(':'))
                            temp = words[i].Split(':');
                        else
                            if (words[i].Contains(';'))
                                temp = words[i].Split(';');
                if (temp != null) 
                    words[i] = temp[0];
                
                //инициализируем слова
                count[words[i]] = 0;
            }
            //Считаем слова
            for (int i = 0; i < words.Length; ++i)
            {
                count[words[i]]++;
            }
            foreach (KeyValuePair<string, int> kvp in count)
            {
                Console.WriteLine("{0} - {1} раз(а)", kvp.Key, kvp.Value);
            }
        }
    }
}
