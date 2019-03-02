#include <iostream>
#include <cmath>
#include "matrix.hpp"
#include <ctime>
#include <cstdlib>
#include "parceptron.hpp"

double sigmoid(double);

int main(void){
  Parceptron p(2,100,1);
  double in[1][2] = {{1,0}};
  double target[1][1] = {{1}};
  std::srand(std::time(NULL));

  for(int i = 0; i< 50000; i++){
    in[0][0] = std::rand()%2;
    //std::cout<<in[0][0]<<std::endl;
    in[0][1] = std::rand()%2;
    //std::cout<<in[0][1]<<std::endl;
    p.feedforward((double *) in);
    if((in[0][0] && in[0][1]) || (!in[0][0] && !in[0][1]))target[0][0] = 0;
    else target[0][0] = 1;
    p.train((double *)target);
  }

  in[0][0] = 0;
  in[0][1] = 0;
  p.feedforward((double *) in);
  for(int i = 0; i < p.Outputs.row; i++){
    std::cout<<"| ";
    for(int j = 0; j < p.Outputs.col; j++){
      std::cout << p.Outputs.data[i][j] <<" ";
    }
    std::cout<<"|"<<std::endl;
  }

  in[0][0] = 0;
  in[0][1] = 1;
  p.feedforward((double *) in);
  for(int i = 0; i < p.Outputs.row; i++){
    std::cout<<"| ";
    for(int j = 0; j < p.Outputs.col; j++){
      std::cout << p.Outputs.data[i][j] <<" ";
    }
    std::cout<<"|"<<std::endl;
  }


  in[0][0] = 1;
  in[0][1] = 0;
  p.feedforward((double *) in);
  for(int i = 0; i < p.Outputs.row; i++){
    std::cout<<"| ";
    for(int j = 0; j < p.Outputs.col; j++){
      std::cout << p.Outputs.data[i][j] <<" ";
    }
    std::cout<<"|"<<std::endl;
  }


  in[0][0] = 1;
  in[0][1] = 1;
  p.feedforward((double *) in);
  for(int i = 0; i < p.Outputs.row; i++){
    std::cout<<"| ";
    for(int j = 0; j < p.Outputs.col; j++){
      std::cout << p.Outputs.data[i][j] <<" ";
    }
    std::cout<<"|"<<std::endl;
  }



  return 0;
}
