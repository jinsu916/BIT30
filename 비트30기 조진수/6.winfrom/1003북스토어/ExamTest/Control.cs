using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExamTest
{
    class Control
    {
        BookStore bookstore = new BookStore();
        #region 싱글톤
        public static Control Instance
        {
            get; private set;
        }

        static Control()
        {
            Instance = new Control();
        }
        private Control()
        {
           bookstore.c = GetCountValue;
        }
        #endregion


        public void CInsert()
        {
            try
            {
                Console.Write("책제목:");
                string name = Console.ReadLine();

                Console.Write("가격:");
                int price = int.Parse(Console.ReadLine());

                bookstore.Insert(name, price);
                Console.WriteLine("저장완료");
            }
            catch(Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }

        public void CPrintAll()
        {
            try
            {
                bookstore.PrintAll();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }

        public void CSelect()
        {
            try
            {
                Console.Write("제목으로검색 : ");
                string name = Console.ReadLine();
                bookstore.Select(name);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }

        public void CUpdate()
        {
            try
            {
                Console.Write("제목으로수정 : ");
                string name = Console.ReadLine();
                Console.Write("판매량 : ");
                int cou = int.Parse(Console.ReadLine());
                bookstore.Update(name,cou);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }

        public void CDelete()
        {
            try
            {
                Console.Write("제목으로삭제 : ");
                string name = Console.ReadLine();

                bookstore.Delete(name);
                Console.WriteLine("삭제완료");
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }

        public void GetCountValue(int c)
        {
            Console.WriteLine("누적판매량 {0}", c);
        }
    }
}
