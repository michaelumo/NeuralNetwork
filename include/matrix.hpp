#ifndef MATRIX_
  #define MATRIX_

class Matrix {
public:
  int row, col;
  double** data;
  Matrix();
  Matrix(int, int, double);
  Matrix(int, int);
  Matrix(int, int, double *);
  Matrix operator+(const Matrix &other);
  Matrix operator-(const Matrix &other);
  Matrix operator*(const Matrix &other);
  Matrix operator*(double);
  Matrix transpose();
  Matrix map();
  double sigmoid(double);
  /*void subtract_matrix(int *, int *, int, int, int);//send a ,b, row of a, column of a
  void multiply_matrix(int *, int *, int, int, int*);//send a, column of a, b, column of b
  void transpose(int *, int *, int, int);
  void add_scalar(int *, int, int, int);
  void subtract_scalar(int *, int, int, int, int);
  void divide_scalar(int *, int, int, int);
  void multiply_scalar(int *, int, int, int);*/
};

#endif
