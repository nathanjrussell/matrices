#include <iostream>
#include "MATRIX.h"

using namespace std;

int main (int argc, char ** argv) {
  IdentityMatrix<int> I(5);
  I.print();

  return 0;
}
