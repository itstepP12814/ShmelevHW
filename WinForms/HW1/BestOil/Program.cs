using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BestOil
{
    public static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        private static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new MainForm());
        }
    }

    public struct Gasoline
    {
        public string Mark { get; set; }
        public decimal Cost { get; set; }

        public Gasoline(string mark, decimal cost)
        {
            Mark = mark;
            Cost = cost;
        }

        public override string ToString() {
            return Mark;
        }
    }

    public class GasStation
    {
        public List<Gasoline> Marks { get; set; }
        public ComputeType ComputeBy { get; set; }
        public decimal LocalSumm { get; set; }

        public enum ComputeType
        {
            value,
            cost
        };

        public GasStation()
        {
            Marks = new List<Gasoline>() {
                new Gasoline("АИ-95", 11900),
                new Gasoline("АИ-92", 11100),
                new Gasoline("ДТ Евро 5", 12300),
                new Gasoline("Газ ПБА", 6200),
                new Gasoline("АИ-98", 13000),
                new Gasoline("Брендовое топливо АИ-92", 11100)
            };
        }

        public decimal GetValueByCost(decimal availableMoney, Gasoline mark)
        {
            return availableMoney / mark.Cost;
        }

        public decimal GetCostByValue(decimal needleValue, Gasoline mark)
        {
            return needleValue * mark.Cost;
        }
    }

    public class Food
    {
        public string Name { get; set; }
        public decimal Cost { get; set; }
        public Food(string name, decimal cost) {
            Name = name;
            Cost = cost;
        }
    }

    public class MiniMarket {
        public List<Food> Food { get; set; }
        public decimal LocalSumm { get; set; }

        public MiniMarket() {
            Food = new List<Food>() {
                new Food("Хот-дог", 25000),
                new Food("Кока-кола", 18000),
                new Food("Гамбургер", 28000),
                new Food("Чизбургер", 32000)
            };
        }

        public decimal GetCostByAmount(int amount, Food goods) {
            return amount * goods.Cost;
        }
    }
}
