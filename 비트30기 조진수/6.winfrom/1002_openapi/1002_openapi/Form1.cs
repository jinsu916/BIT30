using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1002_openapi
{
    public partial class Form1 : Form
    {
        SimageSearcher s = new SimageSearcher();        //이미지
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //이미지찾기
            s.SearchImage(textBox1.Text);
            textBox2.Text = s.XmlString;
            //리스트 박스에 이미지 제목만 출력
            TitlePrint();
        }

        private void TitlePrint()
        {
            listBox1.Items.Clear();
            foreach(Simage simage in s.imagelist)
            {
                listBox1.Items.Add(simage.Title);
            }
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            //타이틀바에 출력
            int idx = listBox1.SelectedIndex;
            string title = listBox1.SelectedItem.ToString();
            string temp = string.Format("순서{0}  제목: {1}", idx, title);
            this.Text = temp;

            //이미지 출력
            string filepath =  s.imagelist[idx].Link;
            byte[] data = new System.Net.WebClient().DownloadData(filepath);
            System.IO.MemoryStream ms = new System.IO.MemoryStream(data);
            Image img = Image.FromStream(ms);

            Graphics gp = this.CreateGraphics();
            gp.DrawImage(img, 600, 40);
        }
    }
}
