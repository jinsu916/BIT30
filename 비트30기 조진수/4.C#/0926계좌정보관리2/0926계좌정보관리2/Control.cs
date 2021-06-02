using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0926계좌정보관리2
{
    class Control
    {
        List<Account> acc = new List<Account>();

        #region 싱글톤 패턴
        static Control con;
        public static Control Instance
        {
            get
            {
                return con;
            }
        }

        static Control()
        {
            con = new Control();
        }

        private Control()
        {
        }
        #endregion
        public void InputAccount(int id, int balance)
        {
            for (int i = 0; i < acc.Count; i++)
            {
                Account mem = acc[i];
                if (mem.Acid == id)
                {
                    mem.AddMoney(balance);
                    return;
                }
            }
            throw new Exception("없쥬");
        }
        public void OutputAccount(int id, int balance)
        {
            for (int i = 0; i < acc.Count; i++)
            {
                Account mem = acc[i];
                if (mem.Acid == id)
                {
                    mem.MinMoney(balance);
                    return;
                }
            }
            throw new Exception("없쥬");
        }

        public bool DelAccount(int id)
        {
            for (int i = 0; i < acc.Count; i++)
            {
                Account mem = acc[i];
                if (mem.Acid == id)
                {
                    acc.Remove(mem);
                    return true;
                }

            }
            return false;
        }
        public Account SelectAccount(int id)
        {
            for (int i = 0; i < acc.Count; i++)
            {
                Account mem = acc[i];
                if (mem.Acid == id)
                    return mem;
            }
            throw new Exception("알맞은 ID 존재 안함.");

        }
        public void SelectAllAccount(out List<Account> mem)
        {
            mem = acc;
        }
        public bool AddAccount(Account mem)
        {
            try
            {
                acc.Add(mem);
                return true;
            }
            catch (Exception)
            {
                return false;
            }

        }
        public void SortAccount(string idx)
        {
            switch (idx)
            {
                case "1": acc.Sort(new IDComparaer()); break;
                case "2": acc.Sort(); break;
                case "3": acc.Sort(new BalanceComparaer()); break;
                default: break;
            }
        }
        
    }
}
