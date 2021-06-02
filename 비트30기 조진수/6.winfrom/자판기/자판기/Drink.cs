using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 자판기
{
    public class Drink
    {
        #region 필드, 프로퍼티
        public string Name { get; private set; }        //음료이름
        private int price;                              //가격
        public int Inventory { get; private set; }      //재고량
        public int Salesrate { get; private set; }      //판매량
        public int Price
        {
            get { return price; }
            set
            {
                if (value <= 0)
                    throw new Exception("0보다 작다");
                price = value;
            }
        }
        #endregion
        #region 생성자
        public Drink(string n, int p, int i)
        {
            Name = n;
            Price = p;
            Inventory = i;
            Salesrate = 0;
        }
        #endregion
        #region 메서드
        public void Print()
        {
            Console.WriteLine("음료이름 : " + Name);
            Console.WriteLine("가    격 : " + Price + "원");
            Console.WriteLine("재 고 량 : " + Inventory + "개");
            Console.WriteLine("판 매 량 : " + Salesrate + "개");
            Console.WriteLine("판매금액 : " + GetSel() + "원");
        }

        public int GetSel()
        {
            return Price * Salesrate;
        }

        public override string ToString()
        {
            return string.Format("[{0}/{1}] 판매 {2}개, 재고{3}",
                Name, Price, Salesrate, Inventory);
        }

        public void SelDrink()
        {
            Inventory--;
            Salesrate++;
        }
        #endregion
    }
}
