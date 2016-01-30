using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CodeFirstExample.Entities;

namespace CodeFirstExample.Context
{
    class ComputersDB : DbContext
    {
        public ComputersDB() : base()
        {
            
        }
        public DbSet<User> Users { get; set; }
        public DbSet<Device> Devices { get; set; }
    }
}
