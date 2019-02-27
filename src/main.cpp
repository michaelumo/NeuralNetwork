#include <iostream>
#include <cmath>
#include "matrix.hpp"
#include "parceptron.hpp"

double sigmoid(double);

int main(void){
  Parceptron p(2,2,1);
  double in[2][1] = {{1},{0}};
  double target[1][1] = {{1}};
  p.feedforward((double *) in);
  p.train((double *)target);
  for(int i = 0; i < p.Outputs.row; i++){
    std::cout<<"| ";
    for(int j = 0; j < p.Outputs.col; j++){
      std::cout << p.Outputs.data[i][j] <<" ";
    }
    std::cout<<"|"<<std::endl;
  }
  return 0;
}
