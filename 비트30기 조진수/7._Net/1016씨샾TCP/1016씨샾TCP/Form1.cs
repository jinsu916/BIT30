using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1016씨샾TCP
{
    public partial class Form1 : Form
    {
        Form2 dlg = null;
        Form3 dlg2 = null;
        wbClient server = new wbClient();
        Packet pack = Packet.Instance;
        bool islogin;
        string id = null;

        public Form1()
        {
            InitializeComponent();
            islogin = false;                    //불형고정
            server.ParentInfo(this);        //스레드에서 폼사용
            CheckForIllegalCrossThreadCalls = false;        //크로스스레드

        }

        private void 프로그램종료ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void 서버연결ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            dlg = new Form2();
            if(dlg.ShowDialog() == DialogResult.OK)
            {
                //dlg.IP;
                //dlg.Port;
                if(server.Connect(dlg.IP, dlg.Port) ==true)
                {
                    Ui.FillDrawing(panel1, Color.Blue);
                    Ui.LabelState(label1, true);

                    String temp = String.Format("[연결]{0}:{1} 성공", dlg.IP, dlg.Port);
                    Ui.LogPrint(listBox1, temp);
                }
                else
                {
                    String temp = String.Format("[연결]{0}:{1} 실패", dlg.IP, dlg.Port);
                    Ui.LogPrint(listBox1, temp);
                }
            }
        }

        private void 서버연결해제ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            server.DisConnect();

            Ui.FillDrawing(panel1, Color.Red);
            Ui.LabelState(label1, false);

            String temp = String.Format("[접속해제]{0}:{1} 성공", dlg.IP, dlg.Port);
            Ui.LogPrint(listBox1, temp);
        }

        //전송
        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                String temp = String.Format("[" + id + "]" + textBox2.Text);

                string msg = pack.GetMessage(temp);

                server.Send(msg);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        public void ShortMessage(string str)
        {
            Ui.LogPrint(listBox2, str);
        }

        private void 회원가입ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            dlg2 = new Form3();
            if (dlg2.ShowDialog() == DialogResult.OK)
            {
                string msg = pack.GetNewMember(dlg2.ID, dlg2.PW, dlg2.NAME, int.Parse(dlg2.AGE));
                server.Send(msg);
            }
        }

        //로그인
        private void button2_Click(object sender, EventArgs e)
        {
            id = textBox3.Text;
            string pw = textBox4.Text;
            string msg = pack.GetLogin(id, pw);

            server.Send(msg);
        }

        //로그아웃
        private void button3_Click(object sender, EventArgs e)
        {
            string id = textBox3.Text;
            string msg = pack.GetLogOut(id);

            server.Send(msg);
        }

        //탈퇴
        private void button4_Click(object sender, EventArgs e)
        {
            string id = textBox3.Text;
            string msg = pack.GetDelMember(id);

            server.Send(msg);
        }

        #region 수신패킷 분석
        public void PaserByteDate(byte[] data)
        {
            string msg = Encoding.Default.GetString(data);
            string[] token = msg.Split('@');
            switch (token[0].Trim())
            {
                case "NEWMEMBERACK": NewMemberAck(token[1]); break;
                case "DELMEMBERACK": DeleteAck(token[1]); break;
                case "LOGINACK": LogInAck(token[1]); break;
                case "LOGOUTACK": LogOutAck(token[1]); break;
                case "MESSAGEACK": GetMessageAck(token[1]); break;
            }
        }
        #endregion

        #region 서버->클라이언트
        void NewMemberAck(string msg)
        {
            string[] sp = msg.Split('#');

            if (sp[0] == "True")
            {
                this.Text = "회원가입성공";
            }
            else if (sp[0] == "False")
            {
                this.Text = "회원가입실패";
            }

        }

        void DeleteAck(string msg)
        {
            string[] sp = msg.Split('#');

            if (sp[0] == "True")
            {
                this.Text = "삭제성공";
            }
            else if (sp[0] == "False")
            {
                this.Text = "삭제실패";
            }

        }

        void LogInAck(string msg)
        {
            string[] sp = msg.Split('#');
            if (islogin == false)
            {
                if (sp[0] == "True")
                {
                    id = sp[1];
                    string name = sp[2];
                    this.Text = string.Format("{0}[{1}]님이 로그인성공", id, name);
                    islogin = true;
                }
                else if (sp[0] == "False")
                {
                    this.Text = "로그인실패";
                }
            }

        }

        void LogOutAck(string msg)
        {
            string[] sp = msg.Split('#');

            if (sp[0] == "True")
            {
                this.Text = "로그아웃성공";
                islogin = false;
            }
            else if (sp[0] == "False")
            {
                this.Text = "로그아웃실패";
            }

        }

        void GetMessageAck(string msg)
        {
            if (islogin == true)
            {

                Ui.ChatPrint(listBox3, msg);
            }

        }
        #endregion

    }
}
