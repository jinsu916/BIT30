﻿using System;
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
    public partial class Form1 : Form
    {
        private Machine ma = new Machine();

        //모달리스 폼
        public InputForm frm = null;

        public Form1()
        {
            InitializeComponent();

            SetData();
            SetDrink();
        }

        #region 메뉴 핸들러 
        private void 프로그램종료ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void 금액투입IToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (frm == null)
            {
                frm = new InputForm(this);
                frm.Show();
            }
            else
            {
                frm.Focus();
            }
        }

        private void 제품선택SToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SelForm form = new SelForm();
            form.SetComboBox(ma.dlist);
            DialogResult result = form.ShowDialog();
            if(result == DialogResult.OK)
            {
                ma.SelectDrink(form.PName);
                SetData();
            }
        }
        #endregion 

        #region 기능함수 
        //부모 초기화(생성자에서 호출)
        private void SetDrink()
        {
            for (int i = 0; i<ma.dlist.Count; i++ )
            {
                Drink d = ma[i];
                ListViewItem item = new ListViewItem(d.Name);
                //item.ImageIndex = i++;
                item.SubItems.Add(d.Price.ToString());
                item.SubItems.Add(d.Count.ToString());
                listView1.Items.Add(item);
            }
        }

        //부모 초기화(생성자, InputMoney에서 호출)
        private void SetData()
        {
            label1.Text = string.Format("판매 총 수량 {0}개", ma.Count);
            label2.Text = string.Format("판매 총 금액 {0}개", ma.TotalSel);
            label3.Text = string.Format("투입금액     {0}개", ma.Money);
        }

        //모달리스에서 호출
        public void InputMoney(int money)
        {
            try
            {
                ma.InputMoney(money);
                SetData();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {
            ListView.SelectedListViewItemCollection breakfast =
                            this.listView1.SelectedItems;
            
            foreach (ListViewItem item in breakfast)
            {
                string name = item.SubItems[0].Text;
                foreach (Drink d in ma.dlist)
                {
                    if (d.Name.Equals(name))
                    {
                        textBox1.Text = d.Name;
                        textBox2.Text = d.Price.ToString();
                        textBox3.Text = d.Count.ToString();
                        textBox4.Text = d.SelCount.ToString();
                        textBox5.Text = d.GetSel().ToString();
                    }
                }
            }
        }
        #endregion
    }
}
