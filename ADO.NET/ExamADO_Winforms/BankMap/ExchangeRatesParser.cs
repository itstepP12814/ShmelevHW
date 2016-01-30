using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Security.Cryptography.Xml;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.Linq;
using BankApplication;

namespace BankMap
{
    class ExchangeRatesParser
    {
        public string XmlPath { get; private set; }
        public ExchangeRatesParser(string xmlPath)
        {
            XmlPath = xmlPath;
        }

        public async Task<List<ExchangeRates>> GetRatesAsync()
        {
            List<ExchangeRates> ratesArr = new List<ExchangeRates>();
            await Task.Run(() =>
            {
                XDocument doc = XDocument.Load(XmlPath);
                XElement rootbBank = doc.Element("banks");
                int i = 0;
                if (rootbBank != null)
                    foreach (var item in rootbBank.Elements())
                    {
                        string bankId = (++i).ToString();

                        ExchangeRates rateUsd = new ExchangeRates();
                        rateUsd.Currency = "USD";
                        rateUsd.Sell = Convert.ToDecimal(item.Element("usd").Element("sell").Value);
                        rateUsd.Buy = Convert.ToDecimal(item.Element("usd").Element("buy").Value);
                        rateUsd.XmlBankId = bankId;
                        ExchangeRates rateEur = new ExchangeRates();
                        rateEur.Currency = "EUR";
                        rateEur.Sell = Convert.ToDecimal(item.Element("eur").Element("sell").Value);
                        rateEur.Buy = Convert.ToDecimal(item.Element("eur").Element("buy").Value);
                        rateEur.XmlBankId = bankId;
                        ExchangeRates rateRur = new ExchangeRates();
                        rateRur.Currency = "RUR";
                        rateRur.Sell = Convert.ToDecimal(item.Element("rur").Element("sell").Value, CultureInfo.InvariantCulture);
                        rateRur.Buy = Convert.ToDecimal(item.Element("rur").Element("buy").Value, CultureInfo.InvariantCulture);
                        rateRur.XmlBankId = bankId;
                        ratesArr.AddRange(new[] {rateUsd, rateEur, rateRur});
                    }
            });
            return ratesArr;
        }
    }

    public class Rate
    {
        public int BankId { get; set; }
        public decimal UsdSell{ get; set; }
        public decimal UsdBuy { get; set; }
        public decimal EurSell { get; set; }
        public decimal EurBuy { get; set; }
        public decimal RurSell { get; set; }
        public decimal RurBuy { get; set; }
    }
}
