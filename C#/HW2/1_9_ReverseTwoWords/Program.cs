//Поменять местами соседние слова во введённом предложении.
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_9_ReverseTwoWords
{
    class Program
    {
        static void Main(string[] args)
        {
            string userText = Console.ReadLine();
            string[] words = userText.Split(" ".ToCharArray());
            for (int i = 0; i < words.Length; i+=2)
            {
                string revWord = words[i];
                if (i + 1 < words.Length)
                {
                    words[i] = words[i+1];
                    words[i + 1] = revWord;
                }
            }
            foreach (string key in words)
            {
                Console.Write(key + " ");
            }
        }
    }
}
