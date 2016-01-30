using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ConsoleApplicationMonitorLockApp
{
   class Program
   {
      static void Main(string[] args)
      {
         Thread thread1 = new Thread(() =>
         {
            Console.WriteLine("Unlock thread");
         });

         Thread thread2 = new Thread(() => {
            MonBlocker monBlocker = new MonBlocker();
            lock (monBlocker)
            {
               Console.WriteLine("Lock thread");
               monBlocker.WaitResponse(thread1);
            }
         });
            thread1.Start();
         thread2.Start();
         Console.ReadLine();
      }

      public class MonBlocker
      {
         public void WaitResponse(Thread thread)
         {
            lock (this) {
               Console.WriteLine("Waiting");
               System.Threading.Thread.Sleep(5000);
            }
         }
      }
   }
}
