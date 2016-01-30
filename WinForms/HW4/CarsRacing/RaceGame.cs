using System;
using System.Collections.Generic;
using System.Linq;
using System.Media;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CarsRacing
{
    static class RaceGame {
        public static Form raceForm;
        static Form splashForm;
        public static SoundPlayer IntroPlayer;
        public static SoundPlayer RunningPlayer;
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main() {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            raceForm = new RaceForm();
            splashForm = new SplashScreen();
            IntroPlayer = new SoundPlayer("intro.wav");
            IntroPlayer.Play();
            RunningPlayer = new SoundPlayer("running.wav");
            Application.Run(splashForm);
        }
    }
}
