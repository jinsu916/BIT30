using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0930WindowsForm
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
        }

        //시작배경색변경
        protected override void OnPaint(PaintEventArgs pea)
        {
            Graphics grfx = pea.Graphics;
            grfx.FillRectangle(new SolidBrush(Color.Black), this.ClientRectangle);
        }

        //
        private void button1_Click(object sender, EventArgs e)
        {
            Form2 gdie1 = new Form2();
            gdie1.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form3 gdie1 = new Form3();
            gdie1.Show();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Form4 gdie1 = new Form4();
            gdie1.Show();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Form5 gdie1 = new Form5();
            gdie1.Show();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Form6 gdie1 = new Form6();
            gdie1.Show();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            Form7 gdie1 = new Form7();
            gdie1.Show();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            Form8 gdie1 = new Form8();
            gdie1.Show();
        }

        private void button8_Click(object sender, EventArgs e)
        {
            Form9 gdie1 = new Form9();
            gdie1.Show();
        }

        private void button9_Click(object sender, EventArgs e)
        {
            Form10 gdie1 = new Form10();
            gdie1.Show();
        }
    } 
}
