//Пользователь вводит русский текст. Подсчитать количество слов, которые заканчиваются на гласную букву. 
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_10_VowelEndWords
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите предложение на русском: ");
            string userText = Console.ReadLine();
            string[] vowels = { "а", "о", "э", "и", "у", "ы", "е", "ё", "ю", "я" };
            string[] words = userText.Split(" ".ToCharArray());
            string[] result = new string[0];
            foreach (string word in words)
            {
                foreach (string vowel in vowels)
                {
                    if (word.EndsWith(vowel, StringComparison.CurrentCultureIgnoreCase))
                    {
                        Array.Resize(ref result, result.Length + 1);
                        result[result.Length - 1] = word;
                    }
                }
            }
            Console.WriteLine("Слова заканчивающиеся на гласную: ");
            foreach(string key in result){
                Console.WriteLine(key);
            }
        }
    }
}
