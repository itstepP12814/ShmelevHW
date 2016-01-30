using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MainProcessApp
{
   public partial class MainProcessWindow : Form {
      private const uint WM_SETTEXT = 0x0C;

      public MainProcessWindow()
      {
         InitializeComponent();
      }


   }
}
