#include <iostream>
#include "matrix.hpp"

void Matrix::add_matrix(int *A, int *B, int row, int col){ //WORKING
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

void Matrix::multiply_matrix(int *A, int *B, int row, int col, int *C){ //WORKING
  //*(I n m)
  for (int k = 0; k < col; k++){
    std::cout<<"| ";
    for(int i = 0; i < col; i++){
      int sum = 0;
      for(int j = 0; j < row; j++){
        sum += *(A+k*row+j) * *(B+j*col+i);
      }
      *(C+k+row*i) = sum;
      std::cout << *(C+k+row*i) <<" ";
    }
    std::cout<<"|"<<std::endl;
  }
}

void Matrix::subtract_matrix(int *A, int *B, int row, int col, int reverse){ //WORKING
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      *(A+i*col+j) -= *(B+i*col+j);
    }
  }
  if (reverse)multiply_scalar((int *) A, -1, row, col);
}

void Matrix::multiply_scalar(int *A, int B, int row, int col){ //WORKING
  for(int i=0; i < row; i++){
    std::cout<<"| ";
    for(int j = 0; j < col; j++){
      *(A+i*col+j) *= B;
      std::cout << *(A+i*col+j) <<" ";
    }
    std::cout<<"|"<<std::endl;
  }
}

void Matrix::divide_scalar(int *A, int B, int row, int col){ //WORKING
  for(int i=0; i < row; i++){
    for(int j = 0; j < col; j++){
      *(A+i*col+j) /= B;
    }
  }
}

void Matrix::add_scalar(int *A, int B, int row, int col){ //WORKING
  int I[row][col];
  for(int i = 0; i<row; i++){
    std::cout<<"| ";
    for(int j = 0; j < col; j++){
      if(i  == j)I[i][j] = 1;
      else I[i][j] = 0;
      std::cout << I[i][j] <<" ";
    }
    std::cout<<"|"<<std::endl;
  }
  multiply_scalar((int *)I, B, row, col);
  add_matrix((int *)A, (int *)I, row, col);
}

void Matrix::subtract_scalar(int *A, int B, int row, int col, int reverse){ //WORKING
  int I[row][col];
  for(int i = 0; i<row; i++){
    for(int j = 0; j < col; j++){
      if(i  == j)I[i][j] = 1;
      else I[i][j] = 0;
    }
  }
  multiply_scalar((int *)I, B, row, col);
  subtract_matrix((int *)A, (int *)I, row, col, reverse);
}
