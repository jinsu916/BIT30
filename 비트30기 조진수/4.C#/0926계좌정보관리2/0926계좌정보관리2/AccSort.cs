using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0926계좌정보관리2
{
    class AccSort
    {
        public static void Invoke(bool b)
        {
            Control con = Control.Instance;
            Console.WriteLine("저장방식>>");
            string idx = wbLib.inputstring("[1]계좌번호 [2]이름 [3]잔액");

            con.SortAccount(idx);
        }
    }
}
