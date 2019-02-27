#include <iostream>
#include <ctime>
#include <cstdlib>
#include "matrix.hpp"

Matrix::Matrix(int r, int c, double x){
  std::srand(std::time(nullptr));
  row = r;
  col = c;
  data = new int*[row];
  for(int i = 0; i < row; i++)data[i] = new int[col];
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      data[i][j] = x;//std::rand()%10+1;
    }
  }
}

/*Matrix::Matrix(int r, int c){
  std::srand(std::time(nullptr));
  row = r;
  col = c;
  data = new int*[row];
  for(int i = 0; i < row; i++)data[i] = new int[col];
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      data[i][j] = 2;//std::rand()%10+1;
    }
  }
}*/

Matrix::Matrix(int r, int c, double* d){
  std::srand(std::time(nullptr));
  row = r;
  col = c;
  data = new int*[row];
  for(int i = 0; i < row; i++)data[i] = new int[col];
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      data[i][j] = *(d+i*col+j);
    }
  }
}

Matrix Matrix::operator+(const Matrix &other){ //WORKING
  //TODO: Check if the size of the matrix are correct
  if(other.row != row || other.col != col)return Matrix(row, col,0.);
  double d[row][col];
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      d[i][j] = data[i][j]+other.data[i][j];
    }
  }
  return Matrix(row, col, (double *)d);
}

Matrix Matrix::operator-(const Matrix &other){ //WORKING
  //TODO: Check if the size of the matrix are correct
  if(other.row != row || other.col != col)return Matrix(row, col, 0.);
  double d[row][col];
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      d[i][j] = data[i][j]-other.data[i][j];
    }
  }
  return Matrix(row, col, (double *)d);
}

Matrix Matrix::operator^(const Matrix &other){ //WORKING
  if(other.row != col)return Matrix(row, col,0.);
  double d[row][other.col];
  for (int k = 0; k < row; k++){
    for(int i = 0; i < other.col; i++){
      int sum = 0;
      for(int j = 0; j < other.row; j++){
        sum += data[i][j] * other.data[j][i];
      }
      d[k][i]= sum;
    }
  }
  return Matrix(row, other.col, (double *)d);
}

Matrix Matrix::operator*(double x){ //WORKING
  double d[row][col];
  for (int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      d[i][j] = data[i][j]*x;
    }
  }
  return Matrix(row, col, (double *)d);
}

Matrix Matrix::transpose(){ //WORKING
  double d[col][row];
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      d[j][i] = data[i][j];
    }
  }
  return Matrix(col, row, (double *)d);
}

/*
void Matrix::multiply_scalar(int *A, int B){ //WORKING
  for(int i=0; i < row; i++){
    std::cout<<"| ";
    for(int j = 0; j < col; j++){
      *(A+i*col+j) *= B;
      std::cout << *(A+i*col+j) <<" ";
    }
    std::cout<<"|"<<std::endl;
  }
}

void Matrix::divide_scalar(int *A, int B){ //WORKING
  for(int i=0; i < row; i++){
    for(int j = 0; j < col; j++){
      *(A+i*col+j) /= B;
    }
  }
}

void Matrix::add_scalar(int *A, int B){ //WORKING
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

void Matrix::subtract_scalar(int *A, int B){ //WORKING
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
*/
