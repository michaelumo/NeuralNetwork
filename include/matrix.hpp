#ifndef MATRIX_
  #define MATRIX_

class Matrix {
public:
  void add_matrix(int *, int *, int, int);//send a ,b, row of a, column of a
  void subtract_matrix(int *, int *, int, int);//send a ,b, row of a, column of a
  void multiply_matrix(int *, int, int *, int, int*);//send a, column of a, b, column of b
  void add_scalar(int *, int, int, int);
  void subtract_scalar(int *, int, int, int, int);
  void divide_scalar(int *, int, int, int);
  void multiply_scalar(int *, int, int, int);
};

#endif
