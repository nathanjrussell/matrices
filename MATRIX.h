#ifndef MATRIX_H
#define MATRIX_H
using namespace std;

template <typename T>
class Matrix {
  protected:
    int numRows;
    int numCols;
    T *elements = 0;

  public:
    ~Matrix();
    Matrix();
    Matrix(int r, int c);
    void setDim(int r, int c);
    void print();
    int getNumRows();
    int getNumCols();
    void getDim(int *values);

    //operation overloads
    T operator()(int r,int c);
    void operator*=(T scalar);
    void operator+=(T scalar);
};

template <class T>
class IdentityMatrix: public Matrix<T> {
   public:
      IdentityMatrix(int size);
};

template <class T>
class RandomMatrix: public Matrix<T> {
   public:
      RandomMatrix(int size, T lowerBound, T upperBound);
};

template <class T>
class KroneckerProduct: public Matrix<T> {
   public:
    KroneckerProduct(Matrix<T> &A, Matrix<T> &B);
    //operation overloads

};


#include "MATRIX.tpp"
#endif
