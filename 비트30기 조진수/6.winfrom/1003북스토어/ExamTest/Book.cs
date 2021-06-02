using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExamTest
{
    class Book
    {
        public string Name { get; private set; }
        public int Price { get; private set; }
        public int SellCount { get; private set; }

        public Book(string n,int p)
        {
            Name = n;
            Price = p;
            SellCount = 0;
        }

        public void UpCount(int s)
        {
            SellCount += s;
        }

        public override string ToString()
        {
            return string.Format("이름 : {0}, 가격 : {1}, 판매량 : {2}", Name, Price, SellCount);
        }
    }
}
