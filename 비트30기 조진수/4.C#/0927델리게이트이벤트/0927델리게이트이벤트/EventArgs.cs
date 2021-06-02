using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0927델리게이트이벤트
{
    class CalEventArgs : EventArgs
    {
        public string Type { get; private set; }
        public int Num1 { get; private set; }
        public int Num2 { get; private set; }
        public int Num3 { get; private set; }
        public DateTime date { get; private set; }

        public CalEventArgs(string s, int n1, int n2, int n3)
        {
            Type = s;
            Num1 = n1;
            Num2 = n2;
            Num3 = n3;
            date = DateTime.Now;
        }
    }
    delegate void CalEvent(object obj, CalEventArgs arg);
}
