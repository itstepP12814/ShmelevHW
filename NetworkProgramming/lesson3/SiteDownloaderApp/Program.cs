using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;

namespace SiteDownloaderApp
{
   class Program
   {
      static void Main(string[] args) {
         Uri NetPath = new Uri("http://akson.by");
         using (FileStream objFileStream = new FileStream("index.html", FileMode.CreateNew, FileAccess.Write)) {
            byte[] btarrBuffer = GetPageBytes(NetPath);
            objFileStream.Write(btarrBuffer, 0, btarrBuffer.Length);
         }
      }

      static byte[] GetPageBytes(Uri pageUri) {
         WebClient objClient = new WebClient();
         return objClient.DownloadData(pageUri);
      }
   }
}
