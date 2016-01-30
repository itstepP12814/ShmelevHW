using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ModelToDbExample
{
    class Program
    {
        static void Main(string[] args)
        {
            PhoneStoreModelContainer db = new PhoneStoreModelContainer();

            Cars car1 = new Cars()
            {
                Id = 1,
                Name = "Lada",
                Speed = 180,
            };

            Drivers driver1 = new Drivers()
            {
                Id = 1,
                Name = "Vasya",
                Adress = "Minsk",
                Cars =car1
            };
            Drivers driver2 = new Drivers()
            {
                Id = 2,
                Name = "Petya",
                Adress = "Minsk",
                Cars = car1
            };

            //car1.Drivers.Add(driver1);
           // car1.Drivers.Add(driver2);

            db.CarsSet.Add(car1);
            db.SaveChanges();

            foreach (var car in db.CarsSet)
            {
                Console.WriteLine(car.ToString());
                foreach (var driver in car.Drivers)
                {
                    Console.WriteLine("\t" + driver.Name.ToString());
                }
            }

        }
    }

    public partial class Cars
    {
        public override string ToString()
        {
            return Name.ToString();
        }
    }
}
