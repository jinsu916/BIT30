using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0926_Collection
{
    class Program
    {
        Sample1 sam = new Sample1();

        public Program()
        {
            logo();
        }

        public void Run()
        {
              while(true)
            {
                Console.Write(">> ");
                string msg = Console.ReadLine();
                string[] split = msg.Split(' ');
                if (split[0].Equals("insert"))
                {
                    sam.insert(split[1]);
                }
                else if (split[0].Equals("selectall"))
                {
                    sam.printall();
                }
                else if (split[0].Equals("select"))
                {
                    sam.select(split[1]);
                }
                else if (split[0].Equals("exit"))
                    return;
            }
        }

        private void logo()
        {
            Console.WriteLine("-----------------------------");
            Console.WriteLine("컬렉션 사용 프로그램 예제");
            Console.WriteLine("버전 1.0");
            Console.WriteLine("사용 방법");
            Console.WriteLine("  insert 저장문자열");
            Console.WriteLine("  selectall");
            Console.WriteLine("  select 검색문자열");
            Console.WriteLine("-----------------------------");
        }

        static void Main(string[] args)
        {
           // Program p = new Program();
           // p.Run();
            new Program().Run();
        }
    }
}
