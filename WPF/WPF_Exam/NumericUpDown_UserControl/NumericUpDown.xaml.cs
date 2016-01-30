using System;
using System.Globalization;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Security.AccessControl;
using System.Windows;
using System.Windows.Controls;

namespace NumericUpDown_UserControl
{
   public partial class NumericUpDown : UserControl
   {
      public NumericUpDown()
      {
         InitializeComponent();
         Maximum = 100;
         Minimum = 0;
      }

      private static int iMinStatic = 0;
      private static int iMaxStatic = 100;

      static NumericUpDown()
      {
         FrameworkPropertyMetadata objMetaValue = new FrameworkPropertyMetadata((int)0, OnValueChanged);
         ValueProperty = DependencyProperty.Register(
            "Value",
            typeof(int),
            typeof(NumericUpDown),
            objMetaValue);

         //ValueChangedEvent = EventManager.RegisterRoutedEvent(
         //"ValueChanged",
         //RoutingStrategy.Bubble,
         //typeof(RoutedEventHandler),
         //typeof(NumericUpDown));
      }

      #region ValueProperty

      public static readonly DependencyProperty ValueProperty;
      public int Value
      {
         get { return (int)GetValue(ValueProperty); }
         set {
            try {
               SetValue(ValueProperty, value);
            }
            catch (Exception)
            {}
         }
      }
      private static void OnValueChanged(DependencyObject element, DependencyPropertyChangedEventArgs args)
      {
         ((NumericUpDown)element).SetTextValue((int)args.NewValue);
      }
      void SetTextValue(int newValue)
      {
         NumberTextBox.Text = newValue.ToString();
      }

      private void UpBtn_Click(object sender, RoutedEventArgs e)
      {
         int iCurrentValue = ++Value;
         NumberTextBox.Text = iCurrentValue.ToString();
      }

      private void DownBtn_Click(object sender, RoutedEventArgs e)
      {
         int iCurrentValue = --Value;
         NumberTextBox.Text = iCurrentValue.ToString();
      }
      #endregion

      #region MinimumProperty
      public int Minimum
      {
         get { return (int)GetValue(MinimumProperty); }
         set { SetValue(MinimumProperty, value); }
      }

      private static FrameworkPropertyMetadata ObjMinimumPropertyMetadata = new FrameworkPropertyMetadata(0, OnMinimumChanged);

      private static void OnMinimumChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
      {
         iMinStatic = (int)e.NewValue;
      }

      public static readonly DependencyProperty MinimumProperty =
          DependencyProperty.Register("Minimum", typeof(int), typeof(NumericUpDown), ObjMinimumPropertyMetadata);
      #endregion

      #region MaximumProperty
      public int Maximum
      {
         get { return (int)GetValue(MaximumProperty); }
         set { SetValue(MaximumProperty, value); }
      }

      private static FrameworkPropertyMetadata ObjMaximumPropertyMetadata = new FrameworkPropertyMetadata((int)iMaxStatic, OnMaximumChanged);

      private static void OnMaximumChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
      {
         iMaxStatic = (int)e.NewValue;
      }

      public static readonly DependencyProperty MaximumProperty =
          DependencyProperty.Register("Maximum", typeof(int), typeof(NumericUpDown), ObjMaximumPropertyMetadata);
      #endregion

      #region DecimalPlacesProperty

      public int DecimalPlaces
      {
         get { return (int)GetValue(DecimalPlacesProperty); }
         set { SetValue(DecimalPlacesProperty, value); }
      }
      static readonly FrameworkPropertyMetadata _ObjMetaDecimalPlaces = new FrameworkPropertyMetadata((int)0, OnDecimalPlacesChanged);
      public static readonly DependencyProperty DecimalPlacesProperty =
          DependencyProperty.Register("DecimalPlaces", typeof(int), typeof(NumericUpDown), new PropertyMetadata(0));

      private static void OnDecimalPlacesChanged(DependencyObject sender, DependencyPropertyChangedEventArgs e)
      {
         ((NumericUpDown)sender).SetDecimalPlaces((int)e.NewValue);
      }

      private void SetDecimalPlaces(int newValue)
      {
         string strText = NumberTextBox.Text;
         string[] strResultArr = strText.Split(new char[] { ',', '.' }, StringSplitOptions.RemoveEmptyEntries);

         string strConcat = String.Empty;
         for (int i = 0; i < newValue; ++i)
         {
            strConcat += "0";
         }

         if (strResultArr.Count() != 1)
         {
            string strResult = strResultArr[0] + "." + strResultArr[1] + strConcat;
            NumberTextBox.Text = strResult;
         }
      }
      #endregion
   }
}
