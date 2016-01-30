using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace IndexSearchClientApp
{
   /// <summary>
   /// Interaction logic for MainWindow.xaml
   /// </summary>
   public partial class MainWindow : Window
   {
      string strTestString = "56589";
      string strServerAddress = "127.0.0.1";

      public MainWindow()
      {
         InitializeComponent();
         TextBoxAddress.Text = strServerAddress;
         TextBoxMessage.Text = strTestString;
      }

      private void ButtonBase_OnClick(object sender, RoutedEventArgs e) {
         
         IPAddress objIPAddress = IPAddress.Parse(TextBoxAddress.Text);
         IPEndPoint objEndPoint = new IPEndPoint(objIPAddress, 20566);
         Socket objOutputSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.IP);
         try
         {
            objOutputSocket.Connect(objEndPoint);
            if (objOutputSocket.Connected) {
               objOutputSocket.Send(Encoding.UTF8.GetBytes(TextBoxMessage.Text));
               int iLength;
               byte[] btarrBuffer = new byte[1024];
               do {
                  iLength = objOutputSocket.Receive(btarrBuffer);
                  TextBoxInfo.Text += Encoding.UTF8.GetString(btarrBuffer, 0, iLength) + "\n";
               } while(iLength > 0);
            }
            else
            {
               TextBoxInfo.Text += "Ошибка подключения";
            }
         }
         catch (SocketException ex)
         {
            Console.WriteLine(ex.Message);
         }
      }
   }
}
