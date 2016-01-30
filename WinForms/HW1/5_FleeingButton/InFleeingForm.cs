using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _5_FleeingButton
{
    public partial class InFleeingForm : Form {
        private Random rand;
        private int Xpos;
        private int Ypos;
        public InFleeingForm()
        {
            InitializeComponent();
            rand = new Random();
            Xpos = rand.Next(0, ClientSize.Width);
            Ypos = rand.Next(0, ClientSize.Height);
            button1.MouseHover += button1_Hover;
        }

        private void button1_Hover(object sender, EventArgs e) {
            button1.Location = new Point(Xpos, Ypos);
            Xpos = rand.Next(0, ClientSize.Width);
            Ypos = rand.Next(0, ClientSize.Height);
        }
    }
}
