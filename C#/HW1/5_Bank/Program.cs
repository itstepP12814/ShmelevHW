using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _5_Bank
{
    class Program
    {
        static void Main(string[] args)
        {
            decimal deposit = 1000;
            double mounth_percent;
            int term = 0;
            Console.WriteLine("Какой процент по вкладу?");
            mounth_percent = (Convert.ToDouble(Console.ReadLine()))/100;
            while (deposit <= 1100M)
            {
                deposit = (deposit * (decimal)mounth_percent) + deposit;
                ++term;
            }
            Console.WriteLine(term);
        }
    }
}
