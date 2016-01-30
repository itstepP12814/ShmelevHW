using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SampleProcess
{
   public partial class Form1 : Form {
      private ProcessStartInfo objStartInfo;
      public Form1()
      {
         InitializeComponent();
         MyProcess.StartInfo = new ProcessStartInfo("notepad.exe");
      }

      private void startBtn_Click(object sender, EventArgs e) {
         MyProcess.Start();
      }

      private void stopBtn_Click(object sender, EventArgs e) {
         MyProcess.CloseMainWindow();
         MyProcess.Close();

      }
   }

   
}
