using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1004
{
    public class Drink
    {
        #region 필드, 프로퍼티 
        public string Name { get; private set; }
        private int price;
        public int Count { get; private set; }
        public int SelCount { get; private set; }
        public int Price
        {
            get { return price; }
            set
            {
                if (value <= 0)
                    throw new Exception("가격은 0이상 필요함");
                price = value;
            }
        }
        #endregion

        #region 생성자
        public Drink(string n, int p, int c)
        {
            Name = n;
            Price = p;
            Count = c;
            SelCount = 0;
        }
        #endregion

        #region 메서드
        public void Print()
        {
            Console.WriteLine("음료수명 : " + Name);
            Console.WriteLine("가    격 : " + Price + "원");
            Console.WriteLine("재 고 량 : " + Count + "개");
            Console.WriteLine("판 매 량 : " + SelCount + "개");
            Console.WriteLine("판매금액 : " + GetSel() + "원");
        }

        public int GetSel()
        {
            return Price * SelCount;
        }

        public override string ToString()
        {
            return string.Format("[{0}/{1}] 판매 {2}개, 재고 {3}개", 
                Name, Price, SelCount, Count);
        }

        public void SelDrink()
        {
            Count--;
            SelCount++;
        }
        #endregion 
    }
}
