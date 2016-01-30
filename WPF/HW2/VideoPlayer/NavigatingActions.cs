using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

namespace VideoPlayer
{
    public static class MainFormAction {
        public static RoutedUICommand togglePlayListCommand;
        public static RoutedUICommand TogglePlayListCommand { get { return togglePlayListCommand; } }

        static MainFormAction() {
            togglePlayListCommand = new RoutedUICommand("Свернуть/развернуть плейлист", "TogglePlayList", typeof(MainFormAction));
        }

        private static void TogglePlayList(ListBox playList)
        {
            if(playList.Visibility != Visibility.Collapsed)
                playList.Visibility = Visibility.Collapsed;
            else
                playList.Visibility = Visibility.Visible;
        }
    }
}
