using System;
using System.CodeDom;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.Entity.Validation;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Security.AccessControl;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using BankApplication;
using BankMap.Views;
using GMap.NET;
using GMap.NET.MapProviders;
using GMap.NET.WindowsForms;
using GMap.NET.WindowsForms.Markers;
using GMap.NET.WindowsForms.ToolTips;

namespace BankMap
{
    public partial class MainForm : Form
    {
        private DPoint _lastClickCoordinates;
        private PointLatLng _lastAreaCoordinates;
        public string XmlPath = @"http://www.obmennik.by/xml/kurs.xml";
        private GMapOverlay _temporaryMarksOverlay;
        private GMapOverlay _savedMarksOverlay;


        public MainForm()
        {
            InitializeComponent();
            gMapControl.MouseWheel += GMapControlOnMouseWheel;
            comboBoxCur.DataSource = Program.db.GetCurrenciesNames();
        }

        private void GMapControlOnMouseWheel(object sender, MouseEventArgs mouseEventArgs)
        {
            double deltaZoomValue = 0.3;

            if (mouseEventArgs.Delta > 0 && gMapControl.Zoom + deltaZoomValue < gMapControl.MaxZoom)
                ZoomIn(deltaZoomValue);

            if (mouseEventArgs.Delta < 0 && gMapControl.Zoom - deltaZoomValue > gMapControl.MinZoom)
                ZoomOut(deltaZoomValue);
        }

        private void ZoomIn(double deltaZoomValue)
        {
            gMapControl.Zoom += deltaZoomValue;
        }

        private void ZoomOut(double deltaZoomValue)
        {
            gMapControl.Zoom -= deltaZoomValue;
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            //Создаем выпадающее меню фильтра банка
            bankFilterMenu.DropDown = new ToolStripDropDown();
            IEnumerable<Bank> banks = Program.db.GetBanks();
            List<ToolStripMenuItem> bankMenuItems = new List<ToolStripMenuItem>();
            foreach (var bank in banks)
            {
                ToolStripMenuItem item = new ToolStripMenuItem();
                item.Name = "bankItem" + bank.Id;
                item.Tag = bank.Id;
                item.Text = bank.Name;
                item.Click += bankMenuItemOnClick;
                bankMenuItems.Add(item);
            }
            bankFilterMenu.DropDown.Items.AddRange(bankMenuItems.ToArray());

            //Создаем выпадающее меню фильтра услуг
            serviceFilterMenu.DropDown = new ToolStripDropDown();
            IEnumerable<ServicesNames> services = Program.db.GetServicesNames();
            List<ToolStripMenuItem> servicesMenuItems = new List<ToolStripMenuItem>();
            foreach (var service in services)
            {
                ToolStripMenuItem item = new ToolStripMenuItem();
                item.Name = "serviceItem" + service.Id;
                item.Tag = service.Id;
                item.Text = service.Name;
                item.Click += serviceMenuItemOnClick;
                servicesMenuItems.Add(item);
            }
            serviceFilterMenu.DropDown.Items.AddRange(servicesMenuItems.ToArray());

            gMapControl.MapProvider = GMapProviders.OpenStreetMap;
            gMapControl.MinZoom = 2;
            gMapControl.MaxZoom = 17;
            gMapControl.Zoom = 12;
            _temporaryMarksOverlay = new GMapOverlay("temporary");
            _savedMarksOverlay = new GMapOverlay("saved");
            gMapControl.Overlays.Add(_temporaryMarksOverlay);
            gMapControl.Overlays.Add(_savedMarksOverlay);
            GMaps.Instance.Mode = AccessMode.ServerAndCache;
            gMapControl.DragButton = MouseButtons.Left;
            gMapControl.ZoomAndCenterMarkers(null);
            gMapControl.SetPositionByKeywords("Minsk, Belarus");
            _lastClickCoordinates = new DPoint() { X = 0, Y = 0 };

            _lastAreaCoordinates = gMapControl.Position;
            LoadMarksForAllBanks();
        }

        private void serviceMenuItemOnClick(object sender, EventArgs eventArgs)
        {
            ToolStripMenuItem clickedItem = (ToolStripMenuItem)sender;
            _savedMarksOverlay.Clear();
            LoadMarksForBranchesRange(Program.db.GetBankBranchesByService((int)clickedItem.Tag));
        }

        private void bankMenuItemOnClick(object sender, EventArgs eventArgs)
        {
            ToolStripMenuItem clickedItem = (ToolStripMenuItem)sender;
            _savedMarksOverlay.Clear();
            LoadMarksForBranchesRange(Program.db.GetBankBranchesByBank((int)clickedItem.Tag));
        }

