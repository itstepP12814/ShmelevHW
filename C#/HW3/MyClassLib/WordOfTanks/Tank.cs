using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
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
            int pauseTime = 10;
            Random rand = new Random();
            ammunition = rand.Next(0, 100);
            System.Threading.Thread.Sleep(pauseTime);
            armor = rand.Next(0, 100);
            System.Threading.Thread.Sleep(pauseTime);
            speed = rand.Next(0, 100);
            System.Threading.Thread.Sleep(pauseTime);
        }
        public override string ToString()
        {
            return name + "\t" + ammunition.ToString() + "\t" + armor.ToString() + "\t" + speed.ToString();
        }

        public static string operator *(Tank lTank, Tank rTank)
        {
            int lPoints = 0;
            int rPoints = 0;
            if (lTank.armor > rTank.armor)
                lPoints++;
            else
                if (lTank.armor < rTank.armor)
                    rPoints++;

            if (lTank.ammunition > rTank.ammunition)
                lPoints++;
            else
                if (lTank.ammunition < rTank.ammunition)
                    rPoints++;

            if (lTank.speed > rTank.speed)
                lPoints++;
            else
                if (lTank.speed < rTank.speed)
                    rPoints++;

            if (lPoints > rPoints) return lTank.name;
            if (lPoints < rPoints) return rTank.name;
            else return "Ничья";
        }
    }
}
