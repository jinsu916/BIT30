using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1028
{
    public class Account
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public int Balance { get; set; }
        public DateTime Date { get; set; }
        

        public override string ToString()
        {
            return Id + " : " + Name + " : " + Balance + " : " + Date;
        }
    }
}