        private async Task LoadMarksBank(Bank bank)
        {
            try
            {
                await GetExchangeRateInfo(XmlPath);
            }
            catch (WebException ex)
            {
                throw ex;
            }
            finally
            {
                LoadMarksForAllBranches(bank);
            }
        }

        private async Task LoadMarksForAllBanks()
        {
            try
            {
                await GetExchangeRateInfo(XmlPath);
            }
            catch (WebException ex)
            {
                throw ex;
            }
            finally
            {
                foreach (var bank in Program.db.GetBanks())
                {
                    LoadMarksForAllBranches(bank);
                }
            }
        }

        private async Task GetExchangeRateInfo(string source)
        {
            _temporaryMarksOverlay.Clear();
            _savedMarksOverlay.Clear();
            ExchangeRatesParser parser = new ExchangeRatesParser(source);
            List<ExchangeRates> rates = await parser.GetRatesAsync();
            foreach (var bank in Program.db.GetBanks())
            {
                Program.db.RemoveOldExchangeRates(bank);
                foreach (var exchangeRate in rates)
                {
                    if (bank.Id == Convert.ToInt32(exchangeRate.XmlBankId))
                    {
                        Program.db.AddExchangeRate(bank, exchangeRate);
                    }
                }
            }
        }

        private void LoadMarksForAllBranches(Bank bank)
        {
            foreach (var bankBranch in bank.BankBranchSet)
            {
                LoadMarksForOnceBranch(bankBranch);
            }
        }

        private void LoadMarksForBranchesRange(List<BankBranch> branches)
        {
            foreach (var bankBranch in branches)
            {
                LoadMarksForOnceBranch(bankBranch);
            }
        }

        private void LoadMarksForOnceBranch(BankBranch bankBranch)
        {
            GMapMarker marker = new GMarkerGoogle(new PointLatLng(bankBranch.Ypos, bankBranch.Xpos),
                    GMarkerGoogleType.blue);
            marker.Tag = bankBranch.Id;
            if ((int)marker.Tag == bankBranch.Id)
            {
                string currencyInfo = "";

                //Добавляем подсказку с курсами валют
                foreach (var exchangeRate in Program.db.GetBankById(bankBranch.Bank_Id).ExchangeRatesSet)
                {
                    currencyInfo +=
                        "Валюта: " + exchangeRate.Currency + "\n" +
                        "\tПокупка: " + exchangeRate.Buy + "\n" +
                        "\tПродажа:" + exchangeRate.Sell + "\n\n";
                }
                //Создаем всплывающую подсказку с информацией о курсах
                marker.ToolTip = new GMapToolTip(marker);
                marker.ToolTipText = currencyInfo;
            }
            _savedMarksOverlay.Markers.Add(marker);
        }

        private void gMapControl_MouseClick(object sender, MouseEventArgs e)
        {
            double lat = gMapControl.FromLocalToLatLng(e.X, e.Y).Lat;
            double lng = gMapControl.FromLocalToLatLng(e.X, e.Y).Lng;

            DPoint compareDPoint = new DPoint() { X = lat, Y = lng };
            PointLatLng areaLatLng = gMapControl.Position;
            if (_lastClickCoordinates != compareDPoint)
            {
                //Если мы не переместили карту
                if (_lastAreaCoordinates == areaLatLng)
                {
                    if (_temporaryMarksOverlay.Markers.Count != 0)
                    {
                        _temporaryMarksOverlay.Markers.Remove(_temporaryMarksOverlay.Markers[_temporaryMarksOverlay.Markers.Count - 1]);
                    }
                    _lastClickCoordinates.X = lat;
                    _lastClickCoordinates.Y = lng;
                    GMapMarker newMarker = new GMarkerGoogle(new PointLatLng(lat, lng), GMarkerGoogleType.green);
                    _temporaryMarksOverlay.Markers.Add(newMarker);
                }
                _lastAreaCoordinates = gMapControl.Position;
            }
        }

