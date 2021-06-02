using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1001
{
    public partial class Form3 : Form
    {
        Image image = null;     //이미지 초기화

        public Form3()
        {
            InitializeComponent();
            //image = Image.FromFile("C:\\Users\\user\\Pictures\\aaa.png");       //이미지 가져오기
        }

        private void Form3_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.DrawImage(image, 300, 10);       //실행시 그림 출력
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ListBoxAddFileName();
        }

        //해당폴더 파일 읽어오기
        private void ListBoxAddFileName()
        {
            listBox1.Items.Clear();

            DirectoryInfo dinfo =
                new DirectoryInfo("C:\\Users\\user\\Pictures");
            if (dinfo.Exists)  // 디렉토리가 존재하면 
            {
                FileInfo[] files = dinfo.GetFiles(); // 디렉토리 안에 있는 파일 목록 출력
                foreach (FileInfo f in files)    // 파일 이름 출력
                {
                    listBox1.Items.Add(f.Name);
                }
            }
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            string str = listBox1.SelectedItem.ToString();

            SelectImage(str);
            PrintImage(str);
        }

        private void SelectImage(string str)
        {            
            textBox1.Text = str;
        }

        private void PrintImage(string str)
        {
            image = Image.FromFile("C:\\Users\\user\\Pictures\\" + str);
            this.Invalidate();
        }

        //글자 쓰기
        private void button2_Click(object sender, EventArgs e)
        {
            string msg = textBox2.Text;
            //Image imageFile = Image.FromFile("ocean.jpg");
            Graphics grfx = Graphics.FromImage(image);
            Font font = new Font("돋음", 20);
            Brush brush = Brushes.Pink;
            grfx.DrawString(msg, font, brush, 10, 10);
            grfx.Dispose();

            image.Save("C:\\Users\\user\\Pictures\\"+"ocean.bmp", 
                System.Drawing.Imaging.ImageFormat.Bmp);
        }
    }
}
