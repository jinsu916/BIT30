using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0930WindowsForm
{
    public partial class Form0 : Form
    {
        public Form0()
        {

        }
    }
    public partial class Form2 : Form
    {
        public Form2()
        {
            this.Text = "Graphics 개체 얻기1";

            //paint 이벤트 핸들러 등록
            this.Paint += new PaintEventHandler(GDIExam_Paint);
        }
        public void GDIExam_Paint(object sender, PaintEventArgs pea)
        {
            Graphics grfx = pea.Graphics;
            grfx.FillRectangle(new SolidBrush(Color.Blue), this.ClientRectangle);
        }
    }
    public partial class Form3 : Form
    {
        Button btn = null;
        public Form3()
        {
            this.Text = "Graphics 개체 얻기3";
            btn = new Button();
            btn.Text = "버튼위에 GDI+ 출력";
            btn.SetBounds(10, 10, 200, 100);
            btn.Click += new EventHandler(btn_Click);
            this.Controls.Add(btn);


        }
        public void btn_Click(object sender, EventArgs e)
        {
            Graphics grfx = btn.CreateGraphics();
            grfx.FillRectangle(new SolidBrush(Color.Blue), btn.ClientRectangle);
            grfx.Dispose();
            // Dispose()시키지 않으면 해당 개체의 Graphics 리소스가 회수되지 않기
            // 때문에 시스템에 문제를 일으킬 수 있슴 // 아래 구문이 더 깔끔함
            // using(Graphics grfx = btn.CreateGraphics()) 
            // { 
            // grfx.FillRectangle(new SolidBrush(Color.Blue), this.ClientRectangle);
            // }
        }

    }
    public partial class Form4 : Form
    {
        ListBox lstbox = null;
        public Form4()
        {
            this.Text = "Graphics 개체 얻기4";
            lstbox = new ListBox();
            lstbox.SetBounds(10, 10, 200, 100);
            lstbox.Items.Add("사과");
            lstbox.Items.Add("포도");
            lstbox.Items.Add("수박");
            lstbox.DrawItem += new DrawItemEventHandler(GDIExam_DrawItem);
            lstbox.MeasureItem += new MeasureItemEventHandler(GDIExam_MeasureItem);
            this.Controls.Add(lstbox);
            this.Load += new EventHandler(GDIExam_Load);

        }
        private void GDIExam_Load(object sender, EventArgs e)
        {
            lstbox.DrawMode = DrawMode.OwnerDrawVariable;
            //lstbox.DrawMode = DrawMode.OwnerDrawFixed; 
        }
        // 먼저 호출됨
        private void GDIExam_MeasureItem(object sender, MeasureItemEventArgs e)
        {
            Graphics g = e.Graphics;
            Console.WriteLine("{0} : MeasureItem 이벤트 실행", e.ToString());
        }
        // ListBox가 다시 그려질 때마다 호출됨(데이터 갯수만큼 호출됨)
        private void GDIExam_DrawItem(object sender, DrawItemEventArgs e)
        {
            Graphics g = e.Graphics;
            Brush brush = Brushes.Black;
            switch (e.Index)
            {
                case 0: brush = Brushes.Red;
                    break;
                case 1: brush = Brushes.Violet;
                    break;
                case 2: brush = Brushes.Green; break;
            }
            g.DrawString(lstbox.Items[e.Index].ToString(), e.Font, brush, e.Bounds, StringFormat.GenericDefault);
            Console.WriteLine("{0} : DrawItem 이벤트 실행", e.ToString());
        }
    }
    public partial class Form5 : Form
    {
        Button btn = null;
        Image image = null;
        public Form5()
        {
            this.Text = "Graphics 개체 얻기5";
            btn = new Button(); btn.Text = "그림위에 글씨 쓰기";
            btn.SetBounds(10, 100, 200, 100);
            btn.Click += new EventHandler(btn_Click);
            this.Controls.Add(btn);
        }
        protected override void OnPaint(PaintEventArgs e)
        {
            Graphics grfx = e.Graphics;
            if (image != null) grfx.DrawImage(image, 0, 0);
        }
        public void btn_Click(object sender, EventArgs e)
        {
            Image imageFile = Image.FromFile("C:/Users/bit/Desktop/ocean.jpg");
            Graphics grfx = Graphics.FromImage(imageFile);
            Font font = new Font("돋음", 20);
            Brush brush = Brushes.Pink;
            grfx.DrawString("이미지에 글자쓰기", font, brush, 10, 10); grfx.Dispose();
            imageFile.Save("C:/Users/bit/Desktop/ocean.gif", System.Drawing.Imaging.ImageFormat.Gif); //System.Drawing.Imaging.ImageFormat.Gif 확장자 변환가능
            this.image = Image.FromFile("C:/Users/bit/Desktop/ocean.gif"); this.Invalidate(this.ClientRectangle);
        }

    }


    public partial class Form6 : Form
    {
        public Form6()
        {
            this.Text = "그래픽 그리기";
            this.Size = new Size(200, 200);

        }
        protected override void OnPaint(PaintEventArgs pea)
        {
            Graphics g = pea.Graphics;
            Pen pen = new Pen(Color.Black, 2);
            g.DrawLine(pen, 10, 10, 190, 190);
            g.DrawRectangle(pen, 10, 10, 100, 100);
            g.DrawEllipse(pen, 50, 50, 100, 100);
            g.DrawArc(pen, 100, 100, 80, 80, 0, -90);
        }

    }
    public partial class Form7 : Form
    {
        Point[] point1 = new Point[5];
        Point[] point2 = new Point[3];

        public Form7()
        {
            this.Text = "다각형과 타원 그리기";
            this.Size = new Size(300, 400);
            point1[0] = new Point(10, 20);
            point1[1] = new Point(20, 70);
            point1[2] = new Point(50, 100);
            point1[3] = new Point(10, 150);
            point1[4] = new Point(100, 100);
            point2[0] = new Point(100, 10);
            point2[1] = new Point(10, 100);
            point2[2] = new Point(190, 100);

        }
        protected override void OnPaint(PaintEventArgs pea)
        {
            Graphics g = pea.Graphics; Pen pen = new Pen(Color.Red, 2);// 빨간색2의 두께를 갖는 선으로 
            g.DrawPolygon(pen, point1);// 5개 점을 경유하는 다각형 그림
            pen = new Pen(Color.Blue, 3);// 파랑색 3의 두께를 갖는 선으로
            g.DrawPolygon(pen, point2);   // 3개의 점을 경유하는 다각형
            pen = new Pen(Color.Black, 1);// 두께 1의 검은색 선으로
            for (int i = 0; i < 200; i += 20)    // 9개의 타원을 그림 
            {
                g.DrawEllipse(pen, 70, 130, i, i + 50);

            }
        }
    }
    public partial class Form8 : Form
    {
        Point[] point = new Point[3];
        public Form8()
        {
            this.Text = "FillXXX 계열 메서드";
            point[0] = new Point(100, 10);
            point[1] = new Point(10, 100);
            point[2] = new Point(190, 100);

        }
        protected override void OnPaint(PaintEventArgs pea)
        {
            Graphics g = pea.Graphics; g.FillEllipse(Brushes.Brown, 10, 100, 50, 50);// 채워진 타원 그리기
            GraphicsPath graphPath = new GraphicsPath(); graphPath.AddEllipse(0, 0, 150, 100);// 타원 등록 
            g.FillPath(Brushes.Red, graphPath);// FilPath를 사용해 영역을 그림
            g.FillPie(Brushes.Yellow, 200, 10, 100, 100, 90, 180);
            g.FillPolygon(Brushes.Green, point);
            g.FillRectangle(Brushes.Magenta, 50, 150, 100, 100);
            Rectangle fillRect = new Rectangle(150, 150, 100, 100);
            Region fillRegion = new Region(fillRect);
            g.FillRegion(Brushes.Orange, fillRegion);
        }

    }
    public partial class Form9 : Form
    {
        public Form9()
        {
            this.Text = "그라데이션 효과주기";

        }
        protected override void OnPaint(PaintEventArgs pea)
        {
            Graphics g = pea.Graphics; for (int i = 0; i < 256; i++)
            {
                // 색상을 바꿔가며, 좌측 상단에서 대각선 방향으로 선을 그림 
                g.DrawLine(new Pen(Color.FromArgb(i, 0, 0)), 10, 10, 265 - i, 10 + i);
            }
        }
    }
    public partial class Form10 : Form
    {
        public Form10()
        {
            this.Text = "얼굴 그리기";

        }
        protected override void OnPaint(PaintEventArgs pea)
        {
            Graphics g = pea.Graphics; g.DrawArc(Pens.Black, 70, 20, 130, 180, 180, -180);  // 아랫턱 그리기
            for (int i = 0; i < 15; i++)
            {
                // 머리카락그리기
                g.DrawArc(Pens.Brown, 50 + 2 * i, 50, 100, 160, 130, 80);
                g.DrawArc(Pens.Brown, 20 + 2 * i, 50, 190, 160, 140, 100);
                g.DrawArc(Pens.Brown, 90 + 2 * i, 50, 100, 160, 200, 260);
                g.DrawArc(Pens.Brown, 80 + 3 * i, 50, 100, 90, 130, 80);
            }
            g.DrawEllipse(Pens.Black, 90, 120, 20, 25);         // 눈 
            g.DrawEllipse(Pens.Black, 155, 120, 20, 25);        // 눈
            g.FillEllipse(Brushes.Blue, 93, 130, 15, 15);       // 눈동자 
            g.FillEllipse(Brushes.Blue, 158, 130, 15, 15);      // 눈동자
            g.DrawArc(Pens.Black, 110, 150, 50, 40, 0, 180);
        }

    }
}
