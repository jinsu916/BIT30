using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0924관리프로그램
{
    class app
    {
        #region 싱글톤 패턴
        private app() { }

        public static app Instance { get; private set; }

        static app()
        {
            Instance = new app();
        }
        #endregion
        control con = new control();

        public void init()
        {
            wbprint.logo();
            con.fileload();
        }
        public void run()
        {
            while(true)
            {
                Console.Clear();

                con.printall();
                wbprint.menuprint();
                switch(Console.ReadKey().Key)
                {
                    case ConsoleKey.F1: con.insert(); break;
                    case ConsoleKey.F2: con.select(); break;
                    case ConsoleKey.F3: con.update(); break;
                    case ConsoleKey.F4: con.delete(); break;
                    case ConsoleKey.F5: con.filesave(); break;
                    case ConsoleKey.F6: con.fileload(); break;
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
