using System;
using System.Drawing.Imaging;
using System.IO;
using System.Net;
using System.Security.Permissions;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using ScreenShotMakerServer;
using ScreenShotNetMakerClient;

namespace ScreenshotTest
{
   [TestClass]
   public class ScreenShotTest
   {
      IPAddress IpAddress = IPAddress.Loopback;
      private int Port = 1027; 
      [TestMethod]
      public void TakeScreenshot() {
         var image = ScreenshotMaker.TakeScreenShot();
         image.Save("lol.png", ImageFormat.Png);
      }

   }
}
