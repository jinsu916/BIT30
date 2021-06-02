using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0926계좌정보관리2
{
    static class AccDelete
    {
        public static void Invoke()
        {
            Control con = Control.Instance;
            int id = wbLib.inputnumber("삭제할 계좌");
            if (con.DelAccount(id) == true)
                Console.WriteLine("삭제 성공");
            else
                Console.WriteLine("삭제 실패");
        }
    }
}
