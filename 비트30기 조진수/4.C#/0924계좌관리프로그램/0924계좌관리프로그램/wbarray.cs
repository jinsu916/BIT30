using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0924계좌관리프로그램
{
    class wbarray
    {
        private account[] acclist;

        public int Size { get; private set; }
        public int Max { get; private set; }

        #region 생성자
        public wbarray()
        {
            Size = 0;
            Max = wblib.inputnuber("계좌 저장 크기");
            acclist = new account[Max];
        }
        #endregion


        public account getdata(int idx)
        {
            return acclist[idx];
        }

        public account this[int index]
        {
            get { return acclist[index]; }
        }

        public void insert(account mem)
        {
            if (Size >= Max)
                throw new Exception("저장 공간 부족");
            acclist[Size] = mem;
            Size++;
        }
        public void erase(int idx)
        {
            for (int i = idx; i < Size; i++)
            {
                acclist[i] = acclist[++i];
            }
            Size--;
        }
    }
}
