using System.Windows.Forms;

namespace _2_MouseHandlers
{
    public partial class MH_form : Form
    {
        public MH_form()
        {
            InitializeComponent();
            MouseClick+= MH_form_click;
            MouseMove += MH_form_move;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void MH_form_click(object sender, MouseEventArgs e)
        {
            if(e.Button == MouseButtons.Left) {
                if(ModifierKeys != Keys.Control)
                    label2.Text = MouseHandlersProgram.mouseLeftBtnHandler(this, e);
                else
                    MouseHandlersProgram.exitProgram();
            }
            if(e.Button == MouseButtons.Right) {
                string info = MouseHandlersProgram.mouseRightBtnHandler(this);
                MessageBox.Show(info, "Информация о клиентской области", MessageBoxButtons.OK);
            }
        }

        private void MH_form_move(object sender, MouseEventArgs e) {
            Text = MouseHandlersProgram.mouseMoveInfo(e);
        }
    }
}
