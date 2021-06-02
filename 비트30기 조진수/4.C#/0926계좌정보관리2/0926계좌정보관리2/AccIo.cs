using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0926계좌정보관리2
{
    static class AccIo
    {
        public static void Invoke(bool b)
        {
            try
            {
                Control con = Control.Instance;
                int id = wbLib.inputnumber("입금할 계좌");
                int balance = wbLib.inputnumber("입금액");

                if (b == true)
                    con.InputAccount(id, balance);
                else if (b == false)
                    con.OutputAccount(id, balance);

                Console.WriteLine("입/출금 성공");
            }
            catch (Exception)
            {
                Console.WriteLine("입/출금 실패");
            }
        }
    }
}
