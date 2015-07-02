using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HouseBuilding
{
    public interface IPart
    {
        void connectWithAnotherPart(IPart anotherPart);
        int Height { get; set; }
        int Width { get; set; }
        IPart PartLink { get; set; }//ссылка на другой элемент дома
    }
    public class House
    {

        int[] elementsCountArr;
        
        public Basement[] basements;
        public Wall[] walls;
        public Window[] windows;
        public Door[] doors;
        public Roof[] roofs;

        public int BasementCount { get { return elementsCountArr[(int)Part.BASEMENT]; } set { elementsCountArr[(int)Part.BASEMENT] = value; } }
        public int WallsCount { get { return elementsCountArr[(int)Part.WALL]; } set { elementsCountArr[(int)Part.WALL] = value; } }
        public int DoorsCount { get { return elementsCountArr[(int)Part.DOOR]; } set { elementsCountArr[(int)Part.DOOR] = value; } }
        public int WindowCount { get { return elementsCountArr[(int)Part.WINDOW]; } set { elementsCountArr[(int)Part.WINDOW] = value; } }
        public int RoofsCount { get { return elementsCountArr[(int)Part.ROOF]; } set { elementsCountArr[(int)Part.ROOF] = value; } }
        public int Length { get { return elementsCountArr.Sum(); } }
        public enum Part { None, BASEMENT, WALL, WINDOW, DOOR, ROOF }; //Идентификаторы для перечисления (ими определяется порядок строительства)
        
        public House(int basementsCount, int windowsCount, int doorsCount, int roofsCount, int wallsCount)
        {
            elementsCountArr = new int[Enum.GetNames(typeof(Part)).Length]; //Создаем массив размером с количество элементов перечисления
            //План строительства
            //Определенному типу элемента (который стоит в определенном перечислением порядке)
            //соответсвует непостроенное количество элементов
            elementsCountArr[(int)Part.BASEMENT] = basementsCount;
            elementsCountArr[(int)Part.WINDOW] = windowsCount;
            elementsCountArr[(int)Part.DOOR] = doorsCount;
            elementsCountArr[(int)Part.ROOF] = roofsCount;
            elementsCountArr[(int)Part.WALL]  = wallsCount;

            basements = new Basement[basementsCount];
            walls = new Wall[wallsCount];
            windows = new Window[windowsCount];
            doors = new Door[doorsCount];
            roofs = new Roof[roofsCount];
        }

        public Part getNextBuildAction()
        {
            for(int i=(int)Part.BASEMENT; i<elementsCountArr.Length; ++i)
            {
                if (elementsCountArr[i] != 0)
                    return (Part)i; //Возвращаем номер части дома, которую следует строить
            }
            return Part.None;
        }
    }

    public class Basement : IPart
    {
        int height;
        int width;
        IPart partLink;
        public Basement(int heigth, int width)
        {
            this.height = heigth;
            this.width = width;
        }

        public void connectWithAnotherPart(IPart anotherPart)
        {
            PartLink = anotherPart;
        }

        public int Height
        {
            get { return height; }
            set { height = value; }
        }

        public int Width
        {
            get { return height; }
            set { height = value; }
        }

        public IPart PartLink
        {
            get { return partLink; }
            set { partLink = value; }
        }
    }

    public class Wall : IPart
    {
        int height;
        int width;
        IPart partLink;
        public Wall(int heigth, int width)
        {
            this.height = heigth;
            this.width = width;
        }

        public void connectWithAnotherPart(IPart anotherPart)
        {
            PartLink = anotherPart;
        }

        public int Height
        {
            get { return height; }
            set { height = value; }
        }

        public int Width
        {
            get { return height; }
            set { height = value; }
        }

        public IPart PartLink
        {
            get { return partLink; }
            set { partLink = value; }
        }
    }

    public class Door : IPart
    {
        int height;
        int width;
        IPart partLink;
        public Door(int heigth, int width)
        {
            this.height = heigth;
            this.width = width;
        }

        public void connectWithAnotherPart(IPart anotherPart)
        {
            PartLink = anotherPart;
        }

        public int Height
        {
            get { return height; }
            set { height = value; }
        }

        public int Width
        {
            get { return height; }
            set { height = value; }
        }

        public IPart PartLink
        {
            get { return partLink; }
            set { partLink = value; }
        }
    }

    public class Window : IPart
    {
        int height;
        int width;
        IPart partLink;
        public Window(int heigth, int width)
        {
            this.height = heigth;
            this.width = width;
        }

        public void connectWithAnotherPart(IPart anotherPart)
        {
            PartLink = anotherPart;
        }

        public int Height
        {
            get { return height; }
            set { height = value; }
        }

        public int Width
        {
            get { return height; }
            set { height = value; }
        }

        public IPart PartLink
        {
            get { return partLink; }
            set { partLink = value; }
        }
    }
    public class Roof : IPart
    {
        int height;
        int width;
        IPart partLink;
        public Roof(int heigth, int width)
        {
            this.height = heigth;
            this.width = width;
        }

        public void connectWithAnotherPart(IPart anotherPart)
        {
            PartLink = anotherPart;
        }

        public int Height
        {
            get { return height; }
            set { height = value; }
        }

        public int Width
        {
            get { return height; }
            set { height = value; }
        }

        public IPart PartLink
        {
            get { return partLink; }
            set { partLink = value; }
        }
    }

}
