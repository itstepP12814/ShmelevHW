using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeFirstExample.Entities
{
    class Device
    {
        public int Id { get; set; }
        public int Price { get; set; }
        public string Model { get; set; }
        public string Manufacturer { get; set; }
        //Навигационное свойство
        public virtual User User { get; set; }
    }
}
