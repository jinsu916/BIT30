using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0923
{
    /*
     * 1.멤버 변수             --> 멤버 변수        : 데이터 은닉
     * 2.생성자 소멸자         --> 생성자            : ovverlode
     * 3.get & set 메서드      --> 프로퍼티(속성)
     * 4.일반 메서드           --> 일반메서드
     */
    class Member
    {
        private string name;
        private string phone;
        private int age;
        private char gender;


        public Member(string n, string p, int a, char g)
        {
            name = n;
            phone = p;
            age = a;
            gender = g;
        }

    }
}
