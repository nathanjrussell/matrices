#include <iostream>
#include "MATRIX.h"

using namespace std;

template <typename T>
Matrix<T>::~Matrix() {
  if (!elements) { //check if allocated
    delete[] elements; //deallocate
  } //close if ~elements
} //close destructor

template <typename T>
Matrix<T>::Matrix() {
  //empty on purpose
} //close default constructor

template <typename T>
Matrix<T>::Matrix(int r, int c) {
  this->setDim(r,c);
} //close Matrix constructor (r,c)

template <typename T>
T Matrix<T>::operator()(int r, int c) {
    return elements[r*numCols + c];
}
template <typename T>
void Matrix<T>::operator*=(T scalar) {
  int matrixSize = numRows * numCols;
  for (int i=0; i<matrixSize; ++i) {
    elements[i] *= scalar;
  }
}

template <typename T>
void Matrix<T>::operator+=(T scalar) {
  int matrixSize = numRows * numCols;
  for (int i=0; i<matrixSize; ++i) {
    elements[i] += scalar;
  }
}

template <typename T>
void Matrix<T>::setDim(int r, int c) {
  numRows = r; //sets number of rows
  numCols = c; //sets number of cols
  elements = new T[r*c]; //allocate space for matrix
  for (int i=0; i<r*c; ++i) {
    elements[i] = 0;  //initialize all values to zero
  } //close for i loop
} //close setDim

template <typename T>
int Matrix<T>::getNumCols() {
  return numCols;
}

template <typename T>
int Matrix<T>::getNumRows() {
  return numRows;
}

template <typename T>
void Matrix<T>::getDim(int *values) {
  values[0] = numRows;
  values[1] = numCols;
}

template <typename T>
void Matrix<T>::print() {
  cout <<endl<<"Printing matrix with "<< numRows<<" rows and "<<numCols<<" cols";
  cout<<endl<<endl; //newline
  for (int r=0; r<numRows; ++r) { //iterate over rows
    for (int c=0; c<numCols; ++c) { //iterate over cols
      cout << elements[r*numCols + c]<<" "; //print element in r row and c col
    } //close for c loop
    cout<<endl;
  } //close for r loop
  cout<<endl; //extra line at bottom of matrix print
} //close print()


template <typename T>
IdentityMatrix<T>::IdentityMatrix(int size):Matrix<T>(size,size) {
  for (int i=0; i<size; ++i) {
    this->elements[i*size + i] = 1;
  }
}

template <typename T>
RandomMatrix<T>::RandomMatrix(int size, T lowerBound, T upperBound):Matrix<T>(size,size) {
  int randInt;
  for (int r=0; r<size; ++r) {
    for (int c=0; c<size; ++c) {
      randInt = rand()%(int)(upperBound - lowerBound) + lowerBound;
      this->elements[r*size + c] = (T) (randInt + rand()/(double)RAND_MAX);
    }
  }
}

template <typename T>
KroneckerProduct<T>::KroneckerProduct(Matrix<T> &A, Matrix<T> &B):Matrix<T>() {
  int dimA[2];
  int dimB[2];
  A.getDim(dimA);
  B.getDim(dimB);
  int ar,ac,br,bc;
  int rowK =0;
  int colK = 0;
  int count = 0;

  this->setDim(dimA[0]*dimB[0], dimA[1]*dimB[1]);
  for (int rowA=0; rowA<dimA[0]; ++rowA) {
    for (int rowB=0; rowB<dimB[0]; ++rowB) {
      for (int colA=0; colA<dimA[1]; ++colA) {
        for (int colB=0; colB<dimB[1]; ++colB) {
          this->elements[count++] = A(rowA,colA)*B(rowB,colB);
        }
      }
    }
  }
  //   for (int c=0; c<this->numCols; ++c) {
  //     ar = (((r+1)%dimB[0]) ? (r+1)/dimB[0] : ((r+1)/dimB[0]) + 1) - 1;
  //     ac = (((c+1)%dimB[1]) ? (c+1)/dimB[0] : ((c+1)/dimB[0]) + 1) - 1;
  //     br = r % dimB[0];
  //     bc = c % dimB[1];
  //     this->elements[r*(this->numCols) + c] = A(ar,ac) * B(br,bc);
  //   }
  // }
}





// template class IdentityMatrix<int>;
// template class Matrix<int>;
