using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HouseBuilding
{
    public interface IBuilder
    {
        IPart BuildNext(House curHouse);
        House.Part CurPart { get; }
    }
    class Team
    {
        IBuilder[] teamStack;
        TeamLeader teamLeader;
        public Team(TeamLeader teamLeader, params IBuilder[] workers)
        {
            teamStack = new Builder[workers.Length];
            teamStack = workers;
            this.teamLeader = teamLeader;
        }
        
        public bool Build(House curHouse)
        {
            for (int i = 0, j=0; curHouse.Length != 0; ++i, ++j)
            {
                teamStack[j].BuildNext(curHouse);
                System.Threading.Thread.Sleep(500);
                teamLeader.CheckProgress(curHouse);
                if (j == teamStack.Length - 1)
                    j = 0;
            }
            return true;
        }
    }

    class Builder : IBuilder
    {
        House.Part curPart;
        public House.Part CurPart { get { return curPart; } }
        public IPart BuildNext(House targetHouse) //Метод строительства
        {
            curPart = targetHouse.getNextBuildAction();

            switch ((int)curPart)
            {
                case (int)House.Part.BASEMENT:
                    targetHouse.basements[targetHouse.BasementCount-1] = new Basement(20, 20);
                    targetHouse.BasementCount--;
                    break;
                case (int)House.Part.DOOR:
                    targetHouse.doors[targetHouse.DoorsCount-1] = new Door(2, 1);
                    targetHouse.DoorsCount--;
                    break;
                case (int)House.Part.ROOF:
                    targetHouse.roofs[targetHouse.RoofsCount-1] = new Roof(20, 20);
                    targetHouse.RoofsCount--;
                    break;
                case (int)House.Part.WALL:
                    targetHouse.walls[targetHouse.WallsCount-1] = new Wall(2, 20);
                    targetHouse.WallsCount--;
                    break;
                case (int)House.Part.WINDOW:
                    targetHouse.windows[targetHouse.WindowCount-1] = new Window(1, 1);
                    targetHouse.WindowCount--;
                    break;
                default:
                    break;
            }
            return null;
        }
    }

    class TeamLeader : IBuilder
    {

        House.Part curPart;
        public House.Part CurPart { get { return curPart; } }
        public IPart BuildNext(House curHouse)
        {
            Console.WriteLine("Строить я ему буду... Я ж тут прораб!");
            return null;
        }
        public void CheckProgress(House curHouse)
        {
            Console.WriteLine("\nНа данный момент:");
            if (curHouse.BasementCount == 0)
                Console.WriteLine("\tПостроен фундамент");
            if (curHouse.WallsCount == 0)
                Console.WriteLine("\tВозведены стены");
            if (curHouse.WindowCount == 0)
                Console.WriteLine("\tУстановлены окна");
            if (curHouse.DoorsCount == 0)
                Console.WriteLine("\tУстановлены двери");
            if (curHouse.RoofsCount == 0)
                Console.WriteLine("\tУстановлены все элементы крыши");

            if (curHouse.BasementCount == 0 && curHouse.WallsCount == 0 && curHouse.WindowCount == 0 && curHouse.DoorsCount == 0 && curHouse.RoofsCount == 0)
            {
                Console.WriteLine("\tСтроительство дома завершено. Всем разойтись!");
            }
            else
            {
                if (curHouse.BasementCount != 0 && curHouse.WallsCount != 0 && curHouse.WindowCount != 0 && curHouse.DoorsCount != 0 && curHouse.RoofsCount != 0)
                    Console.WriteLine("\tЕщё ничего не построили, тунеядцы!");
            }
        }
    }
}
