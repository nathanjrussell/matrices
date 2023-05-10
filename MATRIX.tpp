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
  int dimA[2]; //array to hold num of rows and cols for matrix A.
  int dimB[2]; //array to hold num of rows and cols for matrix A.
  A.getDim(dimA); //get the dims for matrix A and populate dim variable
  B.getDim(dimB); //get the dims for matrix B and populate dim variable
  int position = 0; //current position for new matrix element entry.
  this->setDim(dimA[0]*dimB[0], dimA[1]*dimB[1]); //set new dims for kron prod
  //for loops below outline how a kronecker product can be populated.
  for (int rowA=0; rowA<dimA[0]; ++rowA) { //iterate through rows of A
    for (int rowB=0; rowB<dimB[0]; ++rowB) { //iterate through rows of B
      for (int colA=0; colA<dimA[1]; ++colA) { //iterate through cols of A
        for (int colB=0; colB<dimB[1]; ++colB) { //iterate through cols of B
          this->elements[position++] = A(rowA,colA)*B(rowB,colB); //set element
        } //close for loop colB
      } //close for loop colA
    } //close for loop for rowB
  } //close for loop for rowA
} //close KroneckerProduct constructor





// template class IdentityMatrix<int>;
// template class Matrix<int>;
