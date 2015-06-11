using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ATM
{
    namespace Clients
    {
        public class Client
        {
            Banks.Bank clientBank; //Ссылка на банк
            string username;
            public Client(Banks.Bank bank)
            {
                clientBank = bank;
                //При инициализации клиента предлагаем создать счет
                Console.WriteLine("Вы новый клиент. Для пользования услугами банка Вам необходимо открыть счет. \nСоздать новый счет? (Y/N):");
                string answer = Console.ReadLine();
                if (answer.ToLower() == "y")
                {
                    Console.WriteLine("Введите Ваше имя:");
                    username = Console.ReadLine();
                    Console.WriteLine("Ваш счет открыт:\n" + clientBank.openAccount(username));
                }

                showMenu();

            }

            public void showMenu()
            {
                bool exit = false;
                try
                {
                    while (exit != true)
                    {
                        Console.WriteLine(@"Выберите действие:
                    1 - Вывод баланса на экран.
                    2 - Пополнение счета
                    3 - Снять деньги со счета
                    4 - Выход
                    Введите номер пункта и нажмите Ввод:");
                        string answer = Console.ReadLine();
                        int numberAnswer;
                        Int32.TryParse(answer, out numberAnswer);
                        try
                        {
                            switch (numberAnswer)
                            {
                                case 1:
                                    {
                                        Console.WriteLine("Для проведения операции требуется пароль: ");
                                        string password = Console.ReadLine();
                                        Console.WriteLine(clientBank.viewAccount(username, password));
                                    }
                                    break;
                                case 2:
                                    {
                                        Console.WriteLine("Для проведения операции требуется пароль: ");
                                        string password = Console.ReadLine();
                                        Console.WriteLine("Введите сумму, которую вы хотите добавить на счет:");
                                        string trySum = Console.ReadLine();
                                        decimal sumToAdd;
                                        if (Decimal.TryParse(trySum, out sumToAdd))
                                            Console.WriteLine(clientBank.addMoney(username, password, sumToAdd));
                                        else
                                            throw new FormatException();
                                    }
                                    break;
                                case 3:
                                    {
                                        Console.WriteLine("Для проведения операции требуется пароль: ");
                                        string password = Console.ReadLine();
                                        Console.WriteLine("Введите сумму, которую вы хотите снять со счета:");
                                        string trySum = Console.ReadLine();
                                        decimal sumToGet;
                                        if (Decimal.TryParse(trySum, out sumToGet))
                                            Console.WriteLine(clientBank.getCash(username, password, sumToGet));
                                        else
                                            throw new FormatException();
                                    }
                                    break;
                                case 4:
                                    exit = true;
                                    Console.WriteLine("Всего доброго!");
                                    break;
                                default:
                                    Console.WriteLine("Вы ошиблись в выборе. Попробуйт еще раз.");
                                    break;
                            }
                        }
                        catch (ApplicationException)
                        {
                            Console.WriteLine("Ошибка авторизации: Возможно введен неверный пароль.");
                        }
                        catch (UnauthorizedAccessException)
                        {
                            Console.WriteLine("Ошибка авторизации: Вы ввели неверный пароль три раза подряд. Счет заблокирован.");
                            exit = true;
                        }
                        catch (InsufficientMemoryException)
                        {
                            Console.WriteLine("Ошибка счета: На счете недостаточно средств для данной операции.");
                        }
                    }
                }
                catch (FormatException)
                {
                    Console.WriteLine("Вы ввели неверные данные.");
                }
                finally
                {
                    if (exit != true)
                        showMenu();
                }
            }
        }
    }
}
