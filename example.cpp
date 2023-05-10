#include <iostream>
#include "MATRIX.h"

using namespace std;

int main (int argc, char ** argv) {
  IdentityMatrix<double> I1(5);
  IdentityMatrix<double> I2(6);
  // RandomMatrix<int> I(5,100,200);
  I1 *= 5;
  I2 *= 6;
  I2 += 7;
  I1.print();
  I2.print();
  KroneckerProduct<double> KP(I1,I2);
  KP.print();

  return 0;
}
