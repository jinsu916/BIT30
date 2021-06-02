using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0926계좌정보관리2
{
    static class AccSelect
    {
        static Account acc;

        public static void Invoke()
        {
            Control con = Control.Instance;
            int id = wbLib.inputnumber("검색할 계좌");
            acc = con.SelectAccount(id);
            Print();
        }

        static void Print()
        {
            acc.Print();
        }
    }
}
