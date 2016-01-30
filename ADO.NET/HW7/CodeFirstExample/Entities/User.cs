using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeFirstExample.Entities
{
    class User
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public string LastName { get; set; }
        //? - позволяет ссылочному типу быть null
        public DateTime? Date { get; set; }

        //Навигационное свойство
        public virtual List<Device> Devices { get; set; }
    }
}
