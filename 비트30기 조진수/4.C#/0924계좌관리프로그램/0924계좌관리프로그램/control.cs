using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0924계좌관리프로그램
{
    class control
    {
        //-----------------저장소--------------------
        wbarray array = new wbarray();
        myioarr array1 = new myioarr();
        //-------------------------------------------
        public void printall()
        {
            Console.WriteLine("저장개수 : {0}개", array.Size);
            for (int i = 0; i < array.Size; i++)
            {
                account mem = array[i];//array.getdata(i);
                Console.WriteLine(mem);
            }
        }
        public void printalllist()
        {
            for (int i = 0; i < array1.Size; i++)
            {
                accio mem = array1[i];//array.getdata(i);
                Console.WriteLine(mem);
            }
        }
        public void makeaccount()
        {

            try
            {
                enumaccount acc = (enumaccount)wblib.inputnuber("개설계좌 [1]일반 [2]신용 [3]기부");

                int acid = wblib.inputnuber("계 좌 ID");
                string name = wblib.inputstring("이    름");
                int balance = wblib.inputnuber("입 금 액");

                if((int)acc == 1)
                {
                    array.insert(new account(acid, name, acc, balance));
                    array1.insert(new accio(acid, balance, 0, balance));
                    Console.WriteLine("저장완료");
                }
                else if((int)acc == 2)
                {
                    array.insert(new faithaccount(acid, name, acc, balance));
                    array1.insert(new accio(acid, balance, 0, balance));
                    Console.WriteLine("저장완료");
                }
                else if((int)acc == 3)
                {
                    array.insert(new contriaccount(acid, name, acc, balance));
                    array1.insert(new accio(acid, balance, 0, balance));
                    Console.WriteLine("저장완료");
                }
                else
                {

                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("입력오류");
                Console.WriteLine(">>" + ex.Message);
            }

        }

        private int acidtoidx(int acid)
        {
            for (int i = 0; i < array.Size; i++)
            {
                account mem = array[i];
                if (mem.Acid.Equals(acid) == true)
                    return i;

            }
            throw new Exception("없음");
        }
        public void deposit()
        {
            try
            {
                int acid = wblib.inputnuber("계좌 ID");
                account mem = array[acidtoidx(acid)];
                
                int money = wblib.inputnuber("입금액");
                mem.AddMoney(money);
                Console.WriteLine(mem);

                array1.insert(new accio(acid, money, 0, mem.Balance));
            }
            catch (Exception ex)
            {
                Console.WriteLine("입금 에러");
                Console.WriteLine(">>" + ex.Message);
            }
        }
        public void withdraw()
        {
            try
            {
                int acid = wblib.inputnuber("계좌 ID");
                account mem = array[acidtoidx(acid)];

                int money = wblib.inputnuber("출금액");
                mem.MinMoney(money);
                Console.WriteLine(mem);

                array1.insert(new accio(acid, 0, money, mem.Balance));
            }
            catch (Exception ex)
            {
                Console.WriteLine("출금 에러");
                Console.WriteLine(">>" + ex.Message);
            }
        }
        public void inquire()
        {
            try
            {
                int acid = wblib.inputnuber("계좌 ID");
                account mem = array[acidtoidx(acid)];
                Console.WriteLine(mem);

                for(int i =0; i<array1.Size; i++)
                { 
                accio mem1 = array1[i]; 
                    if(mem1.Acid== acid)
                    {
                        Console.WriteLine(mem1);
                    }
             
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("잔액조회 에러");
                Console.WriteLine(">>" + ex.Message);
            }
        }
    }
}
