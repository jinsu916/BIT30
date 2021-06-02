using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0927델리게이트이벤트
{
    //이벤트 구독자
    class EventLog
    {
        private List<CalEventArgs> loglist = new List<CalEventArgs>();


        Cal cal;
        public EventLog(Cal _cal)
        {
            cal = _cal;
            cal.Log += LogMessage;
        }

        public void LogMessage(object obj, CalEventArgs e)
        {
            loglist.Add(e);
            PrintAll();

        }
        private void PrintAll()
        {
            Console.WriteLine("============================================");
            foreach (CalEventArgs a in loglist)
            {
                Console.WriteLine("[{0}] {1}, {2}, {3}, {4}",
                    a.Type, a.Num1, a.Num2, a.Num3, a.date);
            }
            Console.WriteLine("============================================");
        }
    }
}
