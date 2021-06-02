using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0923
{
    class MyTime
    {
        int hour;
        int min;
        int sec;

        public MyTime(int h, int m, int s)
        {
            hour = h;
            min = m;
            sec = s;
        }

        public override string ToString()
        {
            return hour + "/" + min + "/" + sec;
        }

        public override bool Equals(object obj)
        {
            MyTime t = (MyTime)obj;
            if (hour == t.hour & min == t.min && sec == t.sec)
                return true;
            else
                return false;
        }
    }
}
