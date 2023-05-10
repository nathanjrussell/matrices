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
    // virtual int area();
};

template <class T>
class IdentityMatrix: public Matrix<T> {
   public:
      IdentityMatrix(int size);
};


// class RandomMatrix: public Matrix {
//    public:
//       RandomMatrix(int r, int c):Matrix(r, c) {};
//       // int area ();
// };

#endif
