using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0923
{
    /// <summary>
    /// 진입점 메서드를 포함하고 있는 클래스
    /// </summary>
    class Program
    {
        //출력함수
        static void Print1()
        {
            Console.Write("test\n");
            Console.WriteLine("test");  //개행처리
        }
        //값타입 참조타입
        static void Print2()
        {
            int num1;   //값형식 - 만드는순간 공간할당 (값저장)
            num1 = 10;

            Program pr; //참조형식 - 공간X (주소값저장)
            pr = new Program();     //참조형식 사용법 (힢메모리에 저장공간 생성)

            Program pr1 = new Program();
            pr = pr1;
        }
        //String 타입 : 참조타입
        //참조타입이지만 값타입처럼 사용 가능
        //1. 저장공간 생성 : new
        //2. 대입연산   : 동일객체를 가리킴
        static void Print3()
        {
            string str = "test";
            string str1;
            str1 = str;
            str1 = "AAA";
            Console.WriteLine("{0},{1}", str, str1);
        }
        //-----------------입력-----------------------------------------
        //Read()
        static void Print4()
        {
            //문자 하나를 반환하는 함수
            int number = Console.Read();
            Console.WriteLine("{0}",number);
            Console.WriteLine(number);
        }
        //ReadLine()
        //일반적으로 위 함수를 사용, 모든타입 입력처리
        static void Print5()
        {
            Console.Write("이름:");
            string name = Console.ReadLine();

            Console.Write("나이:");
            string temp = Console.ReadLine();
            int age = int.Parse(temp);      //string -> int 로변환

            Console.Write("몸무게:");
            float weight = float.Parse(Console.ReadLine());

            Console.Write("성별(남or여):");
            temp = Console.ReadLine();
            char gender = temp[0];

            Console.WriteLine("이름:{0}", name);
            Console.WriteLine("성별:" + gender);  //S + 기타타입 = S
            Console.WriteLine("나이:" + age + "살");
            Console.WriteLine("몸무게 : {0}", weight);
        }
        //ReadKey : 특수문자 포함....
        static void Print6()
        {
            ConsoleKeyInfo key = Console.ReadKey();
            if(key.Key == ConsoleKey.F1)
            {
                Console.WriteLine("F1");
            }
            else if(key.Key == ConsoleKey.DownArrow)
            {
                Console.WriteLine("Down");
            }
        }
        //------------------------------------------------------
        //예외처리
        //C#은 다양한 예외처리 구문이 제공된다
        static void Print7()
        {
            try
            {
                int num = 0;
                float result = 10 / num;

                int[] arr = new int[5]; //배열은 참조형
                arr[5] = 10;

            }

            catch(DivideByZeroException ex)
            {
                Console.WriteLine("나눗셈: " + ex.Message);
            }
            catch(Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
        //객체 사용 코드
        static void Print8()
        {
            //메모리
            MyTime t1 = new MyTime(12, 22, 31);
            MyTime t2 = new MyTime(12, 22, 31);
            MyTime t3 = t1;

            //객체 명을 출력하면 암묵적으로 ToString()을 호출
            Console.WriteLine(t1);
            Console.WriteLine(t2.ToString());
            Console.WriteLine(t3);

            //eqauals
            if (t1.Equals(t2) == true)
                Console.WriteLine("TRUE");
            else
                Console.WriteLine("FAlSE");
        }
        static void Main(string[] args)
        {
            Print5();
        }
    }
}
