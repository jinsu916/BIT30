using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0927델리게이트이벤트
{
    class Program
    {
        Cal cal = new Cal();
        EventLog elog;

        public Program()
        {
            cal.delresult = Result;
            elog = new EventLog(cal);
        }

        public void Run()
        {
            while(true)
            {
                Console.Write(">>");
                String str = Console.ReadLine();
                String[] sp = str.Split(' ');

                if (sp[0].Equals("set"))
                {
                    cal.Set(int.Parse(sp[1]),
                                 int.Parse(sp[2]));
                }
                else if (sp[0].Equals("add"))
                {
                    cal.Add();
                }
                else if (sp[0].Equals("sub"))
                {
                    cal.Sub();
                }
                else if (sp[0].Equals("exit"))
                {
                    return;
                }
            }
        }

        //callback 함수
        public void Result(int n1, char op, int n2, int result)
        {
            Console.WriteLine("{0} {1} {2} = {3}",
                n1, op, n2, result);
        }
        static void Main(string[] args)
        {
            new Program().Run();
        }
    }
}
