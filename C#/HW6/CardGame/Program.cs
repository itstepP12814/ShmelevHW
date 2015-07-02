using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CardGame
{
    class Program
    {
        static void Main(string[] args)
        {
            GameController game = new GameController(2);
            while (game.GameOver != true)
            {
                game.NextStep();
            }
        }
    }
}
