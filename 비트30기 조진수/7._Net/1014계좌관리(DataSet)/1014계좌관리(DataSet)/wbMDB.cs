using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1014계좌관리_DataSet_
{
    class wbMDB
    {
        private DataTable dt = null;
        private DataRow dr = null;
        readonly string fname = "account.xml";

        public bool CreateAccTable()
        {
            try
            {
                //테이블 생성
                dt = new DataTable("Account");

                //accid 컬럼
                DataColumn dc_accid = new DataColumn();
                dc_accid.ColumnName = "ACCID";
                dc_accid.DataType = typeof(int);
                dc_accid.AllowDBNull = false;
                dc_accid.AutoIncrement = true;
                dc_accid.AutoIncrementSeed = 1;
                dc_accid.AutoIncrementStep = 1;
                dt.Columns.Add(dc_accid);

                //accnumber 컬럼
                DataColumn dc_accnumber = new DataColumn();
                dc_accnumber.ColumnName = "ACCNUMBER";
                dc_accnumber.DataType = typeof(int);
                dc_accnumber.AllowDBNull = false;
                dc_accnumber.Unique = true;
                dt.Columns.Add(dc_accnumber);

                //cname 컬럼
                DataColumn dc_cname = new DataColumn();
                dc_cname.ColumnName = "CNAME";
                dc_cname.DataType = typeof(string);
                dt.Columns.Add(dc_cname);

                //balance 컬럼
                DataColumn dc_balance = new DataColumn();
                dc_balance.ColumnName = "BALANCE";
                dc_balance.DataType = typeof(int);
                dc_balance.DefaultValue = 0;
                dc_balance.AllowDBNull = false;
                dt.Columns.Add(dc_balance);
                
                //date 컬럼
                DataColumn dc_date = new DataColumn();
                dc_date.ColumnName = "DATE";
                dc_date.DataType = typeof(DateTime);
                dc_date.AllowDBNull = false;
                dt.Columns.Add(dc_date);

                DataColumn[] pkeys = new DataColumn[1];
                pkeys[0] = dc_accid;
                dt.PrimaryKey = pkeys;

                return true;
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
                return false;
            }

        }

        public string ViewAccTable()
        {
            string str = string.Empty;

            str += "테이블 명 : " + dt.TableName + "\r\n";
            str += "컬럼 개수 : " + dt.Columns.Count + "\r\n";
            str += "==============================================\r\n";


            foreach (DataColumn dc in dt.Columns)
            {
                str += string.Format("{0}\t\t{1}\r\n",
                    dc.ColumnName, dc.DataType);
            }
            return str;
        }

        public void AddAccount(int accn, string cn, int bal)
        {
            try
            {
                dr = dt.NewRow();
                dr["ACCNUMBER"] = accn;
                dr["CNAME"] = cn;
                dr["BALANCE"] = bal;
                dr["DATE"] = DateTime.Now;
                dt.Rows.Add(dr);
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        public string ViewAccData()
        {
            string str = string.Empty;
            int row_count = dt.Rows.Count;

            str += "테이블명 : " + dt.TableName + "\r\n";
            str += "행 개수 : " + row_count + "\r\n";
            str += "============================================\r\n";

            for(int i = 0; i< row_count; i++)
            {
                dr = dt.Rows[i];
                foreach (DataColumn dc in dt.Columns)
                {
                    str += string.Format("{0}\t\t{1}\r\n",
                        dc.ColumnName, dr[dc]);
                }
                str += "============================================\r\n";
            }
            
            return str;
        }

        public void SaveAccountXML()
        {
            dt.WriteXmlSchema("account.xsd", true);
            dt.WriteXml(fname, true);
        }

        public void FindAccount(int accid)
        {
            dr = dt.Rows.Find(accid);
            if(dr == null)
            {
                MessageBox.Show("실패");
                return;
            }
            
        }

        public void RemoveAccount(int accid)
        {
            try
            {
                dr = dt.Rows.Find(accid);
                dt.Rows.Remove(dr);
                MessageBox.Show("삭제완료");

            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    } 
}
