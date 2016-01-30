using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Timers;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Shell;
using Timer = System.Timers.Timer;

namespace WpfApplicationExample
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private Timer timer;
        public double angle = 0;
        public MainWindow()
        {
            InitializeComponent();
            timer = new Timer();
            timer.Elapsed += TimerOnElapsed;
        }

        private void TimerOnElapsed(object sender, ElapsedEventArgs elapsedEventArgs)
        {
        }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            Thread tg = new Thread(EventHandler(lol));
            

        }

        void lol()
        {
            while (true)
            {
                Thread.Sleep(1);
                button.RenderTransform.Value.RotateAt(++angle, button.ActualHeight, button.ActualWidth);
            }
        }
    }
}
