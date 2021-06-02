using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0927_조별
{
    class Control
    {
        Banding ben = new Banding();
       
        public Control()
        {
            ben.delgetitem = getdrink;
            ben.delreturnbalance = getbalance;
        }

        public void getdrink(string item)
        {
            Console.WriteLine("선택한 상품 >>  {0}", item);
        }

        public void getbalance(int balance)
        {
            Console.WriteLine("{0}원이 반환되었습니다", balance);
        }
        //정보 상단에 출력
        public void Print()
        {
            ben.PrintAll();
            //log출력도 여기에
        }
        //금액 투입
        public void Getmoney()
        {
            try
            {
                int inputmoney = Lib.inputnumber("넣을 금액");
                if (inputmoney <= 0)
                    throw new Exception("잘못된 금액");

                ben.InputMoney(inputmoney);
            }
            catch(Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }

        public void GetBalance()
        {
           ben.ClearMoney();
        }

        //음료의 id값 받기
        public void GetProduct()
        {
            try
            {
                int idx = Lib.inputnumber("상품을 눌러주세요");
                ben.GetItem(idx);

            }
            catch(Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
    }
}
