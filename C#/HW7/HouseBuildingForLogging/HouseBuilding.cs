using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LoggerLib;
namespace HouseBuilding
{
    class MainBlock
    {
        public static Logger logger = new Logger("logfile.txt", "userLoggerCongif.ini"); 
        static void Main(string[] args)
        {
            House house1 = new House(1, 4, 1, 1, 4);
            Team goodTeam = new Team(new TeamLeader(), new Builder(), new Builder(), new Builder(), new Builder());
            goodTeam.Build(house1);
        }
    }
}
