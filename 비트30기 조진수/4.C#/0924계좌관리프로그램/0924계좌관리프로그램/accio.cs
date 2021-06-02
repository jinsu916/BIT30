using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0924계좌관리프로그램
{
    class accio
    {
        //멤버변수 프로퍼티
        public int Acid { get; private set; }       //계좌번호
        private int input;                  //입금
        public int Input
        {
            get { return input; }
            set
            {
                if (value >= 0)
                    input = value;
                else
                    throw new Exception("잘못된 입력값");
            }
        }
        private int output;                 //출금
        public int Output
        {
            get { return output; }
            set
            {
                if (value >= 0)
                    output = value;
                else
                    throw new Exception("잘못된 입력값");
            }
        }
        private int balance;                 //잔액
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
        public string Date { get; set; }    //일시

        //생성자
        public accio(int a, int i, int o, int b)
        {
            Acid = a;
            Input = i;
            Output = o;
            Balance = b;
            Date = DateTime.Now.ToString("yyyy-MM-dd-HH-mm-ss");

        
        }

        public void Print()
        {
            Console.WriteLine("계 좌 ID : " + Acid);
            Console.WriteLine("입 금 액 : " + Input);
            Console.WriteLine("출 금 액 : " + Output);
            Console.WriteLine("잔    액 : " + Balance);
            Console.WriteLine("일    시 : " + Date);
        }

        public override string ToString()
        {
            string temp =
                string.Format("[{0}] 입금액 : {1}, 출금액 : {2}, 잔액 : {3}, 일시 : {4}",
                                Acid, Input, Output, Balance, Date);
            return temp;
        }
    }
}
