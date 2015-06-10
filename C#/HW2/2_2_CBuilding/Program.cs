//Реализовать  класс  для  описания  здания CBuilding (количество
//этажей,  количество подъездов, количество квартир в здании).  В 
//классе определить конструктор для инициализации полей класса. 
//Создать  методы для вычисления  количества  квартир  в  подъезде,  
//количества  квартир  на  этаже. Проверить работоспособность 
//созданного класса в методе Main().
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_2_CBuilding
{
    class Program
    {
        static void Main(string[] args)
        {
            CBuilding building = new CBuilding(10, 60, 2);
            int inEntrance = building.getAmountOfApartmentsInEntrance();
            int onLevel = building.getAmountOfApartmentsOnLevel();
            Console.WriteLine("Квартир в подъезде: {0}, квартир на этаж: {1}", inEntrance, onLevel);
        }
    }
    class CBuilding{
        int levels;
        int apartmentsAmountInEntrance;
        int apartmentsAmountInBuilding;
        int entrancesAmount;

        public CBuilding(int _levels, int _apartmentsAmountInBuilding, int _entrancesAmount)
        {
            apartmentsAmountInBuilding = _apartmentsAmountInBuilding;
            entrancesAmount = _entrancesAmount;
            levels = _levels;
        }

        public int getAmountOfApartmentsInEntrance()
        {
            return apartmentsAmountInBuilding / entrancesAmount;
        }
        public int getAmountOfApartmentsOnLevel()
        {
            return (apartmentsAmountInBuilding / entrancesAmount) / levels;
        }
    }
}