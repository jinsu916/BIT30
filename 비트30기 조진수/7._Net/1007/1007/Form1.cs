using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace _1007
{
    public partial class Form1 : Form
    {
        private wbDB db = new wbDB();
        public Form1()
        {
            InitializeComponent();
            ButtonState(true, false);
            PuttonState(false, false, false, false);
            CuttonState(false, false, false, false);
            SuttonState(false, false, false, false);
        }

        #region 연결 및 해제
        private void button1_Click(object sender, EventArgs e)
        {
            if (db.Connect() == true)
            {
                //데이터그리드에 테이블 가져오기
                this.saleTableAdapter2.Fill(this.wb30DataSet4.Sale);
                this.customTableAdapter.Fill(this.wb30DataSet1.Custom);
                this.productTableAdapter.Fill(this.wb30DataSet.Product);

                ButtonState(false, true);
                PuttonState(true, true, true, true);
                CuttonState(true, true, true, true);
                SuttonState(true, true, true, true);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            db.DisConnect();
            ButtonState(true, false);
            PuttonState(false, false, false, false);
            CuttonState(false, false, false, false);
            SuttonState(false, false, false, false);
        }
        #endregion

        #region 버튼상태정보
        //버튼 온오프 설정
        private void ButtonState(bool b1, bool b2)
        {
            button1.Enabled = b1;
            button2.Enabled = b2;
        }

        private void PuttonState(bool b1, bool b2, bool b3, bool b4)
        {
            button3.Enabled = b1;
            button4.Enabled = b2;
            button5.Enabled = b3;
            button6.Enabled = b4;
        }

        private void CuttonState(bool b1, bool b2, bool b3, bool b4)
        {
            button7.Enabled = b1;
            button8.Enabled = b2;
            button9.Enabled = b3;
            button10.Enabled = b4;
        }

        private void SuttonState(bool b1, bool b2, bool b3, bool b4)
        {
            button11.Enabled = b1;
            button12.Enabled = b2;
            button13.Enabled = b3;
            button14.Enabled = b4;
        }
        #endregion

        #region 제품에대한 버튼핸들러
        //검색
        private void button4_Click(object sender, EventArgs e)
        {
            int pid = int.Parse(textBox1.Text);
            Product p = db.SelectProduct(pid);
            if( p!= null)
            {
                productTableAdapter.Fill(this.wb30DataSet.Product);     //실시간초기화
                textBox1.Text = p.PID.ToString();
                textBox2.Text = p.PNmae;
                textBox3.Text = p.Pric.ToString();
                textBox4.Text = p.Description;
            }
            else
            {
                MessageBox.Show("없는 아이디");
                textBox1.Text = string.Empty;
                textBox2.Text = string.Empty;
                textBox3.Text = string.Empty;
                textBox4.Text = string.Empty;
            }
        }
        
        //저장
        private void button3_Click(object sender, EventArgs e)
        {
            string pname = textBox2.Text;
            int price = int.Parse(textBox3.Text);
            string desc = textBox4.Text;

            if(db.InsertProduct(pname,price,desc)==true)
            {
                productTableAdapter.Fill(this.wb30DataSet.Product);
                textBox1.Text = string.Empty;
                textBox2.Text = string.Empty;
                textBox3.Text = string.Empty;
                textBox4.Text = string.Empty;
            }
            else
            {
                MessageBox.Show("저장실패");
            }
        }

        //삭제
        private void button5_Click(object sender, EventArgs e)
        {
            int pid = int.Parse(textBox1.Text);

            if(db.DeleteProduct(pid)==true)
            {
                productTableAdapter.Fill(this.wb30DataSet.Product);
                textBox1.Text = string.Empty;
                textBox2.Text = string.Empty;
                textBox3.Text = string.Empty;
                textBox4.Text = string.Empty;
            }
            else
            {
                MessageBox.Show("삭제실패");
            }
        }

        //수정
        private void button6_Click(object sender, EventArgs e)
        {
            int pid = int.Parse(textBox1.Text);
            int price = int.Parse(textBox3.Text);

            if (db.UpdateProduct(pid, price) == true)
            {
                productTableAdapter.Fill(this.wb30DataSet.Product);
                textBox1.Text = string.Empty;
                textBox2.Text = string.Empty;
                textBox3.Text = string.Empty;
                textBox4.Text = string.Empty;
            }
            else
            {
                MessageBox.Show("수정실패");
            }
        }

        #endregion

        #region 고객에대한 버튼핸들러
        
        //검색
        private void button7_Click(object sender, EventArgs e)
        {
            int cid = int.Parse(textBox5.Text);
            Custom c = db.SelectCustom(cid);
            if (c != null)
            {
                customTableAdapter.Fill(this.wb30DataSet1.Custom);
                textBox5.Text = c.CID.ToString();
                textBox6.Text = c.CNAME;
                textBox7.Text = c.PHONE.ToString();
                textBox8.Text = c.ADDR;
            }
            else
            {
                MessageBox.Show("없는 아이디");
                textBox5.Text = string.Empty;
                textBox6.Text = string.Empty;
                textBox7.Text = string.Empty;
                textBox8.Text = string.Empty;
            }
        }

        //삭제
        private void button8_Click(object sender, EventArgs e)
        {
            int cid = int.Parse(textBox5.Text);

            if (db.DeleteCustom(cid) == true)
            {
                customTableAdapter.Fill(this.wb30DataSet1.Custom);
                textBox5.Text = string.Empty;
                textBox6.Text = string.Empty;
                textBox7.Text = string.Empty;
                textBox8.Text = string.Empty;
            }
            else
            {
                MessageBox.Show("삭제실패");
            }
        }

        //저장
        private void button9_Click(object sender, EventArgs e)
        {
            string cname = textBox6.Text;
            int phone = int.Parse(textBox7.Text);
            string addr = textBox8.Text;

            if (db.InsertCustom(cname, phone, addr) == true)
            {
                customTableAdapter.Fill(this.wb30DataSet1.Custom);
                textBox5.Text = string.Empty;
                textBox6.Text = string.Empty;
                textBox7.Text = string.Empty;
                textBox8.Text = string.Empty;
            }
            else
            {
                MessageBox.Show("저장실패");
            }
        }

        //수정
        private void button10_Click(object sender, EventArgs e)
        {
            int cid = int.Parse(textBox5.Text);
            int phone = int.Parse(textBox7.Text);

            if(db.UpdateCustom(cid, phone)==true)
            {
                customTableAdapter.Fill(this.wb30DataSet1.Custom);
                textBox5.Text = string.Empty;
                textBox6.Text = string.Empty;
                textBox7.Text = string.Empty;
                textBox8.Text = string.Empty;
            }
            else
            {
                MessageBox.Show("수정실패");
            }
        }

        #endregion

        #region 판매에대한 버튼핸들러

        private void textBox12_TextChanged(object sender, EventArgs e)
        {

        }

        //검색
        private void button11_Click(object sender, EventArgs e)
        {
          
            int sid = int.Parse(textBox9.Text);
            Sale s = db.SelectSale(sid);
            if( s!= null)
            {
                saleTableAdapter2.Fill(this.wb30DataSet4.Sale);     //실시간초기화
                textBox9.Text = s.SID.ToString();
                comboBox1.Text = s.PID.ToString();
                comboBox2.Text = s.CID.ToString();
                textBox12.Text = s.COUNT.ToString();
            }
            else
            {
                MessageBox.Show("없는 아이디");
                textBox9.Text = string.Empty;
                comboBox1.Text = string.Empty;
                comboBox2.Text = string.Empty;
                textBox12.Text = string.Empty;
            }
        }

        #endregion
    }
}
