using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0924관리프로그램
{
    class Program
    {
        static void Main(string[] args)
        {
            //member[] memlist = new member[3];
            //memlist[0] = new member("홍길동", "111", enumdept.COM, 1);
            //memlist[1] = new member("이길동", "222", enumdept.IT, 2);
            //memlist[2] = new member("고길동", "333", enumdept.GAME, 3);

            //filesave(memlist, 3);

            //member[] memlist1;
            //memlist1 = fileload();

            ////결과 출력
            //Console.WriteLine("결과출력");
            //for (int i = 0; i < memlist1.Length; i++)
            //{
            //    Console.WriteLine(memlist1[i]);
            //}

            app ap = app.Instance;
            ap.init();
            ap.run();
            ap.exit();
        }
    }
}