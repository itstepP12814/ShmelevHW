using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CardGame
{
    enum cardType{ Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};
    class Card
    {
        cardType type;
        public Card(cardType type){
            this.type = type;
        }
        public cardType Type { get { return type; } }
        public static bool operator >(Card first, Card second)
        {
            if (first.type > second.type)
                return true;
            else
                return false;
        }
        public static bool operator <(Card first, Card second)
        {
            if (first.type < second.type)
                return true;
            else
                return false;
        }
    }

    class Deck
    {
        public List<Card> cards;
        public int Length { get { return cards.Count; } }
        public Deck()
        {
            cards = new List<Card>();
            for (int i = 0; i < 4; ++i) //Четыре набора из неповторяющихся карт составляют колоду
            {
                for (int typeOfCard = (int)cardType.Six; typeOfCard < (int)cardType.Ace + 1; ++typeOfCard)
                {
                    cards.Add(new Card((cardType)typeOfCard));
                }
            }
        }
        public override string ToString()
        {
            string result = null;
            foreach (Card card in cards)
            {
                result += card.Type.ToString() + "\n";
            }
            return result;
        }

        public void Shake()
        {
            var rand = new Random();
            for (int i = cards.Count - 1; i >= 0; i--)
            {
                int j = rand.Next(i);
                var temp = cards[i];
                cards[i] = cards[j];
                cards[j] = temp;
            }
        }
    }
}
