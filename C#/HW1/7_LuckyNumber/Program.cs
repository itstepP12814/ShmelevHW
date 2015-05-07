using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _7_LuckyNumber
{
    class Program
    {
        class WrongLengthEx : ApplicationException
        {
            public void what()
            {
                Console.WriteLine("Введен не шестизначный номер.");
            }
        }
        class WrongFormatEx : ApplicationException
        {
            public void what()
            {
                Console.WriteLine("Во введенном вами номере встречаются нечисловые символы.");
            }
        }
        static void Main(string[] args)
        {
            try{
                Console.WriteLine("Введите шестизначный номер билета состоящий из цифр:");
                string curStringNumber = Console.ReadLine();
                if (curStringNumber.Length == 6)
                {
                    int luckyNum;
                        if (Int32.TryParse(curStringNumber, out luckyNum)) //Пробуем распарсить строку на инты
                        {
                            double firstSum = 0;
                            double secondSum = 0;
                            for(int i=0; i < curStringNumber.Length && i<3; ++i){
                                firstSum += char.GetNumericValue(curStringNumber[i]);
                            }
                            for(int i=3; i < curStringNumber.Length; ++i){
                                secondSum += char.GetNumericValue(curStringNumber[i]);
                            }
                            if(firstSum == secondSum)
                                Console.WriteLine("Ваш билет счастливый.");
                            else
                                Console.WriteLine("У вас обычный билет.");
                        }
                        else
                        {
                            throw new WrongFormatEx();
                        }
                        
                    }
                else
                {
                    throw new WrongLengthEx();
                }
            }
            catch (WrongLengthEx ex)
            {
                ex.what();
            }
            catch (WrongFormatEx ex)
            {
                ex.what();
            }
        }
    }
}
