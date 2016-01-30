using System;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Net;
using System.Runtime.Serialization.Formatters.Binary;
using System.Windows;
using System.Windows.Media.Imaging;

namespace ScreenShotNetMakerClient
{
   /// <summary>
   /// Interaction logic for MainWindow.xaml
   /// </summary>
   public partial class MainWindow : Window
   {
      public MainWindow()
      {
         InitializeComponent();
      }

      private async void ButtonBase_OnClick(object sender, RoutedEventArgs e) {
         AsyncClient objClient = new AsyncClient(IPAddress.Loopback, 1027);
         try {
            await objClient.ConnectAsync();
            
            byte[] btarrBuffer = await objClient.ReceiveBitmapBytesAsync();

            using (MemoryStream objStream = new MemoryStream(btarrBuffer))
            {
               BitmapImage objBitmapImage = new BitmapImage();
               objBitmapImage.BeginInit();
               objBitmapImage.StreamSource = objStream;
               objBitmapImage.CacheOption = BitmapCacheOption.OnLoad;
               objBitmapImage.EndInit();
               ImageScreen.Source = objBitmapImage;
            }
         }
         catch(Exception ex) {
            MessageBox.Show("Ошибка: " + ex.Message);
         }
      }
   }
}
