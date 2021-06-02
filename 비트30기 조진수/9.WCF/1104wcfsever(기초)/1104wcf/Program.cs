using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.ServiceModel.Description;
using System.Text;
using System.Threading.Tasks;

namespace _1104wcf
{
    class Program
    {
        //exe Hosting
        static void Main(string[] args)
        {
            BasicHos();
        }

        static void BasicHos()
        {
            //exe Hosting
            ServiceHost host =
                new ServiceHost(typeof(HelloWorlServiceWCFService));
            //    new Uri("http://192.168.0.72/wcf/example/helloworldservice"));

            ////endpoint
            //host.AddServiceEndpoint(
            //    typeof(IHelloWorld),    //C
            //    new BasicHttpBinding(), //B
            //    "");                    //A

            ////===================================WSDL 문서 제공 코드==================
            //ServiceMetadataBehavior behavior =
            //    host.Description.Behaviors.Find<ServiceMetadataBehavior>();
            //if(behavior == null)
            //{
            //    behavior = new ServiceMetadataBehavior();
            //    host.Description.Behaviors.Add(behavior);
            //}
            //behavior.HttpGetEnabled = true;
            ////=========================================================================

            host.Open();
            Console.WriteLine("press any key to stop the service");
            Console.ReadKey();
            host.Close();
        }
    }
}
