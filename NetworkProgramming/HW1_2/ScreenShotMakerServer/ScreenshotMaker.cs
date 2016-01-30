using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.IO.Compression;
using System.Linq;
using System.Net.Mime;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Encoder = System.Drawing.Imaging.Encoder;

namespace ScreenShotMakerServer
{
   static public class ScreenshotMaker
   {
      public static Bitmap TakeScreenShot() {
         Bitmap objScreenshot = new Bitmap(Screen.PrimaryScreen.Bounds.Width, Screen.PrimaryScreen.Bounds.Height, PixelFormat.Format32bppArgb);
         var objGfxScreenshot = Graphics.FromImage(objScreenshot);
         objGfxScreenshot.CopyFromScreen(Screen.PrimaryScreen.Bounds.X, Screen.PrimaryScreen.Bounds.Y, 0, 0, Screen.PrimaryScreen.Bounds.Size, CopyPixelOperation.SourceCopy);
         return objScreenshot;
      }

      static public MemoryStream GetBitmapStream(Bitmap image) {
         using (MemoryStream objBitmapStream = new MemoryStream()) {
            ImageCodecInfo pngEncoder = ImageCodecInfo.GetImageDecoders().First(codec=>codec.FormatID == ImageFormat.Png.Guid);
            EncoderParameters objPngEncoderParameters = new EncoderParameters();
            //Уровень сжатия
            objPngEncoderParameters.Param[0] = new EncoderParameter(Encoder.Quality, 33L);
            image.Save(objBitmapStream, pngEncoder, objPngEncoderParameters);
            GZipStream objGZipStream = new GZipStream(objBitmapStream, CompressionLevel.NoCompression, false);
            return objBitmapStream;
         }
      }
   }
}
