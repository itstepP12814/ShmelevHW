using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace TestSocketApp
{
   class Program
   {
      static void Main(string[] args) {
         TestSocket mySocket = new TestSocket();
         mySocket.Connect();
      }

      class TestSocket
      {
         public void Connect() {
            GlobalProxySelection.Select = new WebProxy("169.254.80.80", 8889);
            IPAddress[] objarrIPAddress = System.Net.Dns.GetHostAddresses("feeltech.ru");
            IPAddress objAddress = objarrIPAddress[0];
            IPEndPoint objEndPoint = new IPEndPoint(objAddress, 80);
            Socket objSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.IP);
            try {
               objSocket.Connect(objEndPoint);
               if(objSocket.Connected) {
                  string strSend = "GET http://feeltech.ru/ HTTP/1.1\r\nHost: feeltech.ru\r\n\r\n";
                  objSocket.Send(Encoding.ASCII.GetBytes(strSend));
                  byte[] btarrBuffer = new byte[2048];
                  int iLength;
                  do {
                     iLength = objSocket.Receive(btarrBuffer);
                     Console.WriteLine(Encoding.ASCII.GetString(btarrBuffer, 0, iLength));
                     Console.ReadLine();
                  } while(iLength > 0);
               }
               else {
                  Console.WriteLine("Connect error");
                  Console.ReadLine();
               }
            }
            catch(SocketException ex) {
               Console.WriteLine(ex.Message);
               Console.ReadLine();
            }
         }
      }
   }
}
