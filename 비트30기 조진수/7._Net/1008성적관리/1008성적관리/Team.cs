using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1008성적관리
{
    public class Team
    {
        public int TID { get; set; }
        public string SNAME { get; set; }
        public string Tname { get; set; }
        public string Tstartdate { get; set; }
        public string Tenddate { get; set; }

        public Team(string sn, string tn, string ts, string te)
        {
            SNAME = sn;
            Tname = tn;
            Tstartdate = ts;
            Tenddate = te;
        }
    }
}
