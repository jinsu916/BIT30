using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0924관리프로그램
{
    enum enumdept { NO, COM, IT, GAME, ETC };
    /// <summary>
    /// 데이터 클래스 
    /// </summary>
    [Serializable]
    class member
    {
        //멤버변수, 프로퍼티
        public string Name { get; private set; }
        public string Phone { get; set; }
        public enumdept Dept { get; set; }        //학과
        private int grad;           //학년
        public int Grad
        {
            get { return grad; }
            set
            {
                if (value >= 1 && value <= 4)
                    grad = value;
                else
                    throw new Exception("잘못된 학년");
            }
        }

        #region 연산자 오버로딩

        public static bool operator ==(member mem, string name)
        {
            return mem.Name == name;
        }

        public static bool operator ==(member mem, member mem1)
        {
            return mem.Name == mem1.Name;
        }

        public static bool operator !=(member mem, string name)
        {
            return mem.Name != name;
        }

        public static bool operator !=(member mem, member mem1)
        {
            return mem.Name != mem1.Name;
        }
        #endregion
        //생성자
        public member(string n, string p ,enumdept d, int g)
        {
            Name = n;
            Phone = p;
            Dept = d;
            Grad = g;
        }

        public void Print()
        {
            Console.WriteLine("이름:" + Name);
            Console.WriteLine("전화번호" + Phone);
            Console.WriteLine("학과:" + Dept);
            Console.WriteLine("학년:" + Grad);
        }
        public override string ToString()
        {
            string temp =
                string.Format("[{0}] {1}, {2}, {3}",
                                Name, Phone, Dept, Grad);
            return temp;
        }
    }
}
