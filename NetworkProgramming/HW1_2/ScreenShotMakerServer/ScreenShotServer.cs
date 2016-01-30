using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace ScreenShotMakerServer
{
   class ScreenShotServer {
      private delegate void AsyncCallback(Socket socket);
       
      static void Main(string[] args)
      {
         IPAddress objAddress = IPAddress.Loopback;
         AsyncServer objAsyncServer = new AsyncServer(objAddress, 1027);
         objAsyncServer.Start();
         Console.Read();
      }
   }
}
    