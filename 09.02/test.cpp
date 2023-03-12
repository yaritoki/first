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
        Point<3> p1{ 1,4,9 };
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
    void testMatrix()
    {
        Point<3> p1{ 1,2,3 }, p2{ 3,2,3 }, p3{ 12,2,3 }, p4{ 2,2,2 };
        SetOfPoints<3, Point<3>> M = { p1,p2,p3 };
        Point<3> res = M * p4;
        std::cout << "result=" << res << std::endl;
    }
    void testMatrixM()
    {
        Point<2> pp1{ 1,2 }, pp2{ 2,1 }, pp3{ 2,3 };
        SetOfPoints<2, Point<2>> M1 = { pp1,pp2 };
        SetOfPoints<2, Point<2>> M2 = { pp1,pp3 };
        
        SetOfPoints<2, Point<2>> res = M1 * M2;
        
        std::cout << M1<<  '*' << '\n' << M2 << '=' << '\n' << res << '\n';
    }
   /* void testDet()
    {
        Point<2> pp1{ 1,2 }, pp2{ 2,1 };
        SetOfPoints<2, Point<2>> M1 = { pp1,pp2 };
        double res = Det(M1);
        std::cout <<"det=" << res<<std::endl;
    }*/

    void testsr()
    {
        Point<2> p1{ 1,2 }, p2{ 2,1}, p3{ 2,3 };
        SetOfPoints<3, Point<2>> M1 = { p1,p2,p3 };
        RawSetOfPoints<3, Point<2>> M2 =M1;
        Point<2> res = M2.Mean();
        std::cout << res<<std::endl;
    }
    void testdis()
    {
        Point<2> p1{ 1,2 }, p2{ 2,1 }, p3{ 3,3 };
        SetOfPoints<3, Point<2>> M1 = { p1,p2,p3 };
        RawSetOfPoints<3, Point<2>> M2 = M1;
       
        Point<2> res = M2.Disp();
        std::cout << res;

        std::cout << std::endl << std::endl << M2;
    }
    void testSetOfPointsVal()
    {
        constexpr size_t dim = 2;
        constexpr size_t count = 3;
        using point = Point<dim>;
        using pointval = PointVal<dim>;

        point p1{ 1,2 }, p2{ 2,1 }, p3{ 3,3 };
        std::array<point::value_type, count> vals{ 1.0,2.0,3.0 };

        SetOfPoints<count, point> M1{ p1,p2,p3 };
        

        SetOfPointsVal<count,point,pointval> M {
            std::move(M1), 
            std::move(vals)};

        std::cout << M;
    }
       
    
}