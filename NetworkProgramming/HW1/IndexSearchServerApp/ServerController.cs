using System;
using System.Collections.Generic;
using System.Linq;
using System.Xml;

namespace IndexSearchServerApp
{
   public class ServerController
   {
      private static IEnumerable<string> GetStreets(string strNeededIndex)
      {
         using (XmlReader objXmlReader = XmlReader.Create("StreetsList.xml"))
         {
            while (objXmlReader.ReadToFollowing("Street"))
            {
               objXmlReader.ReadToFollowing("Name");
               string strStreetName = objXmlReader.ReadElementContentAsString();
               objXmlReader.ReadToFollowing("Index");
               string strIndex = objXmlReader.ReadElementContentAsString();
               if (strIndex == strNeededIndex)
                  yield return strStreetName;
            }
         }
      }

      public static string GetStreetsAsString(string strIndex)
      {
         string strOutput = String.Empty;
         try
         {
            foreach (var street in GetStreets(strIndex))
            {
               strOutput += street + "\n";
            }
         }
         catch (XmlException ex)
         {
            strOutput += "Ошибка чтения базы";
         }
         return strOutput;
      }
   }
}
