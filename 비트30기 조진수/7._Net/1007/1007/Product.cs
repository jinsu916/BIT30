using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1007
{
    public class Product
    {
        public int PID { get;  set; }
        public string PNmae { get; private set; }
        public int Pric { get; set; }
        public string Description { get; set; }

        public Product(string name, int price, string desc)
        {
            PNmae = name;
            Pric = price;
            Description = desc;
        }
    }
}
