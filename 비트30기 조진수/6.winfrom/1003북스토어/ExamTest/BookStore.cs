using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExamTest
{
    //델1
    delegate void DelCount(int c);
    class BookStore
    {
        List<Book> booklist;
        public DelCount c = null;       //델 2

        public BookStore()
        {
            booklist = new List<Book>();
        }
        public void Insert(string n, int p)
        {
            //ADD 저장
            Book book = new Book(n, p);
            booklist.Add(book);
        }

        public void PrintAll()
        {
            foreach(Book b in booklist)
            {
                Console.WriteLine(b);
            }
        }

        public void Select(string n)
        {
            foreach(Book b in booklist)
            {
                if (b.Name.Equals(n))
                {
                    Console.WriteLine(b);
                    return;
                }
            }
            throw new Exception("책이업성");
        }

        public void Update(string n, int cou)
        {

            foreach (Book b in booklist)
            {
                if (b.Name.Equals(n))
                {
                    b.UpCount(cou);
                    c(b.SellCount);
                    return;
                }
            }
            throw new Exception("책업성");
        }

        public void Delete(string n)
        {
            
            for(int i = 0; i<booklist.Count; i++)
            {
                Book mem = booklist[i];
                if (mem.Name.Equals(n))
                {
                    booklist.Remove(mem);
                    return;
                }
            }
            throw new Exception("업성");
        }
    }
}
