using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace ATM
{
    namespace Banks
    {
        public class Bank
        {
            Accounts.Account[] database;
            int accountAmount;
            int maxCount;
            int bankPrivateKey;
            int pwdLength;
            int maxPwdAttempts;
            string name;
            public Bank(string bankName)
            {
                maxCount = 200;
                name = bankName;
                database = new Accounts.Account[maxCount];
                accountAmount = 0;
                Random rand = new Random();
                //Генерируем приватный ключ для операций между банком и счетом
                bankPrivateKey = rand.Next(1000000, 9999999);
                pwdLength = 8;
                maxPwdAttempts = 3; //Пароль можно ввести максимум 3 раза
            }
            public string openAccount(string clientName)
            {
                try
                {
                    ++accountAmount;
                    if ((accountAmount - 1) < maxCount)
                    {
                        //Устанавливаем счету приватный ключ банка и создаем счет и пароль
                        string password = CreateRandomPassword(pwdLength);
                        database[accountAmount - 1] = new Accounts.Account(clientName, bankPrivateKey, password);
                        return "Номер счета: " + database[accountAmount - 1].AccountNumber + "\nВаш пароль: " + password;
                    }
                    else throw new IndexOutOfRangeException();
                }
                catch (IndexOutOfRangeException)
                {
                    Console.WriteLine("Ошибка: В банке не может быть более {0} счетов.", maxCount);
                }
                catch (ArgumentNullException)
                {
                    Console.WriteLine("Ошибка: Не удалось создать пароль.");
                    return null;
                }
                catch (ApplicationException)
                {
                    Console.WriteLine("Ошибка: Не удалось создать пароль.");
                }
                return null;
            }

            private Accounts.Account searchAccount(string owner)
            {
                    for (int i = 0; i < database.Length; ++i)
                    {
                        if (database[i].Owner == owner)
                        {
                            if (database[i].PwdEnterAttempt < maxPwdAttempts)
                                return database[i];
                            else
                                throw new UnauthorizedAccessException();
                        }
                    }
                return null;
            }

            public string viewAccount(string owner, string password)
            {
                Accounts.Account needleAcc = searchAccount(owner);
                if (needleAcc != null)
                    return needleAcc.ToString(password, bankPrivateKey);
                else
                    throw new MemberAccessException();
            }

            public string addMoney(string owner, string password, decimal moneyToAdd)
            {
                Accounts.Account needleAcc = searchAccount(owner);
                if (needleAcc != null)
                    return needleAcc.addMoney(password, bankPrivateKey, moneyToAdd);
                else
                    throw new MemberAccessException();
            }

            internal string getCash(string owner, string password, decimal sumToGet)
            {
                Accounts.Account needleAcc = searchAccount(owner);
                if (needleAcc != null)
                    return needleAcc.getMoney(password, bankPrivateKey, sumToGet);
                else
                    throw new MemberAccessException();
            }
            private static string CreateRandomPassword(int passwordLength)
            {
                string allowedChars = "abcdefghijkmnopqrstuvwxyzABCDEFGHJKLMNOPQRSTUVWXYZ0123456789!@$?_-";
                char[] chars = new char[passwordLength];
                Random rd = new Random();

                for (int i = 0; i < passwordLength; i++)
                {
                    chars[i] = allowedChars[rd.Next(0, allowedChars.Length)];
                }

                return new string(chars);
            }
        }
    }
}
