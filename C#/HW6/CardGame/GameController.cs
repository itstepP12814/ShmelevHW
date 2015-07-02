using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CardGame
{
    class GameController
    {
        Deck deck;
        List<Card> desk;
        List<Player> players;
        bool gameOver;
        delegate void Checker();
        Checker winChecker;
        public bool GameOver { get { return gameOver; } }
        public GameController(int numberOfPlayers)
        {
            players = new List<Player>();
            if (players.Count <= 6)
            {
                gameOver = false;
                deck = new Deck();
                for (int i = 0; i < numberOfPlayers; ++i)
                {
                    Player newPlayer = new Player(i);
                    newPlayer.IWin += new EventHandler(playerWin);
                    newPlayer.ILose += new EventHandler(playerLose);
                    winChecker += new Checker(newPlayer.CheckWinStatus);
                    players.Add(newPlayer);
                }
                deck.Shake();
                giveCardsToPlayers();
            }
            else
                throw new ApplicationException("Не более шести игроков.");
        }
        void giveCardsToPlayers()
        {
            int divNum = deck.Length / players.Count;
            for (int i = 0; i < players.Count; ++i)
            {
                players[i].cards = new List<Card>();
                for (int j = 0; j < divNum; ++j)
                {
                    players[i].cards.Add(deck.cards[j]);
                }
                deck.cards.RemoveRange(0, divNum);
            }
        }

        internal void NextStep()
        {
            //Кладем карты на стол
            desk = new List<Card>();
            Console.WriteLine("\n\nНачался тур:");
            foreach (Player player in players)
            {
                Console.WriteLine(player.Name + ": карт - " + player.cardCount + ", походил: " + player.nextCard().Type.ToString());
                desk.Add(player.nextCard());
                player.removeNextCard();
            }
            //Проверяем чья карта старше
            int winNumber = 0;
            int maxTypeNumber = 0;
            for (int i = desk.Count-1; i >= 0; --i)
            {
                if ((int)desk[i].Type > maxTypeNumber){
                    winNumber = i;
                    maxTypeNumber = (int)desk[i].Type;
                }
            }
            Console.WriteLine("Старшая карта: " + desk[winNumber].Type.ToString());
            players[winNumber].giveCards(desk); //Выйгравший в туре забирает все карты со стола
            
            //Смотрим, выйграл ли кто-нибудь
            winChecker();
        }

        void playerWin(Object sender, EventArgs e)
        {
            Player player = (Player)sender;
            gameOver = true;
            Console.WriteLine(player.Name + " выйграл! Игра окончена.");
        }
        void playerLose(Object sender, EventArgs e)
        {
            Player player = (Player)sender;
            //players.Remove(player);
            Console.WriteLine("Игрок " + player.Name + " выбыл.");
        }
    }
}
