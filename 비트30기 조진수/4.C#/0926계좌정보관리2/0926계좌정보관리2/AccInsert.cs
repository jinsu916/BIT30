using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0926계좌정보관리2
{
    static class AccInsert
    {
        public static void Invoke()
        {
            try
            {
                Control con = Control.Instance;
                string name = wbLib.inputstring("이름");
                int id = wbLib.inputnumber("계좌번호");
                int balance = wbLib.inputnumber("잔액");

                Account acc = new Account(id, name, balance);
                if (con.AddAccount(acc) == true)
                    Console.WriteLine("저장 성공");
                else
                    Console.WriteLine("저장 실패");
            }
            catch (Exception ex)
            {
                Console.WriteLine("입력 오류");
                Console.WriteLine(">> " + ex.Message);
            }
        }
    }
}
