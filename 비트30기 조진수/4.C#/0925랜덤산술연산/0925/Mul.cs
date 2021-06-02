using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0925
{
    class Mul : Cal
    {
        public Mul(int n1, int n2) : base(n1, n2)
        {

        }
        public override float CalResult()
        {
            return (float)Num1 * Num2;
        }
        public override void Print()
        {
            Console.WriteLine("{0}*{1}={2}", Num1, Num2, Result);
        }
    }
}
