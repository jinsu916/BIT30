using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0924관리프로그램
{
    class control
    {
        //-----------------저장소--------------------
        wbarray array = null;
        //-------------------------------------------
        public void filesave()
        {
            //wbfile.filesave(array.Memlist, array.Size);
            wbfile.filesersave(array.Memlist, array.Size);
        }
        public void fileload()
        {
            try
            {
                //member[] arr = wbfile.fileload();
                int max;
                member[] arr = wbfile.fileserload(out max);
                array = new wbarray(max);
                for (int i = 0; i < arr.Length; i++)
                {
                     member mem = arr[i];
                     array.insert(mem);
                }
            }
            catch(FileNotFoundException)
            {
                //파이링없으니깐 배열객체를 생성
                int size = wblib.inputnuber("배열의 크기");
                array = new wbarray(size);
            }

        }
        public void printall()
        {
            if (array == null)
                return;

            Console.WriteLine("저장개수 : {0}개", array.Size);
            for(int i = 0; i<array.Size; i++)
            {
                member mem = (member)array[i];//array.getdata(i);
                Console.WriteLine(mem);
            }
        }
        public void insert()
        {
            try
            {
                string name  =   wblib.inputstring("이름");
                string phone =   wblib.inputstring("전화번호");
                int grad     =   wblib.inputnuber("학년");
                enumdept dept = (enumdept)wblib.inputnuber("학과 [1]컴 [2]IT [3]게임 [4]ETC");

                array.insert(new member(name, phone, dept, grad));
                Console.WriteLine("저장완료");
            }
            catch(Exception ex)
            {
                Console.WriteLine("입력오류");
                Console.WriteLine(">>" + ex.Message);
            }

        }
        private int nametoidx(string name)
        {
            for(int i = 0;i<array.Size; i++)
            {
                member mem = (member)array[i];
                if(mem == name) //연산자 호출
                //if (mem.Name.Equals(name) == true)
                    return i;
            }
            throw new Exception("없음");
        }
        public void select()
        {
            try
            { 
                string name = wblib.inputstring("검색이름");
         
                member mem = (member)array[nametoidx(name)];
                Console.WriteLine(mem);
            }
            catch(Exception ex)
            {
                Console.WriteLine("검색 에러");
                Console.WriteLine(">>" + ex.Message);
            }
        }
        public void update()
        {
            try
            {
                string name = wblib.inputstring("수정 이름");

                member mem = (member)array[nametoidx(name)];

                mem.Phone = wblib.inputstring("전화번호");
                mem.Grad = wblib.inputnuber("학년");
                mem.Dept = (enumdept)wblib.inputnuber("학과 [1]컴 [2]IT [3]게임 [4]ETC");

                Console.WriteLine("수정 완료");
            }
            catch (Exception ex)
            {
                Console.WriteLine("수정 에러");
                Console.WriteLine(">>" + ex.Message);
            }
        }
        public void delete()
        {
            try
            {
                string name = wblib.inputstring("삭제 이름");
                
                int idx = nametoidx(name);
                array.erase(idx);
                Console.WriteLine("삭제 완료");
            }
            catch (Exception ex)
            {
                Console.WriteLine("삭제 에러");
                Console.WriteLine(">>" + ex.Message);
            }
        }
    }
}
