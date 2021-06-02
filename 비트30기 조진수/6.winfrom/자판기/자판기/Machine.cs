using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 자판기
{
    public class Machine
    {
        #region 필드, 프로퍼티
        public List<Drink> dlist = new List<Drink>();   //Drink 컬렉션
        public int AllSalesrate { get; private set; }   //판매 총 수량
        public int AllPrice { get; private set; }       //판매 총 금액
        public int Money { get; private set; }          //입금액
        #endregion

        #region 인덱서
        public Drink this[int index]
        {
            get
            {
                if (index >= 0 && index < dlist.Count)
                    return dlist[index];
                else
                    return null;
            }
            set
            {
                if (index >= 0 && index < dlist.Count)
                    dlist[index] = value;
            }
        }
        #endregion

        #region 생성자
        public Machine()
        {
            AllSalesrate = 0;
            AllPrice = 0;
            Money = 0;
            InitDrinkSetting();
        }
        #endregion

        #region 메서드
        private void InitDrinkSetting()
        {
            dlist.Add(new Drink("콜라", 500, 10));
            dlist.Add(new Drink("사이다", 600, 6));
            dlist.Add(new Drink("환타", 300, 2));
            dlist.Add(new Drink("커피", 400, 3));
            dlist.Add(new Drink("생수", 200, 5));
        }

        public void PrintAll()
        {
            Console.WriteLine("판매수량 : " + AllSalesrate + "개");
            Console.WriteLine("판매금액 : " + AllPrice + "원");
            Console.WriteLine("투 입 액 : " + Money + "원");
            foreach (Drink d in dlist)
            {
                Console.WriteLine(d);
            }
        }

        public void InputMoney(int value)
        {
            if (value <= 0)
                throw new Exception("0보다 큰 금액을 투입");
            Money += value;
        }

        private Drink NameToDrink(string name)
        {
            foreach (Drink d in dlist)
            {
                if (d.Name.Equals(name))
                    return d;
            }
            return null;
        }

        public void SelectDrink(string name)
        {
            Drink d = NameToDrink(name);
            if (d == null)
            {
                Console.WriteLine("해당 제품 없음");
                return;
            }
            if (d.Inventory <= 0)
                throw new Exception("재고가 없다");
            if (d.Price > Money)
                throw new Exception("금액이 모자라다");
            d.SelDrink();
            this.SelDrink(d.Price);
        }

        private void SelDrink(int price)
        {
            this.AllSalesrate++;
            this.AllPrice += price;
        }

        public int GetMoney()
        {
            int value = Money;
            Money = 0;
            return value;
        }
        #endregion
    }
}
