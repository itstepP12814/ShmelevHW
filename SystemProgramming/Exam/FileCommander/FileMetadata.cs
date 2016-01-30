using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FileCommander
{
   public class FileMetadata {
      public string Name { get; set; }
      public string FullPath { get; set; }
      public string NameWithoutExtension { get; set; }
      public bool IsFolder { get; set; }
      public bool IsFile { get; set; }

      public override string ToString() {
         string strOut = String.Empty;;
         if(IsFile) strOut = "[Файл] ";
         if(IsFolder) strOut = "[Папка] ";
         return strOut + Name;
      }
   }
}
