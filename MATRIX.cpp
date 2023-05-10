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
  cout<<"Yes"<<endl;
  this->setDim(r,c);
} //close Matrix constructor (r,c)

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
void Matrix<T>::print() {
  cout <<endl<<"Printing matrix with "<< numRows<<" rows and "<<numCols<<" cols";
  cout<<endl; //newline
  for (int r=0; r<numRows; ++r) { //iterate over rows
    for (int c=0; c<numCols; ++c) { //iterate over cols
      cout << elements[r*numCols + c]<<" "; //print element in r row and c col
    } //close for c loop
    cout<<endl;
  } //close for r loop
} //close print()


template <typename T>
IdentityMatrix<T>::IdentityMatrix(int size):Matrix<T>(size,size) {
  for (int i=0; i<size; ++i) {
    this->elements[i*size + i] = 1;
  }
}

template class IdentityMatrix<int>;
template class Matrix<int>;
