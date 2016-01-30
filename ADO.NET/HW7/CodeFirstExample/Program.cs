using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CodeFirstExample.Context;
using CodeFirstExample.Entities;

namespace CodeFirstExample
{
    class Program
    {
        static void Main(string[] args)
        {
            ComputersDB db = new ComputersDB();
            Device device1 = new Device()
            {
                Model = "Athlon 4.5",
                Price = 4500,
                Manufacturer = "AMD"
            };
            Device device2 = new Device()
            {
                Model = "Sempron 4.5",
                Price = 1500,
                Manufacturer = "AMD"
            };

            User user = new User()
            {
                Name = "Kostya",
                Date = DateTime.Now,
                Devices = new List<Device>()
            };
            user.Devices.AddRange(new []{ device1, device2});
            db.Users.Add(user);
            db.SaveChanges();

            foreach (var device in db.Devices)
            {
                Console.WriteLine("Name: {0}, Price: {1}, Manuf: {2}", device.Model, device.Price, device.Manufacturer);
            }
            Console.ReadLine();
        }
    }
}
