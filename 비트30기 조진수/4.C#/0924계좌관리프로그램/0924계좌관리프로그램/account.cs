using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0924계좌관리프로그램
{
    enum enumaccount { NON, 일반, 신용, 기부 };
    class account
    {
        //멤버변수 프로퍼티
        public int Acid { get; private set; }       //계좌번호
        public string Name { get; private set; }    //이름
        public enumaccount Type { get; set; }       //계좌타입
        private int balance;                        //입금액

        public int Balance
        {
            get { return balance; }
            set
            {
                if (value >= 0)
                    balance = value;
                else
                    throw new Exception("잘못된 입력값");
            }
        }

        //생성자
        public account(int a, string n, enumaccount t, int b)
        {
            Acid = a;
            Name = n;
            Type = t;
            Balance = AddMoney(b);
        }

        public virtual void Print()
        {
            Console.WriteLine("계 좌 ID : " + Acid);
            Console.WriteLine("이    름 : " + Name);
            Console.WriteLine("계좌종류 : " + Type);
            Console.WriteLine("입 금 액 : " + Balance);
        }

        public override string ToString()
        {
            string temp =
                string.Format("[{0}] 이름 : {1}, 계좌종류 : 일반계좌, 잔액 : {2}",
                                Acid, Name,  Balance);
            return temp;
        }
        public virtual int AddMoney(int money)
        {
            return balance += money;
        }

        public virtual int MinMoney(int money)
        {
            return balance -= money;
        }
    }
}