using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0924계좌관리프로그램
{
    class app
    {
        control con = new control();

        public void init()
        {
            wbprint.logo();
        }
        public void run()
        {
            while (true)
            {
                Console.Clear();

                //con.printall();
                wbprint.menuprint();
                switch (Console.ReadKey().Key)
                {
                    case ConsoleKey.F1: con.makeaccount(); break;
                    case ConsoleKey.F2: con.deposit(); break;
                    case ConsoleKey.F3: con.withdraw(); break;
                    case ConsoleKey.F4: con.inquire(); break;
                    case ConsoleKey.Escape: return;
                }
                wbprint.pause();
            }
        }

        public void exit()
        {
            wbprint.ending();
        }
    }
}
