using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0926계좌정보관리2
{
    class App
    {

        public void init()
        {
            wbPrint.logo();
        }
        public void run()
        {
            while (true)
            {
                Console.Clear();
                AccPrintAll.Invoke();
                wbPrint.menuprint();
                switch (Console.ReadKey().Key)
                {
                    case ConsoleKey.F1: AccInsert.Invoke(); break;
                    case ConsoleKey.F2: AccIo.Invoke(true); break;
                    case ConsoleKey.F3: AccIo.Invoke(false); break;
                    case ConsoleKey.F4: AccSelect.Invoke(); break;
                    case ConsoleKey.F5: AccPrintAll.Invoke(); break;
                    case ConsoleKey.F6: AccDelete.Invoke(); break;
                    case ConsoleKey.F7: AccSort.Invoke(true); break;
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
