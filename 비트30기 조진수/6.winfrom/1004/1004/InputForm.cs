using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1004
{
    public partial class InputForm : Form
    {
        Form1 form;

        public InputForm(Form1 f)
        {
            InitializeComponent();
            form = f;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int money = int.Parse(comboBox1.SelectedItem.ToString());
            form.InputMoney(money);
        }

        //죽을때 부모가 가지고 있던 객체 정보를 null로 변경
        //해당 코드가 없으면 모달리스 다이얼로그 종료 후 다시 실행이 안됨.
        private void InputForm_FormClosed(object sender, FormClosedEventArgs e)
        {
            form.frm = null;
        }
    }
}
