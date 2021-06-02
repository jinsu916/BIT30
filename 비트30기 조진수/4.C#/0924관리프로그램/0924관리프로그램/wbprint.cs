using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0924관리프로그램
{
    static class wbprint
    {
        public static void logo()
        {
            Console.Clear();
            Console.WriteLine("*********************************");
            Console.WriteLine("2019.9.24");
            Console.WriteLine("우송비트고급30기 C#언어과정");
            Console.WriteLine("학생관리프로그램 -첫번째 실습");
            Console.WriteLine("jjs");
            Console.WriteLine("*********************************");
            pause();
        }

        public static void ending()
        {
            Console.Clear();
            Console.WriteLine("*********************************");
            Console.WriteLine("학생관리프로그램 -첫번째 실습");
            Console.WriteLine("프로그램 종료");
            Console.WriteLine("*********************************");
            pause();

        }

        public static void menuprint()
        {
            Console.WriteLine("*********************************");
            Console.WriteLine("[F1] 학생등록");
            Console.WriteLine("[F2] 학생이름으로검색");
            Console.WriteLine("[F3] 전화번호, 학과, 학년 수정");
            Console.WriteLine("[F4] 학생삭제");
            Console.WriteLine("[F5] 파일저장");
            Console.WriteLine("[F6] 파일불러오기");
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
