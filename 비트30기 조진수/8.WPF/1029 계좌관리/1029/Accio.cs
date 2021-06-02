using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1029
{
    public class Accio
    {
        private int? accioid;
        public int? Accioid
        {
            get { return accioid; }
            set
            {
                accioid = value;
            }
        }

        private int inputmoney;
        public int Inputmoney
        {
            get { return inputmoney; }
            set
            {
                inputmoney = value;
            }
        }

        private int outputmoney;
        public int Outputmoney
        {
            get { return outputmoney; }
            set
            {
                outputmoney = value;
            }
        }

        public DateTime Tradtime;

        public override string ToString()
        {
            return string.Format("계좌ID:{0}, 입금:{1}, 출금:{2}, 생성날짜:{3}",
                Accioid.ToString(), inputmoney.ToString(), outputmoney.ToString(), Tradtime.ToString());
        }
    }
}
