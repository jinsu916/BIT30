using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 자판기
{
    public partial class Form2 : Form
    {
        Form1 form;

        public Form2(Form1 f)
        {
            InitializeComponent();
            form = f;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //콤보박스로 받기
            int money = int.Parse(comboBox1.SelectedItem.ToString());
            form.InputMoney(money);
            //텍스트박스로 받기
            //int monet = int.Parse(textBox1.Text);
            //form.InputMoney(monet);
        }

        //죽을때 부모가 가지고 있던 객체 정보를 null로 변경
        //해당 코드가 없으면 모달리스 다이얼로그 종료 후 다시 실행이 안됨.
        private void Form2_FormClosed(object sender, FormClosedEventArgs e)
        {
            form.frm = null;
        }
    }
}
