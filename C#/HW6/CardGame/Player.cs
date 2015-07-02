using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CardGame
{
    class Player
    {
        public event EventHandler ILose;
        public event EventHandler IWin;
        public List<Card> cards;
        string name;
        public string Name { get { return name; } set { name = value; } }
        public Player(string name)
        {
            this.name = name;
        }
        public Player(int number)
        {
            this.name = Convert.ToString(number);
        }
        public override string ToString()
        {
            string result = null;
            result += name + ": \n";
            foreach (Card card in cards)
            {
                result += card.ToString() + "\n";
            }
            return result;
        }

        public Card nextCard()
        {
            return cards[0];
        }
        public void removeNextCard()
        {
            cards.RemoveAt(0);
        }
        public void giveCards(List<Card> newCards){
            cards.AddRange(newCards);
        }
        public void CheckWinStatus()
        {
            if (cards.Count >= 36)
            {
                IWin(this, EventArgs.Empty);
            }
            else
            {
                if (cards.Count == 0)
                {
                    ILose(this, EventArgs.Empty);
                }
            }
        }
        public int cardCount { get { return cards.Count; } }
    }
}
