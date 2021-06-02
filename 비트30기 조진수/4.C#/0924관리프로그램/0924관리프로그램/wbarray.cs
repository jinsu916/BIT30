using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0924관리프로그램
{
    /// <summary>
    /// 배열의 자료구조
    /// </summary>
    class wbarray
    {
        private object[] memlist;

        public int Size { get; private set; }
        public int Max { get; private set; }

        #region 생성자
        public wbarray(int max)
        {
            Size = 0;
            Max = max;
            //Max = wblib.inputnuber("배열의 크기");
            memlist = new object[Max];
        }
        #endregion

        public object[] Memlist
        {
            get { return memlist; }
        }

        public object getdata(int idx)
        {
            return memlist[idx];
        }

        public object this[int index]
        {
            get { return memlist[index]; }
        }

        public void insert(object mem)
        {
            if (Size >= Max)
                throw new Exception("저장 공간 부족");
            memlist[Size] = mem;
            Size++;
        }

        public void erase(int idx)
        {
            for(int i = idx; i<Size; i++)
            {
                memlist[i] = memlist[++i];
            }
            Size--;
        }
    }
}
