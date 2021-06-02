using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1002_openapi
{
    public partial class Form2 : Form
    {
        SmovieSearcher s = new SmovieSearcher();
        public Form2()
        {
            InitializeComponent();
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            //타이틀바에 출력
            int idx = listBox1.SelectedIndex;
            string title = listBox1.SelectedItem.ToString();
            string temp = string.Format("순서{0}  제목: {1}", idx, title);
            this.Text = temp;

            //이미지 출력
            string filepath = s.movielist[idx].Image;
            pictureBox1.Load(filepath);

            //배우 
            listBox2.Items.Clear();
            string filepath1 = s.movielist[idx].Actor;
            listBox2.Items.Add(filepath1);

            //영어제목
            textBox3.Clear();
            string filepath2 = s.movielist[idx].Subtitle;
            textBox3.Text = filepath2;

            //개봉일
            textBox4.Clear();
            string filepath3 = s.movielist[idx].PubDate;
            textBox4.Text = filepath3;

            //감독 
            textBox5.Clear();
            string filepath4 = s.movielist[idx].Director;
            textBox5.Text = filepath4;

            //평점
            textBox6.Clear();
            string filepath5 = s.movielist[idx].UserRating.ToString();
            textBox6.Text = filepath5;

            //동영상재생
            axWindowsMediaPlayer1.URL = filepath;
            axWindowsMediaPlayer1.Ctlcontrols.play();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            s.SearchMovie(textBox1.Text);
            //textBox2.Text = s.XmlString;
            //리스트 박스에 이미지 제목만 출력
            TitlePrint();

        }

        private void TitlePrint()
        {
            listBox1.Items.Clear();
            foreach (Smovie smovie in s.movielist)
            {
                listBox1.Items.Add(smovie.Title);
            }
            listBox2.Items.Clear();
            foreach (Smovie smovie in s.movielist)
            {
                listBox2.Items.Add(smovie.Actor);
            }
            textBox3.Clear();
            foreach (Smovie smovie in s.movielist)
            {
                textBox3.Text = smovie.Subtitle;
            }
            textBox4.Clear();
            foreach (Smovie smovie in s.movielist)
            {
                textBox4.Text = smovie.PubDate;
            }
            textBox5.Clear();
            foreach (Smovie smovie in s.movielist)
            {
                textBox5.Text = smovie.Director;
            }
            textBox6.Clear();
            foreach (Smovie smovie in s.movielist)
            {
                textBox6.Text = smovie.UserRating.ToString();
            }

        }
    }
}
