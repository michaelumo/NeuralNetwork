#include <iostream>
#include <cmath>
#include "matrix.hpp"

int main(void){
  Matrix B(3,3,1);
  Matrix G(1,1,10);
  Matrix D(3,3,3);
  Matrix C(3,3,5);
  C = B^D*2;
  for(int i = 0; i < C.row; i++){
    std::cout<<"| ";
    for(int j = 0; j < C.col; j++){
      std::cout << C.data[i][j] <<" ";
    }
    std::cout<<"|"<<std::endl;
  }
  return 0;
}
