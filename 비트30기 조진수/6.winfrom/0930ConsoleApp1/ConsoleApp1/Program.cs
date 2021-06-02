using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ConsoleApp1
{
    class FirstForm : Form
    {
        #region 메서드
        private void Form_Load(object sender, EventArgs e)
        {
            Console.WriteLine("윈도우가 Load 됩니다.");
        }

        // 종료 작업 표시 
        private void Form_Closed(object sender, FormClosedEventArgs e)
        {
            Console.WriteLine("윈도우가 Closed 됩니다.");
        }

        private void Form_Closing(object sender, FormClosingEventArgs e)
        {
            DialogResult r = MessageBox.Show("종료?", "알림", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (r == DialogResult.No)
                e.Cancel = true;

            Console.WriteLine("윈도우가 Closing 됩니다.");
            //      e.Cancel = true;
        }

        private void Form_MouseMove(object sender, MouseEventArgs e)
        {
            //Console.WriteLine("MouseMove 이벤트 발생!!!");
            //Console.WriteLine("(x,y)=({0},{1})", e.X, e.Y);
            //this.Text = string.Format("{0},{1}", e.X, e.Y);
        }

        private void Form_MouseClick(object sender, MouseEventArgs e)
        {
            
            this.Text = string.Format("{0},{1}", e.X, e.Y);
        }

        private void Key_Down(object sender, KeyEventArgs e)
        {
            Console.WriteLine("{0}", e.KeyData);
        }

        #endregion

        public FirstForm(string strText)
        {
            #region 맴버필드 초기화
            //속성 초기화 : 생성자에서 담당
            this.Text = strText;
            this.Top = 10;
            this.Left = 10;
            this.Width = 250;
            this.Height = 200;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            //this.Show();            //없으면 화면에 안보임
            #endregion

            #region 이벤트 핸들러 등혹
            this.Load += new System.EventHandler(this.Form_Load);
            this.FormClosed += new FormClosedEventHandler(this.Form_Closed);
            this.FormClosing += new FormClosingEventHandler(this.Form_Closing);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.Form_MouseMove);
            this.MouseClick += new MouseEventHandler(this.Form_MouseClick);
            this.KeyDown += new KeyEventHandler(this.Key_Down);
            #endregion


            this.Show();
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            NewMethod4();
        }

        private static void NewMethod4()
        {
            FirstForm newform = new FirstForm("첫번째폼");
            Application.Run(newform);
        }

        private static void NewMethod3()
        {
            string[] strText = { "빨", "주", "노", "초", "파", "남", "보" };
            Form[] wnd = new Form[7];
            for (int i = 0; i < 7; i++)
            {
                wnd[i] = new Form();
                wnd[i].Text = strText[i];
                wnd[i].SetBounds((i + 1) * 10, (i + 1) * 10, 100, 100);
                wnd[i].MaximizeBox = false;
                wnd[i].Show();
                Console.WriteLine("{0} 번째 윈도우 출력 성공!!!", i);
            }

            Application.Run(wnd[0]);
        }

        private static void NewMethod2()
        {
            Form obj = new Form();
            obj.Text = "Form클래스를 이용한 윈폼";       // 제목표시줄에 글자 출력
            obj.SetBounds(10, 10, 300, 150);            // 윈폼 크기 지정
            obj.MaximizeBox = false;            // 윈도우 버튼 속성 지정
            obj.StartPosition = FormStartPosition.CenterScreen; // 초기 출력위치 
                                                                // 윈폼 크기 지정시 초기 출력위치가 변경됨
            obj.Opacity = 0.5;  //투명도 0~1사이의 실수값                                                    
            Application.Run(obj);
        }

        private static void NewMethod1()
        {
            Application.Run(new Form());
        }

        private static void NewMethod()
        {
            DialogResult r = MessageBox.Show("TEST", "알림", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (r == DialogResult.Yes)
                Console.WriteLine("YES");
            else
                Console.WriteLine("NO");
        }
    }
}
