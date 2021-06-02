using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0927_조별
{
    delegate void DelGetItem(string product);
    delegate void DelReturnBalance(int balance);
    class Banding
    {
        List<Product> prlist =new List<Product>();
        public int Balance
        {
            get;
           private set;
        }

        public DelGetItem delgetitem = null;
        public DelReturnBalance delreturnbalance = null;

        
            
        public Banding()
        {
            prlist.Add(new Product("콜라", 1400));
            prlist.Add(new Product("사이다", 1000));
            prlist.Add(new Product("밀키스", 900));
            prlist.Add(new Product("웰치스", 1200));
            prlist.Add(new Product("마운틴듀", 100));
            Balance = 0;
        }

        public void PrintAll()
        {
            int idx = 1;
            foreach (Product p in prlist)
            {
                Console.WriteLine("[{0}] {1}", idx,p);
                idx++;
            }
            Console.WriteLine("잔액 : {0}", Balance);
            //Console.WriteLine("============================================");
        }
        public void InputMoney(int money)
        {
            Balance += money;
        }

        public void ClearMoney()
        {
            int money = Balance;
            Balance = 0;
            delreturnbalance(money);
        }

        public void GetItem(int idx)
        {
                Product val = prlist[idx - 1];
                if (Balance < val.Price)
                    throw new Exception("잔액이 부족합니다");
                Balance -= val.Price;

                delgetitem(val.Item);
        }

    }
}
