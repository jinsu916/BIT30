using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0927_조별
{
    class wbPrint
    {
        public static void logo()
        {
            Console.Clear();
            Console.WriteLine("*********************************************");
            Console.WriteLine("2019.9.27");
            Console.WriteLine("우송비트고급30기 C#언어과정");
            Console.WriteLine("자판기 프로그램");
            Console.WriteLine("4조");
            Console.WriteLine("*********************************************");
            pause();
        }

        public static void ending()
        {
            Console.Clear();
            Console.WriteLine("*********************************************");
            Console.WriteLine("자판기 프로그램");
            Console.WriteLine("프로그램 종료");
            Console.WriteLine("*********************************************");
            pause();
        }

        public static void menuprint()
        {

            Console.WriteLine("*********************************************");
            Console.WriteLine("[F1] 금액넣기");
            Console.WriteLine("[F2] 음료고르기");
            Console.WriteLine("[F3] 잔액반환");
            Console.WriteLine("[ESC] 프로그램 종료");
            Console.WriteLine("*********************************************");
        }

        public static void pause()
        {
            Console.WriteLine("아무키나 누르세요");
            Console.ReadKey();
        }
    }
}
