#include <iostream>
#include "MATRIX.h"

using namespace std;

int main (int argc, char ** argv) {
  IdentityMatrix<int> I1(5);
  IdentityMatrix<int> I2(6);
  // RandomMatrix<int> I(5,100,200);
  I1.print();
  I2.print();
  KroneckerProduct<int> KP(I1,I2);
  KP.print();

  return 0;
}
