using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Globalization;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.VisualStyles;

namespace MusicInfoXMLReader
{
    public partial class MainForm : Form {
        private DataTable dataBase;
        private DataTable producersBase;

        private List<CD> cds;
        private List<Producer> producers;
        private bool albumsIsLoaded;
        private bool producersIsLoaded;
        private event EventHandler albumsLoaded;
        private event EventHandler producersLoaded;

        public MainForm()
        {
            InitializeComponent();
            albumsLoaded += AlbumsLoadedView;
            producersLoaded += ProducersAndAlbumsLoadedView;
            foreach(ToolStripMenuItem item in filterMenu.DropDownItems) {
                item.Enabled = false;
            }
        }

        void AlbumsLoadedView(object ob, EventArgs e)
        {
            //1, 2, 3, 4, 5, 10
            filter1.Enabled =
                filter2.Enabled =
                    filter3.Enabled =
                        filter4.Enabled =
                            filter5.Enabled =
                                filter10.Enabled = true;
            albumsIsLoaded = true;
            if (producersIsLoaded) {
                ProducersAndAlbumsLoadedView(ob, e);
            }
        }

        void ProducersAndAlbumsLoadedView(object ob, EventArgs e)
        {
            //6,7,8,9
            if (albumsIsLoaded) {
                filter6.Enabled =
                    filter7.Enabled =
                        filter8.Enabled =
                            filter9.Enabled = true;
            }
            producersIsLoaded = true;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            dataGridView1.DataSource = cds;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            dataGridView1.DataSource = producers;
        }

        private void filter1_Click(object sender, EventArgs e) {
            //2.1.	Список всех артистов, который выпустили свои альбомы после распада СССР.
            var outPut = from cd in cds where cd.Year >= 1991
                select new { ArtistName = cd.Artist};
            dataGridView1.DataSource = outPut.ToList();
        }

        private void filter2_Click(object sender, EventArgs e) {
            //2.2.	Список стран (без повторений).
            var outOut = from cd in cds group cd by cd.Country into nw select new { Country = nw.Key};
            dataGridView1.DataSource = outOut.ToList();
        }

        private void filter3_Click(object sender, EventArgs e) {
            //2.3.	Список наименований альбомов, выпущенных в США, упорядоченных по году выпуска.
            var outPut = (cds.Where(cd => cd.Country == "USA").
                OrderBy(cd => cd.Year).
                Select(cd => new
                {
                    AlbumTitle = cd.Title
                })).ToList();
            dataGridView1.DataSource = outPut;
        }

        private void filter4_Click(object sender, EventArgs e) {
            //2.4.	Суммарную стоимость альбомов за страну.
            var outPut = from cd in cds group cd by cd.Country into nw select new {
                Country = nw.Key,
                CommonPrice = Math.Round(nw.Sum(s => s.Price), 1, MidpointRounding.ToEven)
            };
            dataGridView1.DataSource = outPut.ToList();
        }

        private void filter5_Click(object sender, EventArgs e)
        {
            //2.5.	Список: компания и количество альбомов за год, года упорядочены по возрастанию. 
            var outPut = cds.GroupBy(gr => new { Year = gr.Year, Company = gr.Company }).OrderBy(a => a.Key.Year).Select(s => new {
                Company = s.Key.Company,
                Year = s.Key.Year,
                Count = s.Count()
            });
            dataGridView1.DataSource = outPut.ToList();
        }

        private void filter6_Click(object sender, EventArgs e)
        {
            //2.6.	Наименование альбома и продюсера, получившего самое большое вознаграждение за вклад в развитие.
            var outPut = from cd in cds
                join pr in producers on cd.Producer equals pr.Id into collection
                from nw in collection
                group nw by cd.Title
                into rwc
                from rw in rwc
                where rw.Free == rwc.Max(s => s.Free)
                select new {
                    Album = rwc.Key,
                    Producer = rw.Name,
                    Price = rw.Free
                };
                dataGridView1.DataSource = outPut.ToList();
        }

        private void filter7_Click(object sender, EventArgs e)
        {
            //2.7.	Количество альбомов каждого продюсера в период  между годами выхода альбома 1988 – 1990 гг.
            var outPut = cds.Where(cd => cd.Year >= 1988 && cd.Year <= 1990).
                Join(producers, cd => cd.Producer, pr => pr.Id, (cd, pr) => new { album = cd, producer = pr }).
                GroupBy(prev => prev.producer.Name).
                Select(view => new
                {
                    Producer = view.Key,
                    CountOfOldAlbums = view.Count() //Как получаются данные на этой строке?
                });
            dataGridView1.DataSource = outPut.ToList();
        }

