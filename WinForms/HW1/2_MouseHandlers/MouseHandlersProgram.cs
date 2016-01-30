using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2_MouseHandlers
{
    static class MouseHandlersProgram
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new MH_form());
        }

        public static string mouseLeftBtnHandler(Form form, MouseEventArgs mouseEvent) {
            int rectPadding = 10;
            //Внутри воображаемого прямоугольника
            if (mouseEvent.Y < form.ClientSize.Height-rectPadding && mouseEvent.Y > rectPadding
               && mouseEvent.X < form.ClientSize.Width-rectPadding && mouseEvent.X > rectPadding){ 
                return "Вы кликнули по внутренней части рабочей области";
            }
            else
            {
                //Граница прямоугольника
                if(mouseEvent.Y == form.ClientSize.Height - rectPadding || mouseEvent.X == form.ClientSize.Width - rectPadding
                    || mouseEvent.Y == rectPadding || mouseEvent.X == rectPadding) {
                    return "Вы кликнули по границе рабочей области";
                }
                //Снаружи прямоугольника
                else
                {
                    return "Вы кликнули по внешней части рабочей области";
                }
            }
        }

        public static string mouseRightBtnHandler(Form form) {
            return (string)"Раб. область: ширина - " + form.ClientSize.Width + ", высота - " + form.ClientSize.Height;
        }

        public static string mouseMoveInfo(MouseEventArgs mouseEvent) {
            return (string)"Курсор на X: " + mouseEvent.X + ", Y: " + mouseEvent.Y;
        }
        public static void exitProgram() {
            Application.Exit();
        }
    }
}
