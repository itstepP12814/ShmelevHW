using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MdiExample
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void ColorsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ColorsForm cf = new ColorsForm();
            cf.MdiParent = this;
            cf.WindowState = FormWindowState.Maximized;
            cf.Show();
        }

        private void режим1ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            foreach (var mdiChild in this.MdiChildren)
            {
                mdiChild.WindowState = FormWindowState.Minimized;
            }
        }

        private void режим2ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            foreach (var mdiChild in MdiChildren)
            {
                if (mdiChild.WindowState != FormWindowState.Normal)
                {
                    mdiChild.WindowState = FormWindowState.Normal;
                }
            }
            this.LayoutMdi(MdiLayout.Cascade);

        }
    }
}
