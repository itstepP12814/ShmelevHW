using System;
using System.Windows;

namespace UsingUserControl
{
   /// <summary>
   /// Interaction logic for MainWindow.xaml
   /// </summary>
   public partial class MainWindow : Window
   {
      public MainWindow()
      {
         try {
            InitializeComponent();
         }
         catch (Exception)
         {

         }
      }
   }
}
