using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1008성적관리
{
    public class wbDB
    {
        public List<Team> tlist = new List<Team>();

        private SqlConnection conn;

        private string constr1;

        #region DB연결
        public wbDB()
        {
            conn = new SqlConnection();
            constr1 = @"Server=desktop-pt816dq;database=
                                wb30;uid=jjs;pwd=1234;";
            conn.ConnectionString = constr1;
        }
        public bool Connect()
        {
            try
            {
                conn.Open();
                MessageBox.Show("연결성공");
                TeamGetData();
                return true;
            }
            catch(Exception ex)
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

        public void TeamGetData()
        {
            string comtext = string.Format("select s.SNAME, t.TName, t.Tstartdate, t.Tenddate from Team t, Organization o, Student s where o.TID = t.TID and o.SNUM = s.SNUM");

            SqlCommand command = new SqlCommand(comtext, conn);
            SqlDataReader reader = command.ExecuteReader(); // 2.Select 전용

            while (reader.Read() == true)
            {
                tlist.Add(new Team(reader[0].ToString(),
                                   reader[1].ToString(),
                                   reader[2].ToString(),
                                   reader[3].ToString()));
            }
            reader.Close();
            command.Dispose();
        }

        //SELECT
        public Team SelectTeam(string sn,int idx)
        {
            string st = null;
            if (idx == 0)
                st = "s.SNAME";
            else
                st = "t.Tname";
            string comtext = string.Format("select s.SNAME, t.Tname, t.Tstartdate, t.Tenddate from Team t, Organization o, Student s where o.TID = o.TID and {0} = '{1}'", st, sn);
            

            SqlCommand command = new SqlCommand(comtext, conn);
            SqlDataReader reader = command.ExecuteReader();  // S
            if (reader.Read() == false)
            {
                reader.Close();
                command.Dispose();
                return null;
            }

            
            Team t = new Team(reader[0].ToString(),
                reader[1].ToString(),
                reader[2].ToString(),
                reader[3].ToString());

            reader.Close();
            command.Dispose();
            return t;
        }
    }
}
