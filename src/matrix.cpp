#include <iostream>
#include "matrix.hpp"

void Matrix::add_matrix(int *A, int *B, int row, int col){
  //TODO: Check if the size of the matrix are correct
  for(int i = 0; i < row; i++){
    std::cout<<"| ";
    for(int j = 0; j < col; j++){
      *(A+i*col+j) += *(B+i*col+j);
      std::cout << *(A+i*col+j) <<" ";
    }
    std::cout<<"|"<<std::endl;
  }
}

void Matrix::multiply_matrix(int *A, int Am, int *B, int Bm, int *C){
  //*(I n m)
  int An = Bm; //sizeof(A[0])/sizeof(int);
  for (int k = 0; k < An; k++){
    std::cout<<"| ";
    for(int i = 0; i < An; i++){
      int sum = 0;
      for(int j = 0; j < Am; j++){
        sum += *(A+k*Am+j) * *(B+j*Bm+i);
      }
      *(C+k+Am*i) = sum;
      std::cout << *(C+k+Am*i) <<" ";
    }
    std::cout<<"|"<<std::endl;
  }
}

void Matrix::subtract_matrix(int *A, int *B, int row, int col){
  for(int i = 0; i < row; i++){
    std::cout<<"| ";
    for(int j = 0; j < col; j++){
      *(A+i*col+j) -= *(B+i*col+j);
      std::cout << *(A+i*col+j) <<" ";
    }
    std::cout<<"|"<<std::endl;
  }
}

void Matrix::multiply_scalar(int *A, int B, int An, int Am){
  for(int i=0; i < An; i++){
    for(int j = 0; j < Am; j++){
      *(A+i*Am+j) *= B;
    }
  }
}

void Matrix::divide_scalar(int *A, int B, int An, int Am){
  for(int i=0; i < An; i++){
    for(int j = 0; j < Am; j++){
      *(A+i*Am+j) /= B;
    }
  }
}

void Matrix::add_scalar(int *A, int B, int An, int Am){
  int I[An][Am];
  for(int i = 0; i<An; i++){
    for(int j = 0; j < Am; j++){
      if(i  == j)I[i][j] = 1;
      else I[i][j] = 0;
    }
  }
  multiply_scalar((int *)I, B, An, Am);
  add_matrix((int *)A, I, An, Am);
}

void Matrix::subtract_scalar(int *A, int B, int An, int Am, int reverse){
  int I[An][Am];
  for(int i = 0; i<An; i++){
    for(int j = 0; j < Am; j++){
      if(i  == j)I[i][j] = 1;
      else I[i][j] = 0;
    }
  }
  multiply_scalar((int *)I, B, An, Am);
  subtract_matrix((int *)A, I, An, Am);
  if (reverse)multiply_scalar((int *)A, -1, An, Am);
}
