using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using exampleclient.ServiceReference1;

namespace exampleclient
{
    class Program
    {
        static void Main(string[] args)
        {
            //ExampleClient client = new ExampleClient();
            //Console.WriteLine(client.GetExample(10));

            //Console.WriteLine(client.Add(10, 20));


            ExampleClient client = new ExampleClient();

            Cal[] arr = client.GetExample(10);

            for (int i = 0; i < 10; i++)
            {
                string str = client.PrintExample(arr[i].num1, arr[i].num2, arr[i].oper);
                Console.Write(str);

                float result = float.Parse(Console.ReadLine());
                if (client.InputExample(arr[i].num1, arr[i].num2, arr[i].oper, result))
                    Console.WriteLine("정답");
                else
                    Console.WriteLine("오답");
            }
            //[OperationContract]
            //List<Cal> GetExample(int max);
            //[OperationContract]
            //bool InputExample(int num1, int num2, char oper, float input);
            //[OperationContract]
            //string PrintExample(int num1, int num2, char oper);
        }
    }
}
