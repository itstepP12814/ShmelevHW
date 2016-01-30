using System;
using System.Drawing;
using System.IO;
using System.Net;
using System.Net.Sockets;

namespace ScreenShotMakerServer
{
   public class AsyncServer {
      private Socket InputSocket;
      private IPEndPoint EndPoint;
      public AsyncServer(IPAddress address, int port)
      {
         EndPoint = new IPEndPoint(address, port);
      }

      public void Start() {
         if (InputSocket != null) 
            return;
         InputSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.IP);
         InputSocket.Bind(EndPoint);
         InputSocket.Listen(10);
         InputSocket.BeginAccept(new AsyncCallback(StartAcceptCallback), InputSocket);
      }

      private void StartAcceptCallback(IAsyncResult asyncResult) {
         Socket objSocket = asyncResult.AsyncState as Socket;
         Console.WriteLine("Подключено");

         if(objSocket == null) throw new NullReferenceException();

         Socket objDataSender = objSocket.EndAccept(asyncResult);
         Bitmap objBitmap = ScreenshotMaker.TakeScreenShot();
         byte[] btarrBuffer = ScreenshotMaker.GetBitmapStream(objBitmap).ToArray();

         Console.WriteLine("Сделан снимок");

         objDataSender.BeginSend(btarrBuffer, 0, btarrBuffer.Length, SocketFlags.None, new AsyncCallback(SendingCompleteCallback), objDataSender);
         InputSocket.BeginAccept(new AsyncCallback(StartAcceptCallback), InputSocket);
      }

      private void SendingCompleteCallback(IAsyncResult ar) {
         Socket objSendSocket = ar.AsyncState as Socket;
         Console.WriteLine("Отправлено на " + objSendSocket.RemoteEndPoint);
         objSendSocket.Shutdown(SocketShutdown.Both);
         objSendSocket.Close();
      }
   }
}
