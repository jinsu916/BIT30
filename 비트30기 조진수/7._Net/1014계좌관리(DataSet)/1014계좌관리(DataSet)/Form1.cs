using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1014계좌관리_DataSet_
{
    public partial class Form1 : Form
    {
        wbMDB mdb = new wbMDB();
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(mdb.CreateAccTable() == true)
            {
                string str = mdb.ViewAccTable();
                textBox1.Text = str; 
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int accn = int.Parse(textBox2.Text);
            string cn = textBox3.Text;
            int bal = int.Parse(textBox4.Text);

            mdb.AddAccount(accn, cn, bal);
            string str = mdb.ViewAccData();
            textBox5.Text = str;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            mdb.SaveAccountXML();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            int acid = int.Parse(textBox11.Text);

            mdb.FindAccount(acid);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            int acid = int.Parse(textBox11.Text);

            mdb.RemoveAccount(acid);

            string str = mdb.ViewAccData();
            textBox5.Text = str;
        }

    }
}
