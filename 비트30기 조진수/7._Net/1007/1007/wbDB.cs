using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1007
{
    public class wbDB
    {
        private SqlConnection conn;

        private string constr1;     //나의 계정
        private string constr2;     //강사님 계정

        #region DB연결
        public wbDB()
        {
            conn = new SqlConnection();

            constr1 = @"Server=desktop-pt816dq;database=
                                wb30;uid=jjs;pwd=1234;";
            constr2 = @"Server=user-pc;database=
                                wb30;uid=ccm;pwd=1234;";

            conn.ConnectionString = constr1;

        }
        public bool Connect()
        {
            try
            {
                conn.Open();
                MessageBox.Show("연결성공");
                return true;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return false;
            }
        }
        public void DisConnect()
        {
            conn.Close();
            MessageBox.Show("연결해제");
        }
        #endregion

        //DDL, INSERT, UPDATE, DELETE
        private bool ExSqlCommand(string comstr)
        {
            SqlCommand scom = new SqlCommand();

            scom.Connection = conn;
            scom.CommandText = comstr;
            scom.CommandType = System.Data.CommandType.Text;

            if (scom.ExecuteNonQuery() > 0)     //DDL, I, U, D
            {
                scom.Dispose();
                return true;
            }
            scom.Dispose();
            return false;
        }

        #region Product
        //SELECT
        public Product SelectProduct(int pid)
        {
            string comtext = string.Format("select * from product where pid = {0}",pid);
            SqlCommand command = new SqlCommand(comtext, conn);
            SqlDataReader reader = command.ExecuteReader();  // S
            if(reader.Read()==false)
            { 
                reader.Close();
                command.Dispose();
                return null;
            }


            Product p = new Product(reader[1].ToString(),
                int.Parse(reader[2].ToString()), 
                reader[3].ToString());
            p.PID = int.Parse(reader[0].ToString());

            reader.Close();
            command.Dispose();
            return p;
        }

        public bool InsertProduct(string pname, int price, string desc)
        {
            string str = string.Format("insert into Product values('{0}',{1},'{2}')",
                pname, price, desc);

            return ExSqlCommand(str);
              

        }

        public bool DeleteProduct(int pid)
        {
            string str = string.Format("delete from Product where PID = {0}", pid);

            return ExSqlCommand(str);
        }

        public bool UpdateProduct(int pid, int price)
        {
            string str = string.Format("update Product set Price = {0} where PID = {1}", price, pid);

            return ExSqlCommand(str);
        }
        #endregion

        #region Custom
        //SELECT
        public Custom SelectCustom(int cid)
        {
            string comtext = string.Format("select * from Custom where CID = {0}", cid);
            SqlCommand command = new SqlCommand(comtext, conn);
            SqlDataReader reader = command.ExecuteReader();  // S
            if (reader.Read() == false)
            {
                reader.Close();
                command.Dispose();
                return null;
            }


            Custom c = new Custom(reader[1].ToString(),
                int.Parse(reader[2].ToString()),
                reader[3].ToString());
            c.CID = int.Parse(reader[0].ToString());

            reader.Close();
            command.Dispose();
            return c;
        }

        public bool InsertCustom(string cname, int phone, string addr)
        {
            string str = string.Format("insert into Custom values('{0}',{1},'{2}')",
                cname, phone, addr);

            return ExSqlCommand(str);
            
        }

        public bool UpdateCustom(int cid, int phone)
        {
            string str = string.Format("update Custom set PHONE = {0} where CID = {1}", phone, cid);

            return ExSqlCommand(str);
        }

        public bool DeleteCustom(int cid)
        {
            string str = string.Format("delete from Custom where CID = {0}", cid);

            return ExSqlCommand(str);
        }
        #endregion

        #region Sale
        //SELECT
        public Sale SelectSale(int sid)
        {
            string comtext = string.Format("select * from Sale where sid = {0}", sid);
            SqlCommand command = new SqlCommand(comtext, conn);
            SqlDataReader reader = command.ExecuteReader();  // S
            if (reader.Read() == false)
            {
                reader.Close();
                command.Dispose();
                return null;
            }


            Sale s = new Sale(int.Parse(reader[1].ToString()),
                int.Parse(reader[2].ToString()),
                int.Parse(reader[3].ToString()),
                reader[4].ToString());
            s.SID = int.Parse(reader[0].ToString());

            reader.Close();
            command.Dispose();
            return s;
        }
        #endregion
    }
}
