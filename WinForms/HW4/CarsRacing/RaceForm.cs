using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.Odbc;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.VisualStyles;

namespace CarsRacing
{
    public partial class RaceForm : Form {

        private List<Thread> threads;
        private List<Button> btns;
        Random rand = new Random();
        private event EventHandler Finished;
        private delegate void Updating(Point point, int _index);
        private delegate void Watching(int leadId);

        private delegate void Changer();

        private Thread watcherThread;
        private bool Paused;
        private bool Started;
        private bool OnceFinished;
        private bool GameOver;
        public RaceForm()
        {
            InitializeComponent();

            StartNewGame();

            Finished += (sender, args) => {
                if (!OnceFinished)
                {
                    OnceFinished = true;
                    GameOver = true;
                    FinishedArgs arguments = (FinishedArgs)args;
                    MessageBox.Show("Победитель " + arguments.Name);
                    Invoke(new Changer(() => {
                        button6.Text = "Начать заново";
                        button7.Enabled = false;
                        RaceGame.RunningPlayer.Stop();
                        RaceGame.IntroPlayer.Play();
                    }));
                }
            };
        }

        void Go(object Index) {
            int index = (int)Index;
            int Xpos = btns[index].Location.X;
            int Ypos = btns[index].Location.Y;

            while (btns[index].Right < pictureBox2.Left)
            {
                Xpos+= rand.Next(20);
                Point point = new Point(Xpos, Ypos);
                Invoke(new Updating(Update), point, index);
                Thread.Sleep(400);
            }
            Finished(this, new FinishedArgs(btns[index].Text));
        }

        private void Update(Point point, int index) {
            btns[index].Location = point;
        }

        private void RunWatch()
        {
            while(!GameOver) {
                int leadId = -1;
                int maxPos = 0;
                //Находим номер лидера
                for(int i = 0; i < btns.Count; ++i) {
                    if(btns[i].Location.X > maxPos) {
                        maxPos = btns[i].Location.X;
                        leadId = i;
                    }
                }
                if(leadId != -1) Invoke(new Watching(ChangeColor), leadId);
                Thread.Sleep(100);
            }
        }

        void ChangeColor(int leadId) {

            btns[leadId].BackColor = Color.Gold;
            btns[leadId].ForeColor = Color.Azure;
            btns[leadId].Refresh();
            for (int i=0; i<btns.Count;++i)
            {
                if(i != leadId) {
                    btns[i].BackColor = Color.LightGray;
                    btns[i].ForeColor = Color.Black;
                    btns[i].Refresh();
                }
            }
        }

        private void button6_Click(object sender, EventArgs e) {
            if(GameOver) StartNewGame();
            else {
                button7.Enabled = true;
                if (!Started) {
                    //Первый старт
                    RaceGame.IntroPlayer.Stop();
                    RaceGame.RunningPlayer.Play();
                    Started = true;
                    Paused = false;
                    button6.Text = "Приостановить";
                    for(int i = 0; i < threads.Count; ++i)
                       //if(threads[i].ThreadState != ThreadState.Running 
                           // && threads[i].ThreadState != ThreadState.Running)
                                threads[i].Start(i);
                    watcherThread.Start();
                }
                else {
                    if(!Paused) {
                        //Приостанавливаем
                        Paused = true;
                        button6.Text = "Продолжить";
                        for(int i = 0; i < threads.Count; ++i)
                            //if(threads[i].ThreadState == ThreadState.Running)
                            threads[i].Suspend();
                    }
                    else {
                        //Возобновляем
                        Paused = false;
                        button6.Text = "Приостановить";
                        for(int i = 0; i < threads.Count; ++i)
                            //if(threads[i].ThreadState == ThreadState.Running)
                            threads[i].Resume();
                    }
                }
            }
        }

        private void RaceForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            foreach(var thread in threads) {
                    thread.Abort();
            }
            Application.Exit();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            foreach (var thread in threads)
            {
                if(thread.ThreadState != ThreadState.Suspended)
                    thread.Abort();
                else {
                    thread.Resume();
                    thread.Abort();
                    //Как правильно прерывать приостановленные потоки? 
                }
                GameOver = true;
                button6.Text = "Начать заново";
            }
        }

        void StartNewGame()
        {
            Paused = true;
            Started = false;
            OnceFinished = false;
            GameOver = false;
            btns = new List<Button>() {
                button1,
                button2,
                button3,
                button4,
                button5
            };
            threads = new List<Thread>();

            //Поток для отслеживания лидирующего автомобиля
            watcherThread = new Thread(RunWatch);

            for (int i = 0; i < btns.Count; ++i)
            {
                threads.Add(new Thread(Go));
                int xPos = pictureBox1.Left - btns[i].Width;
                int yPos = (((i + 1)*35) + (pictureBox1.Height / btns.Count)-50);
                btns[i].Location = new Point(xPos, yPos);
            }
            button6.Text = "Начать гонку";
            button7.Enabled = false;
            foreach (Control control in Controls) {
                control.Refresh();
            }
        }

    }

    public class FinishedArgs : EventArgs
    {
        public string Name { get; set; }
        public FinishedArgs(string name) {
            Name = name;
        }
    }
}
