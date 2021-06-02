using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0924계좌관리프로그램
{
    class faithaccount : account     //신용계좌
    {
        public faithaccount(int a, string n, enumaccount t, int b) : base(a, n, t, b)
        {

        }

        public override int AddMoney(int money)
        {

            return (int)(money * 1.01);
        }

        public override string ToString()
        {
            string temp =
                string.Format("[{0}] 이름 : {1}, 계좌종류 : 신용계좌, 잔액 : {2}",
                                Acid, Name, Balance);
            return temp;
        }
    }
}
