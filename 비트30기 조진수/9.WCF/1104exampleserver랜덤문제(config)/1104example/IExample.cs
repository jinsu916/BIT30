using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.Text;
using System.Threading.Tasks;

namespace _1104example
{
    //인터페이스(계약) ==> WSDL 문서
    [ServiceContract]
    interface IExample
    {
        [OperationContract]
        List<Cal> GetExample(int max);
        [OperationContract]
        bool InputExample(int num1, int num2, char oper, float input);
        [OperationContract]
        string PrintExample(int num1, int num2, char oper);
    }

    class CExample : IExample
    {
        public List<Cal>GetExample(int max)
        {
            List<Cal> callist = new List<Cal>();

            Random r = new Random();
            for (int i = 0; i < max; i++)
            {
                int n1 = r.Next(1, 10);
                int n2 = r.Next(1, 10);
                int oper = r.Next(1, 5);
                Cal c = new Cal();
                c.num1 = n1;
                c.num2 = n2;
                switch (oper)
                {
                    case 1: c.oper = '+'; break;
                    case 2: c.oper = '-'; break;
                    case 3: c.oper = '*'; break;
                    case 4: c.oper = '/'; break;
                }
                callist.Add(c);
            }
            return callist;
        }

        public bool InputExample(int num1, int num2, char oper, float input)
        {
            float result = 0;
            switch(oper)
            {
                case '+': result = num1 + num2; break;
                case '-': result = num1 - num2; break;
                case '*': result = num1 * num2; break;
                case '/': result = num1 / num2; break;
            }
            if (result == input)
                return true;
            else
                return false;
        }

        public string PrintExample(int num1, int num2, char oper)
        {
            return num1 + " " + oper + " " + num2 + " = ";
        }
    }
}
