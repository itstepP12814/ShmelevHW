using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
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
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace FileCommander
{
   /// <summary>
   /// Interaction logic for MainWindow.xaml
   /// </summary>
   public partial class MainWindow : Window
   {
      const string START_PATH = @"C:\";
      private string CurrentPath;
      private const string  LEFT_PANEL_NAME = "ListViewLeft";
      private const string RIGHT_PANEL_NAME = "ListViewRight";
      public MainWindow()
      {
         InitializeComponent();
         UpdateField(START_PATH, LEFT_PANEL_NAME);
         UpdateField(START_PATH, RIGHT_PANEL_NAME);

         ListViewLeft.MouseDoubleClick += ListViewOnMouseDoubleClickAsync;
         ListViewRight.MouseDoubleClick += ListViewOnMouseDoubleClickAsync;
      }

      private void UpdateField(string strPath, string strFieldName)
      {
         IEnumerable<FileMetadata> strarrPaths = GetListByPath(strPath).ToList();
         if(strFieldName == LEFT_PANEL_NAME)
         {
            ListViewLeft.ItemsSource = strarrPaths;
            TextBoxPathName_Left.Text = strPath;

         }
         else if(strFieldName == RIGHT_PANEL_NAME)
         {
            ListViewRight.ItemsSource = strarrPaths;
            TextBoxPathName_Right.Text = strPath;
         }
      }

      private async void ListViewOnMouseDoubleClickAsync(object sender, MouseButtonEventArgs mouseButtonEventArgs) {
         ListView list = sender as ListView;
         FileMetadata selectedItem = (FileMetadata)list.SelectedItem;
         if(selectedItem.IsFile) await Task.Factory.StartNew(() => { Process.Start(selectedItem.FullPath); });
         else if(selectedItem.IsFolder) {
            list.ItemsSource = GetListByPath(selectedItem.FullPath);
            CurrentPath = selectedItem.FullPath;
            if (list.Name == LEFT_PANEL_NAME) UpdateField(selectedItem.FullPath, LEFT_PANEL_NAME);
            if (list.Name == RIGHT_PANEL_NAME) UpdateField(selectedItem.FullPath, RIGHT_PANEL_NAME);
         }
      }

      private void UIElement_OnKeyDown(object sender, KeyEventArgs e)
      {
         if(e.Key == Key.Enter) {
            TextBox box = sender as TextBox;
            if (box.Name == "TextBoxPathName_Left") UpdateField(box.Text, LEFT_PANEL_NAME);
            if (box.Name == "TextBoxPathName_Right") UpdateField(box.Text, RIGHT_PANEL_NAME);
         }
      }

      static IEnumerable<FileMetadata> GetListByPath(string needlePath) {
         try
         {
            List<string> arrFolders = Directory.GetDirectories(needlePath).ToList();
            List<string> arrFiles = Directory.GetFiles(needlePath).ToList();
            List<FileMetadata> fileList = new List<FileMetadata>();

            foreach (var arrFolder in arrFolders)
            {
               fileList.Add(new FileMetadata()
               {
                  FullPath = arrFolder,
                  IsFolder = true,
                  Name = arrFolder.Trim(needlePath.ToCharArray()),
                  NameWithoutExtension = System.IO.Path.GetFileNameWithoutExtension(arrFolder)
               });
            }

            foreach (var arrFile in arrFiles)
            {
               fileList.Add(new FileMetadata()
               {
                  FullPath = arrFile,
                  IsFile = true,
                  Name = arrFile.Trim(needlePath.ToCharArray()),
                  NameWithoutExtension = System.IO.Path.GetFileNameWithoutExtension(arrFile)
               });
            }
            return fileList;
         }
         catch(UnauthorizedAccessException ex) {
            MessageBox.Show(ex.Message);
         }
         return GetListByPath(START_PATH);
      }
   }
}