        private void gMapControl_OnMarkerClick(GMapMarker item, MouseEventArgs e)
        {
            try
            {
                DPoint markerPoint = new DPoint()
                {
                    X = item.Position.Lng,
                    Y = item.Position.Lat
                };

                if (item.Tag == null)
                    Program.AddMarkerForm = new AddMarker(markerPoint);
                else
                    Program.AddMarkerForm = new AddMarker(markerPoint, Convert.ToInt32(item.Tag));

                Program.AddMarkerForm.ShowDialog();
                LoadMarksForAllBanks();
            }
            catch (FieldNotFilledException)
            {
                MessageBox.Show(
                    "Не все поля заполнены, пожалуйста, проверьте заполненность полей помеченных звездочкой.",
                    "Не все поля заполнены");
            }
            catch (NoCoordinatesException)
            {
                MessageBox.Show("Возникла ошибка определения координат.", "Ошибка");
            }
            catch (DbEntityValidationException ex)
            {
                foreach (var eve in ex.EntityValidationErrors)
                {
                    Console.WriteLine("Entity of type \"{0}\" in state \"{1}\" has the following validation errors:",
                        eve.Entry.Entity.GetType().Name, eve.Entry.State);
                    foreach (var ve in eve.ValidationErrors)
                    {
                        Console.WriteLine("- Property: \"{0}\", Error: \"{1}\"",
                            ve.PropertyName, ve.ErrorMessage);
                    }
                }
                throw;
            }
        }

        private void addServiceName_Click(object sender, EventArgs e)
        {
            Program.AddServiceForm = new AddService();
            Program.AddServiceForm.ShowDialog();
        }

        private void addNewBankBtn_Click(object sender, EventArgs e)
        {
            Program.AddBankForm = new AddBank();
            Program.AddBankForm.ShowDialog();
        }

        private void bestSellBtn_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrEmpty(comboBoxCur.Text))
                throw new FieldNotFilledException();
            Bank bestBank = Program.db.GetBankWithBestSellRate(comboBoxCur.Text);
            LoadMarksBank(bestBank);
        }

        private void showAllBtn_Click(object sender, EventArgs e)
        {
            LoadMarksForAllBanks();
        }

        private void bestBuyBtn_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrEmpty(comboBoxCur.Text))
                throw new FieldNotFilledException();
            Bank bestBank = Program.db.GetBankWithBestBuyRate(comboBoxCur.Text);
            LoadMarksBank(bestBank);
        }

        private void nearestBranchBtn_Click(object sender, EventArgs e)
        {
            try
            {
                if (_temporaryMarksOverlay.Markers.Count == 0)
                    throw new NoTemporaryMarkerOnMapException();
                var nearestMarker = SearchNearestMarker(_temporaryMarksOverlay.Markers[0]);
                _savedMarksOverlay.Clear();
                LoadMarksForOnceBranch(Program.db.GetBankBranchById((int) nearestMarker.Tag));
                gMapControl.Position = nearestMarker.Position;
                //gMapControl.ZoomAndCenterMarkers("saved");
            }
            catch (NoTemporaryMarkerOnMapException ex)
            {
                MessageBox.Show("Сначала необходимо выбрать точку на карте", "Ошибка", MessageBoxButtons.OK,
                    MessageBoxIcon.Information);
            }
            catch (NullReferenceException ex)
            {
                MessageBox.Show("Нет данных об отделениях", "Ошибка", MessageBoxButtons.OK,
                    MessageBoxIcon.Information);
            }
        }

        private double GetDistance(PointLatLng mainPoint, PointLatLng anotherPoint)
        {
            double firstCatet = Math.Abs(mainPoint.Lng - anotherPoint.Lng);
            double secondCatet = Math.Abs(mainPoint.Lat - anotherPoint.Lat);
            return Math.Pow(firstCatet, 2) + Math.Pow(secondCatet, 2);
        }

        private GMapMarker SearchNearestMarker(GMapMarker mainMarker)
        {
            double minDistance = gMapControl.ViewArea.Lng;
            GMapMarker lastMarker = null;
            foreach (var gMapMarker in _savedMarksOverlay.Markers)
            {
                double dist = GetDistance(mainMarker.Position, gMapMarker.Position);
                if (dist < minDistance)
                {
                    minDistance = dist;
                    lastMarker = gMapMarker;
                }
            }
            return lastMarker;
        }

        private void toolStripAddBank_Click(object sender, EventArgs e)
        {
            addNewBankBtn_Click(sender, e);
        }

        private void toolStripAddService_Click(object sender, EventArgs e)
        {
            addServiceName_Click(sender, e);
        }

        private void toolStripRefreshMap_Click(object sender, EventArgs e)
        {
            gMapControl.ReloadMap();
            LoadMarksForAllBanks();
        }

        private void toolStripRefreshRates_Click(object sender, EventArgs e)
        {
            LoadMarksForAllBanks();
        }

        private void toolStripZoomIn_Click(object sender, EventArgs e)
        {
            ZoomIn(1);
        }

        private void toolStripZoomOut_Click(object sender, EventArgs e)
        {
            ZoomOut(1);
        }

        
    }

    public class DPoint
    {
        public double X;
        public double Y;
    }
}
