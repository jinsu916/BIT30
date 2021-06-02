using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0924계좌관리프로그램
{
    class myioarr
    {
        private accio[] acciolist;

        public int Size { get; private set; }
        public int Max { get; private set; }

        #region 생성자
        public myioarr()
        {
            Size = 0;
            Max = 500;
            acciolist = new accio[Max];
        }
        #endregion


        public accio getdata(int idx)
        {
            return acciolist[idx];
        }

        public accio this[int index]
        {
            get { return acciolist[index]; }
        }

        public void insert(accio mem)
        {
            if (Size >= Max)
                throw new Exception("저장 공간 부족");
            acciolist[Size] = mem;
            Size++;
        }
        public void erase(int idx)
        {
            for (int i = idx; i < Size; i++)
            {
                acciolist[i] = acciolist[++i];
            }
            Size--;
        }
    }
}
