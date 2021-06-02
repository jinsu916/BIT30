
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.ServiceModel;
using System.Text;

namespace _1104wcf
{

    //인터페이스(계약) ==> WSDL 문서
    [ServiceContract]

    //인터페이스
    public interface IHelloWorld
    {
        [OperationContract]
        string SayHello();

        [OperationContract]
        int Add(int n1, int n2);

        int Sub(int n1, int n2);
    }

    //서비스 객체
    class HelloWorlServiceWCFService : IHelloWorld
    {
        public int Add(int n1, int n2)
        {
            return n1 + n2;
        }

        public string SayHello()
        {
            return "Hello WCF World!";
        }

        public int Sub(int n1, int n2)
        {
            return n1 - n2;
        }
    }
}