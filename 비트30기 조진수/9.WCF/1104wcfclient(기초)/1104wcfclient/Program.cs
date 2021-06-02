using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _1104wcfclient.ServiceReference1;

namespace _1104wcfclient
{
    class Program
    {
        static void Main(string[] args)
        {
            HelloWorldClient client = new HelloWorldClient();
            Console.WriteLine(client.SayHello());

            Console.WriteLine(client.Add(10, 20));
        }
    }
}
