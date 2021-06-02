using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0927_조별
{
    class App
    {
        Control con = new Control();
        public void init()
        {
            wbPrint.logo();
        }

        public void run()
        {
            while (true)
            {
                Console.Clear();
                con.Print();
                wbPrint.menuprint();
                switch (Console.ReadKey().Key)
                {
                    case ConsoleKey.F1: con.Getmoney(); break;
                    case ConsoleKey.F2: con.GetProduct(); break;
                    case ConsoleKey.F3: con.GetBalance(); break;
                    case ConsoleKey.Escape: return;
                }
                wbPrint.pause();
            }

        }

        public void exit()
        {
            wbPrint.ending();
        }
    }
}
