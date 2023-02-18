#include "Stream.h"
#include <iostream>
#include "Simplex.h"
namespace OptLib
{
    void testStream()
    {
        Point<3> p1{ 1, 2, 3 }, p2{ 2, 4, 1 };
        std::cout << p1<<'\t' << p2<< '\n';
    }
    void testSum()
    {
        Point<3> p1{ 1, 2, 3 }, p2{ 2, 4, 1 };
        Point<3> res = p1 + p2;
        std::cout<<p1<<'+'<<p2<<'=' << res << '\n';
    }
    void testMinus()
    {
        Point<3> p1{ 1, 2, 3 }, p2{ 2, 4, 1 };
        Point<3> res = p1 - p2;
        std::cout << p1 << '-' << p2 << '=' << res << '\n';
    }
    void testSumscalar()
    {
        Point<3> p1{ 1, 2, 3 };
        /* Point<3> res ;
         SimplexOps::UnaryOps::plus<double> plus{4};*/
        auto res = p1 + 31.2;
        auto res1 = 31.2 + p1;
        std::cout << p1 << '+' << "31.2" << '=' << res <<" or " <<res1<< '\n';
        
    }
    void testMinusscalar()
    {
        Point<3> p1{ 1, 2, 3 };
       /* Point<3> res ;
        SimplexOps::UnaryOps::plus<double> plus{4};*/
        auto res =p1- 31.2;
        auto res1 = 31.2 - p1;
        std::cout << p1 << '-' << "31.2" << '=' << res<< '\n';
        std::cout << "31.2" << '-' << p1 << '=' << res1 << '\n';
    }
    void testMult()
    {
        Point<3> p1{ 1,2,3 } ;
        auto res = p1 * 2;
        auto res1 = 2 * p1;
        std::cout << p1 << '*' << '2' << '=' << res <<" or "<<res1<< '\n';
   }
    void testDelScalar()
    {
        Point<3>p1{ 2,4,8 };
        auto res = p1 / 2;
        auto res1 = 16 / p1;
        std::cout << p1 << '/' << '2' << '=' << res <<  '\n';
        std::cout << "16" << '/' << p1 << '=' << res1 << '\n';
    }
    void testAbs()
    {
        Point<3> p1{ 1,-2,-3 };
        auto res = Abs(p1);
        std::cout <<'|' << p1 << '|' << '=' << res << '\n';
    }
    void testSqrt()
    {
        Point<3> p1{ 1,-2,-3 };
        auto res = Sqrt(p1);
        std::cout << "sqrt(" << p1 << ')' << '=' << res << '\n';
    }
    void testMultpoint()
    {
        Point<3>p1{ 1,2,3 }, p2{ 12,4,10 };
        auto res = p1 * p2;
        std::cout << p1 << '*' << p2<< '=' << res << '\n';
    }
    void testscal()
    {
        Point<3>p1{ 1,2,3 }, p2{ 12,4,10 };
        auto res = sc(p1, p2);
        std::cout << "(" << p1 << ',' << p2 << ")" << "=" << res << '\n';
    }
    void testdel()
    {
        Point<3>p1{ 1,2,3 }, p2{ 1,2,3 };
        auto res = p1 / p2;
        std::cout << p1<<'/' << p2 << '=' << res << '\n';
    }
}