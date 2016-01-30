using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CarsRacing
{
    public partial class SplashScreen : Form
    {
        public SplashScreen()
        {
            InitializeComponent();
            Opacity = 0;
            Timer timerAppear = new Timer();
            Timer timerDisappear = new Timer();

            timerAppear.Interval = timerDisappear.Interval = 100;
            timerAppear.Tick += (sender, args) => {
                if(Opacity != 1) {
                    Opacity+= 0.05;
                }
                else {
                    timerAppear.Stop();
                    timerDisappear.Start();
                }
            };
            timerDisappear.Tick += (sender, args) => {
                if(Opacity != 0) {
                    Opacity-=0.05;
                }
                else {
                    timerDisappear.Stop();
                    RaceGame.raceForm.Show();
                    Hide();
                }
            };

            timerAppear.Start();
        }
    }
}
