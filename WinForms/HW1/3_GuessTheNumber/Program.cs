using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;

namespace _3_GuessTheNumber {
    internal static class Program {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        private static void Main() {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Game game;
            while(true) {
                game = new Game();
                bool gameResult = game.TryAgain();
                if(gameResult) {
                    DialogResult againResult = MessageBox.Show("Фух... Нам понадобилось " + game.AttemptCount + " попыток, чтобы догадаться. " +
                        "\nХотите сыграть ещё?", "Победа", MessageBoxButtons.YesNo);
                    if(againResult == DialogResult.Yes) {
                        continue;
                    }
                    if(againResult == DialogResult.No) {
                        break;
                        Application.Exit();
                    }
                }
                else {
                    MessageBox.Show("Мы старались как могли...", "Неудача", MessageBoxButtons.OK);
                    break;
                }
            }
        }
    }

    internal class Game {
        private int lowMargin;
        private int maxMargin;

        public int AttemptCount
        {
            get { return attemptCount; }
        }

        private int attemptCount;
        private Random rand;
        private List<int> formerNumbers;

        public Game() {
            lowMargin = 1;
            maxMargin = 3;
            attemptCount = 0;
            string greeting = "Загадайте число от " + lowMargin + " до " + maxMargin;
            formerNumbers = new List<int>((maxMargin - lowMargin)+1);
            MessageBox.Show(greeting, "Отгадывальщик чисел 3000", MessageBoxButtons.OK);
            rand = new Random();
        }

        public Game(int minMargin, int maxMargin) : base() {
            this.lowMargin = minMargin;
            this.maxMargin = maxMargin;
        }

        public bool TryAgain() {
            while (formerNumbers.Count < formerNumbers.Capacity) {
                int newNumber = rand.Next(lowMargin, maxMargin+1);
                if(!FindNumber(formerNumbers, newNumber)) {
                    attemptCount++;
                    DialogResult result =
                        MessageBox.Show("Загаданное вами число " + newNumber + "?", "Ответ", MessageBoxButtons.YesNoCancel);
                    if(result == DialogResult.Yes) {
                        return true;
                    }
                    if(result == DialogResult.No) {
                        formerNumbers.Add(newNumber);
                    }
                    if(result == DialogResult.Cancel) {
                        return false;
                    }
                }
            }
            return false;
        }

        private bool FindNumber(List<int> array, int newNumber) {
            foreach(int num in array) {
                if (num == newNumber) return true;
            }
            return false;
        }
    }
}
