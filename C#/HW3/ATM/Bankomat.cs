/*Написать приложение, имитирующее работу банкомата
Реализовать классы Bank, Client, Account в различных
 * пространствах имен (общее пространство имен «Bankomat»).
 * Изначально клиенту нужно открыть счёт в банке, 
 * получить номер счёта, получить свой пароль, 
 * положить сумму на счёт.
*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace ATM
{
    namespace Bankomat
        //Остальные классы программы размещены в MyClassLib/ATM
    {
        class MainBlock
        {
            static void Main(string[] args)
            {
                try
                {
                    Banks.Bank Prior = new Banks.Bank("Приор Банк");
                    Clients.Client kostya = new Clients.Client(Prior);
                }

                catch (ApplicationException)
                {
                    Console.WriteLine("Неизвесная ошибка.");
                }
            }
        }
    }
}
