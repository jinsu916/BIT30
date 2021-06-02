using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1007
{
    public class Sale
    {
        public int SID { get; set; }
        public int CID { get; private set; }
        public int PID { get; private set; }
        public int COUNT { get; set; }
        public string Saledate { get; private set; }

        public Sale(int cid, int pid, int count, string sdate)
        {
            CID = cid;
            PID = pid;
            COUNT = count;
            Saledate = sdate;
        }
    }
}
