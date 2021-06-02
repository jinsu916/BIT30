using System;
using System.Collections;

namespace _0927_조별
{
     class Product
    {
        public string Item { get; set; }
        public int Price { get; set; }

        public Product(string i,int p)
        {
            Item = i;
            Price = p;
        }
        
        public override string ToString()
        {
            return string.Format("[{0}] {1}", Item, Price);
        }

    }
}
