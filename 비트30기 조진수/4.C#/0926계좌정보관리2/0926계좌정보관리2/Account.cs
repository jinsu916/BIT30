using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0926계좌정보관리2
{

    class Account : IComparable
    {
        //멤버변수 프로퍼티
        public int Acid { get; private set; }       //계좌번호
        public string Name { get; private set; }    //이름
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
        public Account(int a, string n, int b)
        {
            Acid = a;
            Name = n;
            Balance = AddMoney(b);
        }

        public virtual void Print()
        {
            Console.WriteLine("계 좌 ID : " + Acid);
            Console.WriteLine("이    름 : " + Name);
            Console.WriteLine("입 금 액 : " + Balance);
        }

        public override string ToString()
        {
            string temp =
                string.Format("[{0}] 이름 : {1}, 잔액 : {2}",
                                Acid, Name, Balance);
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

        //정렬
        public int CompareTo(object obj)
        {
            Account acc = obj as Account;
            if (acc == null)
                throw new Exception("잘못된 객체 전달");

            return Name.CompareTo(acc.Name);
        }
    }
    class BalanceComparaer : IComparer<Account>
    {
        public int Compare(Account x, Account y)
        {
            return y.Balance - x.Balance;
        }
    }

    class IDComparaer : IComparer<Account>
    {
        public int Compare(Account x, Account y)
        {
            return x.Acid - y.Acid;
        }
    }
}
