using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExamTest
{
    class App
    {
        Control con = Control.Instance;

        public static App Instance
        {
            get; private set;
        }

        static App()
        {
            Instance = new App();
        }
        private App()
        {
        }

        public void init()
        {
            Console.Clear();
            Console.WriteLine("*********************************************");
            Console.WriteLine("2019.9.30");
            Console.WriteLine("우송비트고급30기 C#언어과정");
            Console.WriteLine("C# 시험과제");
            Console.WriteLine("JJS");
            Console.WriteLine("*********************************************");
            pause();
        }

        public void run()
        {
            while (true)
            {
                Console.Clear();
                con.CPrintAll();
                Console.WriteLine("*********************************************");
                Console.WriteLine("[F1] 책 저장");
                Console.WriteLine("[F2] 전체출력");
                Console.WriteLine("[F3] 책 검색");
                Console.WriteLine("[F4] 판매량 수정");
                Console.WriteLine("[F5] 책 삭제");
                Console.WriteLine("[ESC] 프로그램 종료");
                Console.WriteLine("*********************************************");

                switch (Console.ReadKey().Key)
                {
                    case ConsoleKey.F1: con.CInsert(); break;
                    case ConsoleKey.F2: con.CPrintAll(); break;
                    case ConsoleKey.F3: con.CSelect(); break;
                    case ConsoleKey.F4: con.CUpdate(); break;
                    case ConsoleKey.F5: con.CDelete(); break;
                    case ConsoleKey.Escape: return;
                }

                pause();
            }

        }

        public void exit()
        {
            Console.Clear();
            Console.WriteLine("*********************************************");
            Console.WriteLine("C# 시험과제");
            Console.WriteLine("프로그램 종료");
            Console.WriteLine("*********************************************");
            pause();
        }

        public static void pause()
        {
            Console.WriteLine("아무키나 누르세요");
            Console.ReadKey();
        }
    }
}
