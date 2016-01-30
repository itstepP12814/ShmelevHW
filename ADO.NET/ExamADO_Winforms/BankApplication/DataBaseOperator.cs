using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Data.Entity.Core.Objects;
using System.Data.Entity.Infrastructure;
using System.Globalization;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace BankApplication
{
    public class DataBaseOperator
    {
        public enum RateEnum { Usd, Eur, Rur };

        private BankDataModelContainer Db;
        public DataBaseOperator()
        {
            Db = new BankDataModelContainer();
        }

        public void AddBankAsync(string name)
        {
            Db.BankSet.Add(new Bank() { Name = name });
            Db.SaveChangesAsync();
        }

        public void AddServiceAsync(string name)
        {
            Db.ServicesNamesSet.Add(new ServicesNames() { Name = name });
            Db.SaveChangesAsync();
        }

        //public void AddBankBranchAsync(int parentBankId, string name, string address, string breakTime, DateTime openDate, string operatorInfo, string phoneNumber, string workTime, List<string> servicesList, double xPos, double yPos)

        public void AddBankBranchAsync(BankBranch bankBranch, Bank bank)
        {
            Db.BankSet.Single(c => c.Id == bank.Id).BankBranchSet.Add(bankBranch);
            Db.SaveChangesAsync();
        }

        public void EditBankBranch(int bankId, Action<BankBranch> entityEdit)
        {
            var oldBranch = Db.BankBranchSet.Single(c => c.Id == bankId);
            entityEdit(oldBranch);
            Db.SaveChanges();
        }

        public void RemoveBankBranch(int branchId)
        {
            BankBranch branchToRemove = Db.BankBranchSet.Single(c => c.Id == branchId);
            Db.ServicesSet.RemoveRange(Db.ServicesSet.Where(s => s.BankBranch_Id == branchToRemove.Id).ToArray());
            Db.BankBranchSet.Remove(branchToRemove);
            Db.SaveChanges();
        }

        public void AddExchangeRate(Bank bank, ExchangeRates rate)
        {
            Db.BankSet.Single(c => c.Id == bank.Id).ExchangeRatesSet.Add(rate);
            Db.SaveChanges();
        }

        public BankBranch GetBankBranchById(int id)
        {
            return Db.BankBranchSet.Single(c => c.Id == id);
        }

        public IEnumerable<ServicesNames> GetServicesNames()
        {
            return Db.ServicesNamesSet.ToList();
        }

        public IEnumerable<Bank> GetBanks()
        {
            return Db.BankSet.ToList();
        }

        public Bank GetBankById(int id)
        {
            return Db.BankSet.Single(c => c.Id == id);
        }

        public void RemoveOldExchangeRates(Bank bank)
        {
            ExchangeRates[] objExchangeRates = Db.BankSet.Single(c => c.Id == bank.Id).ExchangeRatesSet.ToArray();
            Db.ExchangeRatesSet.RemoveRange(objExchangeRates);
            Db.SaveChanges();
        }

        public Bank GetBankWithBestSellRate(string rateName)
        {
            var nameFilter = Db.ExchangeRatesSet.Where(n=>n.Currency.ToLower() == rateName.ToLower()).Select(g=>g).ToList();
            var rateFilter = nameFilter.Where(c => c.Sell == nameFilter.Max(n => n.Sell)).Select(g=>g).ToList().First();
            var bank = Db.BankSet.Single(x=>x.Id == rateFilter.Bank_Id);
            
            return bank;
        }

        public Bank GetBankWithBestBuyRate(string rateName)
        {
            var nameFilter = Db.ExchangeRatesSet.Where(n => n.Currency.ToLower() == rateName.ToLower()).Select(g => g).ToList();
            var rateFilter = nameFilter.Where(c => c.Buy == nameFilter.Max(n => n.Buy)).Select(g => g).ToList().First();
            var bank = Db.BankSet.Single(x => x.Id == rateFilter.Bank_Id);

            return bank;
        }

        public List<string> GetCurrenciesNames()
        {
            return Db.ExchangeRatesSet.GroupBy(n=> new { CurName = n.Currency}).Select(c=>c.Key.CurName).ToList();
        }

        public List<BankBranch> GetBankBranchesByService(int serviceId)
        {
            var serviceName = Db.ServicesNamesSet.Where(s => s.Id == serviceId).Select(n => n.Name).ToList().FirstOrDefault();
            var bankBranches =
                Db.BankBranchSet.Where(
                    bb =>
                        bb.ServicesSet.Where(ss => ss.Name == serviceName).Select(x => x.Name).ToList().FirstOrDefault() ==
                        serviceName).ToList();
            return bankBranches;
        }

        public List<BankBranch> GetBankBranchesByBank(int bankId)
        {
            var banks = Db.BankSet.Where(c => c.Id == bankId).ToList();
            return banks.Select(bank => bank.BankBranchSet.ToList()).ToList()[0];
        }

    }

    public partial class ServicesNames
    {
        public override string ToString()
        {
            return Name;
        }
    }

    public partial class Bank
    {
        public override string ToString()
        {
            return Name;
        }
    }

    public partial class ExchangeRates { }
}