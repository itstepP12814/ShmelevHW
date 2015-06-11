using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace ATM
{
    namespace Accounts
    {
        class Account
        {
            decimal money;
            int accountNumber;
            string owner;
            string password;
            int bankPrivateKey;
            int pwdEnterAttempt;

            public int AccountNumber
            {
                //Номер счета можно только читать
                get{return accountNumber;}
            }

            public string Owner
            {
                get { return owner; }
            }
            
            public Account(string ownerName, int bankKey, string pwd)
            {
                Random rand = new Random();
                accountNumber = rand.Next(100000000, 999999999);
                System.Threading.Thread.Sleep(10);
                owner = ownerName;
                bankPrivateKey = bankKey;
                password = pwd;
            }

            public string addMoney(string userPwd, int bankKey, decimal sumToAdd)
            {
                if (password == userPwd && bankKey == bankPrivateKey)
                {
                    pwdEnterAttempt = 0;
                    money += sumToAdd;
                    return ToString(userPwd, bankKey);
                }
                else
                {
                    pwdEnterAttempt++;
                    throw new ApplicationException();
                }
            }
            internal string getMoney(string userPwd, int bankKey, decimal sumToGet)
            {
                if (password == userPwd && bankKey == bankPrivateKey)
                {
                    pwdEnterAttempt = 0;
                    if (money >= sumToGet)
                    {
                        money -= sumToGet;
                        return ToString(userPwd, bankKey);
                    }
                    else
                        //Недостаточно средств
                        throw new InsufficientMemoryException();
                }
                else
                {
                    pwdEnterAttempt++;
                    throw new ApplicationException();
                }
            }
            public string ToString(string userPwd, int bankKey)
            {
                if (password == userPwd && bankKey == bankPrivateKey)
                {
                    pwdEnterAttempt = 0;
                    return owner + "\t" + accountNumber + "\t" + money + "\t";
                }
                else
                {
                    pwdEnterAttempt++;
                    throw new ApplicationException();
                }
            }

            public int PwdEnterAttempt 
            {
                get { return pwdEnterAttempt; }
            }
        }
    }
}
