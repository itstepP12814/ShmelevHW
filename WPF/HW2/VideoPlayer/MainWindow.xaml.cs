using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Reflection.Emit;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Threading;
using Microsoft.Win32;
using MusicPlayer;

namespace VideoPlayer
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {

        private readonly List<PlayListItem> _PlayListNames = new List<PlayListItem>();
        private DispatcherTimer _PositionTimer;
        private readonly DispatcherTimer _DoubleClickTimer = new DispatcherTimer();
        private bool _Fullscreen;

        [DllImport("user32.dll")]
        private static extern uint GetDoubleClickTime();


        public MainWindow()
        {
            InitializeComponent();
            playerControl.LoadedBehavior = MediaState.Manual;
            playerControl.UnloadedBehavior = MediaState.Manual;
            PlayListControl.ItemsSource = _PlayListNames;
            PlayListControl.MouseDoubleClick += PlayListControlOnSelectionChanged;

            _DoubleClickTimer.Interval = TimeSpan.FromMilliseconds(GetDoubleClickTime());
            _DoubleClickTimer.Tick += (s, e) => _DoubleClickTimer.Stop();
        }

        private void Play_OnExecuted(object sender, EventArgs e)
        {
            playerControl.Play();
            _PositionTimer?.Start();
        }
        private void Pause_OnExecuted(object sender, EventArgs e)
        {
            playerControl.Pause();
            _PositionTimer?.Stop();
        }
        private void Open_OnExecuted(object sender, EventArgs e)
        {
            OpenFileDialog opf = new OpenFileDialog();
            opf.ShowDialog();
            OpenFile(opf.FileName);
        }

        private void AddBtn_AddToPlayListAndOpen(object sender, EventArgs e) {
            OpenFileDialog opf = new OpenFileDialog();
            opf.ShowDialog();
            _PlayListNames.Add(new PlayListItem(opf.SafeFileName, opf.FileName));
            OpenFile(opf.FileName);
        }

        private void MediaElement_Tick(object sender, EventArgs e) {
            TimeSpan actualTimeSpan = playerControl.Position;
            DateTime actualDateTime = DateTime.MinValue;
            DateTime commonDateTime = DateTime.MinValue;
            actualDateTime += actualTimeSpan;
            actualDuration.Content = $"{actualDateTime:H:mm:ss}";
            
            TimeSpan commonTimeSpan = TimeSpan.Zero;
            if(playerControl.NaturalDuration.HasTimeSpan) {
                commonTimeSpan = playerControl.NaturalDuration.TimeSpan;
                commonDateTime += commonTimeSpan;
                commonDuration.Content = $"{commonDateTime:HH:mm:ss}";
            }
            if (playerControl.NaturalDuration.HasTimeSpan)
                videoSlider.Value =(int)videoSlider.Maximum * playerControl.Position.TotalSeconds / playerControl.NaturalDuration.TimeSpan.TotalSeconds;
        }

        private void OpenFile(string path)
        {
            if (!string.IsNullOrEmpty(path))
            {
                _PositionTimer = new DispatcherTimer();
                _PositionTimer.Interval = TimeSpan.FromSeconds(1);
                _PositionTimer.Tick += MediaElement_Tick;
                _PositionTimer.Start();


                playerControl.Source = new Uri(path);
                PlayListControl.ItemsSource = null;
                PlayListControl.ItemsSource = _PlayListNames;
                playerControl.Play();
            }
        }

        private void PlayListControlOnSelectionChanged(object sender, EventArgs e)
        {
            ListBox item = sender as ListBox;
            if (item != null)
            {
                if (item.SelectedItems.Count != 0)
                {
                    PlayListItem videoItem = item.SelectedItems[0] as PlayListItem;
                    if (videoItem != null) OpenFile(videoItem.FullPath);
                }
            }

        }

        private void ChangeVolume_OnExecuted(object sender, EventArgs e)
        {
            Slider slider = sender as Slider;
            playerControl.Volume = (double)slider.Value / 10;
        }

        private void videoSlider_PreviewMouseKeyUp(object sender, EventArgs e)
        {
            Slider slider = sender as Slider;
            if (playerControl.NaturalDuration.HasTimeSpan)
            {
                TimeSpan newPosition = TimeSpan.FromSeconds((slider.Value * playerControl.NaturalDuration.TimeSpan.TotalSeconds) / Convert.ToInt32(slider.Maximum));
                playerControl.Position = newPosition;
            }
            MediaElement_Tick(sender, e);
        }

        private void UIElement_Collapse(object sender, EventArgs e)
        {
            MainGrid.ColumnDefinitions[0].Width = new GridLength(1, GridUnitType.Star);
            MainGrid.ColumnDefinitions[1].Width = GridLength.Auto;
        }

        private void UIElement_Expand(object sender, EventArgs e)
        {
            MainGrid.ColumnDefinitions[0].Width = new GridLength(0.7, GridUnitType.Star);
            MainGrid.ColumnDefinitions[1].Width = new GridLength(0.3, GridUnitType.Star);
        }

        private void MediaElement_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            if (!_DoubleClickTimer.IsEnabled)
            {
                _DoubleClickTimer.Start();
            }
            else
            {
                if (!_Fullscreen)
                {
                    this.WindowStyle = WindowStyle.None;
                    this.WindowState = WindowState.Maximized;
                    MenuDock.Visibility = Visibility.Collapsed;
                    BottomGrid.Visibility = Visibility.Collapsed;
                }
                else
                {
                    this.WindowStyle = WindowStyle.SingleBorderWindow;
                    this.WindowState = WindowState.Normal;
                    MenuDock.Visibility = Visibility.Visible;
                    BottomGrid.Visibility = Visibility.Visible;
                }

                _Fullscreen = !_Fullscreen;
            }
        }



        private void MediaElement_OnMediaEnded(object sender, EventArgs e)
        {
            MediaElement item = sender as MediaElement;
            if (item != null)
            {
                for (int i = 0; i < _PlayListNames.Count; ++i)
                {
                    if (_PlayListNames[i].FullPath == item.Source.OriginalString)
                    {
                        if (i + 1 < _PlayListNames.Count) OpenFile(_PlayListNames[i + 1].FullPath);
                        break;
                    }
                }
            }
        }
    }
}
