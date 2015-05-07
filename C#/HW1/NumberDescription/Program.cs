using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NumberDescription
{
    class Program
    {
        private static string[] _first;
        private static string[] _second;
        private static string[] _third;
        static void Main(string[] args)
        {
            try{
                _first = new[] { "", "cто", "двести", "триста", "четыреста", "пятьсот", "шестьсот", "семьсот", "восемьсот", "девятьсот" };
                _second = new[] { "", "десять", "двадцать", "тридцать", "сорок", "пятьдесят", "шестьдесят", "семьдесят", "восемьдесят", "девяносто" };
                _third = new[] { "", "один", "два", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять" };
                Console.WriteLine("Введите число от 100 до 999 - оно будет переведено в текст");
                string number = Console.ReadLine();
         
                if(Convert.ToInt32(number) >= 100 && Convert.ToInt32(number) <= 999){
                    string numberDefinition = "";
                    int i1 = Convert.ToInt32(Char.GetNumericValue(number[0]));
                    int i2 = Convert.ToInt32(Char.GetNumericValue(number[1]));
                    int i3 = Convert.ToInt32(Char.GetNumericValue(number[2]));
                    numberDefinition += _first[i1] + " ";
                    numberDefinition += _second[i2] + " ";
                    numberDefinition += _third[i3];
                    Console.WriteLine(numberDefinition);
                }
                else
                {
                    throw new Exception("Число не соответствует диапазону (100-999).");
                }
            }
            catch(Exception ex){
                Console.WriteLine(ex);
            }
        }
    }
}
