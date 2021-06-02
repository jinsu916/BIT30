using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ServiceModel;
using System.Runtime.Serialization;

namespace _1104example
{
    [DataContract]
    public class Cal
    {
        [DataMember]
        public int num1;

        [DataMember]
        public int num2;

        [DataMember]
        public char oper;
    }
}
