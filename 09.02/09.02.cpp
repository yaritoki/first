
#include "Stream.h"
#include <iostream>
#include "Simplex.h"
#include "test.h"
int main()
{
    OptLib::testStream();
    OptLib::testSum();
    OptLib::testMinus();
    OptLib::testMinusscalar();
    OptLib::testSumscalar();
    OptLib::testMult();
    OptLib::testDelScalar();
    OptLib::testMultpoint();
    OptLib::testscal();
    OptLib::testdel();
    OptLib::testAbs();
    OptLib::testSqrt();
    
   
    
    std::cout << "*************************\n";
    OptLib::testMatrix();
    OptLib::testMatrixM();
    //OptLib::testDet();
    OptLib::testsr();
    OptLib::testdis();
}
