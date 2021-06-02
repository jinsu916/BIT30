using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1007
{
    public class Custom
    {
        public int CID { get; set; }
        public string CNAME { get; private set; }
        public int PHONE { get; set; }
        public string ADDR { get; set; }

        public Custom (string cname, int phone, string addr)
        {
            CNAME = cname;
            PHONE = phone;
            ADDR = addr;
        }
    }
}
