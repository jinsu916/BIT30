using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/*
 * 사칙연산
 * 시나리오
 * 1. 랜덤하게 1000개의 문제가 생성
 * 2. 아래와 같이 전체 문제가 출력
 *      ex) 3 * 3 = 6
 */
namespace _0925
{
    class Program
    {
        private Cal[] callist = new Cal[1000];

        public void Run()
        {
            InitExample();
            PrintExample();
        }

        private void InitExample()
        {
            
            Random r = new Random();

            int num1, num2, oper;
            for (int i = 0; i <callist.Length; i++)
            {
                num1 = r.Next(1, 100);     //1~99
                num2 = r.Next(1, 100);
                oper = r.Next(0, 4);        //0~3

                Cal cal= null;
                switch(oper)
                {
                    case 0: cal = new Add(num1, num2); break;
                    case 1: cal = new Sub(num1, num2); break;
                    case 2: cal = new Mul(num1, num2); break;
                    case 3: cal = new Div(num1, num2); break;
                }
                callist[i] = cal;
            }
        }

        private void PrintExample()
        {
            for(int i=0; i<callist.Length; i++)
            {
                Console.Write("[{0,4}]", i + 1);
                callist[i].Print();
            }
        }
        static void Main(string[] args)
        {
            Program p = new Program();
            p.Run();
        }
    }
}
