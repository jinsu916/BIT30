using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1008성적관리
{
    public partial class Form1 : Form
    {
        private wbDB db = new wbDB();
        public Form1()
        {
            InitializeComponent();
            if (db.Connect() == true)
                groupBox1.Enabled = true;
            TeamPrintAll();
        }

        public void TeamPrintAll()
        {
            listView1.Items.Clear();
            foreach (Team t in db.tlist)
            {
                string sn = t.SNAME;
                string tn = t.Tname;
                string ts = t.Tstartdate;
                string te = t.Tenddate;

                string[] strs = new string[] { sn, tn, ts, te };
                ListViewItem lvi = new ListViewItem(strs);

                listView1.Items.Add(lvi);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int idx;
            if (comboBox1.SelectedIndex == 0)
                idx = 0;
            else
                idx = 1;
            string sn1 = textBox1.Text;
            Team t = db.SelectTeam(sn1,idx);
            if ( t != null)
            {
                listView1.Items.Clear();

                string sn = t.SNAME;
                string tn = t.Tname;
                string ts = t.Tstartdate;
                string te = t.Tenddate;

                string[] strs = new string[] { sn, tn, ts, te };
                ListViewItem lvi = new ListViewItem(strs);

                listView1.Items.Add(lvi);
            }
            else
            {
                MessageBox.Show("없는 아이디");
                listView1.Items.Clear();
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            TeamPrintAll();
        }
    }
}
