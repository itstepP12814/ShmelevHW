using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1_Resume
{
    static class ResumeProgram
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Resume_form());
        }

        public static void dialogShow() {
            int symbolsCounter = 0;
            int messageCounter = 0;

            string name = "Имя: Константин \nФамилия: Шмелёв";
            string school = "Место учебы: БГМУ";
            string workPlace = "Место работы: БГМУ";
            symbolsCounter += name.Length + school.Length + workPlace.Length;

            DialogResult res1 = MessageBox.Show(name, "ФИО", MessageBoxButtons.OK);
            messageCounter++;
            if (res1 == DialogResult.OK)
            {
                DialogResult res2 = MessageBox.Show(school, "Место учебы", MessageBoxButtons.OK);
                messageCounter++;
                if (res2 == DialogResult.OK)
                {
                    messageCounter++;
                    DialogResult res3 = MessageBox.Show(workPlace + 
                        "\nВы просмотрели " + messageCounter.ToString() + " сообщений, которые состоят из " + symbolsCounter + " знаков", 
                        "Место работы", MessageBoxButtons.OK);
                }
            }
        }
    }
}