        private void filter8_Click(object sender, EventArgs e) {
            var outPut = producers.Where(pr => pr.Date == producers.Min(s => s.Date)).Select(pr=>new { Name = pr.Name});
            //Почему функция Min адекватно отрабатывает для даты-строки, но для типа DateTime не работает? 
            dataGridView1.DataSource = outPut.ToList();
        }

        private void filter9_Click(object sender, EventArgs e)
        {
            //2.9.	Информацию о самом дешевом альбоме (название альбома, исполнителя и продюсера).
            var outPut = cds.Where(cd => cd.Price == cds.Min(s => s.Price)).
                Join(producers, cd => cd.Producer, pr => pr.Id, (cd, pr) => new { Album = cd, Producer = pr }).
                Select(prev => new {
                    AlbumTitle = prev.Album.Title,
                    Artist = prev.Album.Artist,
                    Producer = prev.Producer.Name
                });
            dataGridView1.DataSource = outPut.ToList();
        }

        private void filter10_Click(object sender, EventArgs e)
        {
            //2.10.Полную информацию об альбомах, отсортированную по следующим критериям: год выхода альбома, стоимость альбома, наименование альбома.
            var outPut = cds.OrderBy(cd => cd.Year).ThenBy(cd => cd.Price).ThenBy(cd => cd.Title)
                .Select(cd=> cd);
            dataGridView1.DataSource = outPut.ToList();
        }

        private void loadAlbumsBtn_Click(object sender, EventArgs e) {
            try {
                OpenFileDialog fileDialog = new OpenFileDialog();
                fileDialog.Filter = "XML-файлы(*.xml)|*.xml";
                fileDialog.FilterIndex = 0;
                if(fileDialog.ShowDialog() == DialogResult.OK) {

                    DataSet dataBaseSet = new DataSet();
                    dataBaseSet.ReadXml(fileDialog.FileName);
                    dataBase = dataBaseSet.Tables[0];

                    //Присваиваем артистов
                    cds = new List<CD>();

                    foreach(var note in dataBase.Rows) {
                        DataRow row = (DataRow)note;
                        CD newCd = new CD();
                        newCd.Title = row[0].ToString();
                        newCd.Artist = row[1].ToString();
                        newCd.Country = row[2].ToString();
                        newCd.Company = row[3].ToString();
                        newCd.Price = double.Parse(row[4].ToString(), CultureInfo.InvariantCulture);
                        newCd.Year = int.Parse(row[5].ToString());
                        newCd.Producer = row[6].ToString();
                        cds.Add(newCd);
                    }
                    dataGridView1.DataSource = cds;
                    albumsLoaded(cds, EventArgs.Empty); //Говорим о том, что альбомы загрузились
                }
            }
            catch(Exception ex) {
                MessageBox.Show("Ошибка открытия файла: " + ex.Message, "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }
        }

        private void loadProducersBtn_Click(object sender, EventArgs e)
        {
            try
            {
                OpenFileDialog fileDialog = new OpenFileDialog();
                fileDialog.Filter = "XML-файлы(*.xml)|*.xml";
                fileDialog.FilterIndex = 0;
                if (fileDialog.ShowDialog() == DialogResult.OK)
                {
                    DataSet producersSet = new DataSet();
                    producersSet.ReadXml("../../cd_catalog _2.xml");
                    producersBase = producersSet.Tables[0];

                    //Присваиваем продюссеров

                    producers = new List<Producer>();

                    foreach (var note in producersBase.Rows)
                    {
                        DataRow row = (DataRow)note;
                        Producer newProducer = new Producer();
                        newProducer.Id = row[0].ToString();
                        newProducer.Name = row[1].ToString();
                        newProducer.Date = row[2].ToString();
                        newProducer.Free = int.Parse(row[3].ToString());
                        producers.Add(newProducer);
                    }
                    dataGridView1.DataSource = producers;
                    producersLoaded(producers, EventArgs.Empty);
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка открытия файла: " + ex.Message, "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }
        }
    }

    class CD
    {
        public string Title{ get; set; }
        public string Artist{ get; set; }
        public string Country{ get; set; }
        public string Company{ get; set; }
        public double Price{ get; set; }
        public int Year{ get; set; }
        public string Producer{ get; set; }
    }

    class Producer
    {
        public string Id { get; set; }
        public string Name { get; set; }
        public string Date { get; set; }
        public int Free { get; set; }
    }
}
