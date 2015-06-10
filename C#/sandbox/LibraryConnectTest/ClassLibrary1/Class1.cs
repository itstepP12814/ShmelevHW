using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyClassLib
{
    public class Tank
    {
        string name;
        int ammunition;
        int armor;
        int speed;

        public Tank(string tankModel)
        {
            if (tankModel.ToLower() == "pantera")
            {
                name = "Pantera";
            }
            else
            {
                if (tankModel.ToLower() == "t-34" || tankModel.ToLower() == "t34")
                {
                    name = "T-34";
                }
            }
            Random rand = new Random();
            ammunition = rand.Next(0, 100);
            armor = rand.Next(0, 100);
            speed = rand.Next(0, 100);
        }
        public override string ToString()
        {
            return name + "\t" + ammunition.ToString() + "\t" + armor.ToString() + "\t" + speed.ToString();
        }
    }
}
