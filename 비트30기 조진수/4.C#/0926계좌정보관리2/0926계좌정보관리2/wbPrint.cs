using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0926계좌정보관리2
{
    class wbPrint
    {
        public static void logo()
        {
            Console.Clear();
            Console.WriteLine("*********************************");
            Console.WriteLine("2019.9.26");
            Console.WriteLine("우송비트고급30기 C#언어과정");
            Console.WriteLine("계좌관리프로그램 -세번째 실습");
            Console.WriteLine("jjs");
            Console.WriteLine("*********************************");
            pause();
        }

        public static void ending()
        {
            Console.Clear();
            Console.WriteLine("*********************************");
            Console.WriteLine("계좌관리프로그램 -세번째 실습");
            Console.WriteLine("프로그램 종료");
            Console.WriteLine("*********************************");
            pause();

        }

        public static void menuprint()
        {
            Console.WriteLine("*********************************");
            Console.WriteLine("[F1] 계좌개설");
            Console.WriteLine("[F2] 입금");
            Console.WriteLine("[F3] 출금");
            Console.WriteLine("[F4] 계좌검색");
            Console.WriteLine("[F5] 전체계좌출력");
            Console.WriteLine("[F6] 계좌삭제");
            Console.WriteLine("[F7] 계좌정렬");
            Console.WriteLine("[ESC] 프로그램 종료");
            Console.WriteLine("*********************************");
        }

        public static void pause()
        {
            Console.WriteLine("아무키나 누르세요");
            Console.ReadKey();
        }
    }
}
