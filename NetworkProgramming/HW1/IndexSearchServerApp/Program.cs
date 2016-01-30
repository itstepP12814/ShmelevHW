using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace IndexSearchServerApp
{
   class Program
   {
      static void Main(string[] args) {
         IPAddress objIPAddress = IPAddress.Parse("127.0.0.1");
         IPEndPoint objEndPoint = new IPEndPoint(objIPAddress, 20566);
         Socket objListenerSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.IP);
         objListenerSocket.Bind(objEndPoint);
         objListenerSocket.Listen(10);
         try {
            while(true) {
               Socket objInputSocket = objListenerSocket.Accept();
               byte[] btarrReceiveBuffer = new byte[1024];
               string strIndexNumber = String.Empty;

               int iLength = 0;
                  iLength = objInputSocket.Receive(btarrReceiveBuffer, 0, btarrReceiveBuffer.Length, SocketFlags.None);
                  strIndexNumber += Encoding.UTF8.GetString(btarrReceiveBuffer, 0, iLength);

               Console.WriteLine("Подключено через: " + objInputSocket.RemoteEndPoint);
               Console.WriteLine("Получен индекс: " + strIndexNumber);

               int iIndex;
               string strOutput = String.Empty;
               if(Int32.TryParse(strIndexNumber, out iIndex)) {
                  strOutput = ServerController.GetStreetsAsString(strIndexNumber);
               }
               else
               {
                  strOutput = "Ошибка: проверьте формат индекса";
               }
               Console.WriteLine(strOutput);
               objInputSocket.Send(Encoding.UTF8.GetBytes(strOutput));

               objInputSocket.Shutdown(SocketShutdown.Both);
               objInputSocket.Close();
            }
         }
         catch(SocketException ex) {
            Console.WriteLine(ex.Message);
         }
      }
   }
}
