using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;

namespace _1001
{
    /// <summary>
    /// XML 문서화 
    /// </summary>
    public partial class Form1 : Form
    {
        private XmlWriterSettings xsettings;    //XML 사용하는 데 필요한 구조체(create 개체)
        private XmlWriter xwriter;              //XML 데이터 포함된 스트림 생성해주는 구조체

        public Form1()
        {
            InitializeComponent();              //기초 Form 디자인 구성

            xsettings = new XmlWriterSettings();
            xsettings.Indent = true;            //들여쓰기 여부
        }

        //파일 닫기      
        private void button1_Click(object sender, EventArgs e)
        {
            string filename = textBox1.Text;                    //텍스트박스에서 문자열 받아 저장
            xwriter = XmlWriter.Create(filename, xsettings);    //XML 생성
            this.Text = filename;
        }

        //요소 추가
        private void button3_Click(object sender, EventArgs e)
        {
            xwriter.Close();        //종료
            
        }

        //파일생성
        private void button2_Click(object sender, EventArgs e)
        {
            string msg = textBox2.Text;
            if (msg == string.Empty &&
                comboBox1.SelectedItem.Equals("종료요소") == false)
                return;

            if (comboBox1.SelectedItem.Equals("주석"))
            {
                xwriter.WriteComment(msg);
            }
            else if (comboBox1.SelectedItem.Equals("시작요소"))
            {
                xwriter.WriteStartElement(msg);
            }
            else if (comboBox1.SelectedItem.Equals("값"))
            {
                xwriter.WriteValue(msg);
            }
            else if (comboBox1.SelectedItem.Equals("종료요소"))
            {
                xwriter.WriteEndElement();
            }
            textBox2.Text = "";           
        }

        //XML 읽기
        private void button4_Click(object sender, EventArgs e)
        {
            string filename = textBox1.Text;
            XmlReader xreader = XmlReader.Create(filename); //XmlReader 개체 생성
            StringBuilder msg = new StringBuilder();
            XmlWriter xwriter = XmlWriter.Create(msg);      //콘솔 출력 스트림으로 XmlWriter 개체 생성
            xwriter.WriteNode(xreader, false);              //xreader 개체로 읽어온 데이터를 xwriter 개체에 복사
            xwriter.Close();
            xreader.Close();

            textBox3.Text = msg.ToString();
        }
    }
}
