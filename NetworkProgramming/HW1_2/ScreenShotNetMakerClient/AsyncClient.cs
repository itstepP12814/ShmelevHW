using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Runtime.Serialization.Formatters.Binary;
using System.Threading.Tasks;
using System.Windows;

namespace ScreenShotNetMakerClient
{
   public class AsyncClient
   {
      private IPEndPoint EndPoint;
      private Socket InputSocket;
      public AsyncClient(IPAddress ipAddress, int port)
      {
         EndPoint = new IPEndPoint(ipAddress, port);
      }

      public async Task ConnectAsync()
      {
         if (InputSocket != null)
            return;
         try
         {
            InputSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.IP);
            await Task.Factory.FromAsync(InputSocket.BeginConnect, InputSocket.EndConnect, EndPoint, TaskCreationOptions.None);
         }
         catch (SocketException ex)
         {
            MessageBox.Show("Ошибка подключения к серверу: " + ex.Message);
         }
      }

      public async Task<byte[]> ReceiveBitmapBytesAsync()
      {
            return Task<byte[]>.Run(() => ReceiveBitmapBytes()).Result;
      }

      private Task<byte[]> ReceiveBitmapBytes()
      {
         TaskCompletionSource<byte[]> objCompletionSource = new TaskCompletionSource<byte[]>();
         try
         {
            List<byte> btBuffer = new List<byte>();
            int iLength;
            do
            {
               byte[] btarrBuffer = new byte[1024];
               iLength = InputSocket.Receive(btarrBuffer);
               btBuffer.AddRange(btarrBuffer);
            } while (iLength > 0);

            objCompletionSource.TrySetResult(btBuffer.ToArray());
         }
         catch (Exception ex)
         {
            objCompletionSource.TrySetException(ex);
         }
         return objCompletionSource.Task;
      }
   }
}
