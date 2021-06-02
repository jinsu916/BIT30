using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 자판기
{
    public partial class Form3 : Form
    {
        //음료이름
        public string PName { get; private set; }

        public Form3()
        {
            InitializeComponent();
        }

        public void SetComboBox(List<Drink> dlist)
        {
            String str = string.Empty;
            foreach (Drink d in dlist)
            {
                str = string.Format(d.Name);
                comboBox1.Items.Add(str);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //PName = textBox1.Text;
            PName = comboBox1.SelectedItem.ToString();
            this.DialogResult = DialogResult.OK;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.Cancel;
        }
    }
}
