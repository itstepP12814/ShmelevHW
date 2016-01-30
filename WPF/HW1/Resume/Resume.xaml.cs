using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using Microsoft.Win32;

namespace Forms
{
    /// <summary>
    /// Interaction logic for Resume.xaml
    /// </summary>
    public partial class Resume : Window
    {
        private string skills = String.Empty;
        public Resume()
        {
            InitializeComponent();
            foreach (var child in skillsList.Children)
            {
                CheckBox item = (CheckBox)child;
                item.Checked+= ItemOnChecked;
            }
        }

        private void ItemOnChecked(object sender, RoutedEventArgs routedEventArgs)
        {
            CheckBox item = sender as CheckBox;
            skills += item.Content;
        }

        private void sendBtn_Click(object sender, RoutedEventArgs e)
        {
            string info = "";

            info += lastname.Text + " " + firstname.Text + " " + middlename.Text + "\n";
            info += "Возраст: " + age.Text + "\n";
            info += "Семейное положение: " + age.Text + "\n";
            info += "Адрес: " + age.Text + "\n";
            info += "Электронная почта: " + age.Text + "\n";
            info += "Пол: " + "\n";
            info += "Навыки: " + skills + "\n";
            
            SaveFileDialog opf = new SaveFileDialog();
            opf.ShowDialog();
            System.IO.File.WriteAllText(opf.FileName, info);
        }
    }
}
