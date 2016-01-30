using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using IndexSearchServerApp;
namespace XmlTest
{
   [TestClass]
   public class XmlUnitTest
   {
      [TestMethod]
      public void TestParsing() {
         string strResult = ServerController.GetStreetsAsString("23568");
         Assert.IsFalse(strResult == null || strResult == String.Empty);
      }
   }
}
