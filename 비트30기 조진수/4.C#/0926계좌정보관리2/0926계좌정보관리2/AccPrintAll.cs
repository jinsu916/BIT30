using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0926계좌정보관리2
{
    static class AccPrintAll
    {
        static List<Account> acc;

        public static void Invoke()
        {
            Control con = Control.Instance;
            con.SelectAllAccount(out acc);
            PrintAll();
        }

        static void PrintAll()
        {
            Console.WriteLine("저장개수 : {0}개", acc.Count);
            for (int i = 0; i < acc.Count; i++)
            {
                Account mem = acc[i];
                Console.WriteLine(mem);
            }
        }
    }
}
