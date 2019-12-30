#include <iostream>
#include <cmath>
#include <stddef.h>
#include <iomanip>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "matrix.h"
#include "MT.h"
#include "parceptron.h"

//double sigmoid(double);

int main(void){
  int nm = 10;
  std::vector<int> layers;
  layers.push_back(2);
  layers.push_back(nm);
  layers.push_back(nm);
  //layers.push_back(nm);
  layers.push_back(1);
  Parceptron p(layers);
  Matrix in(1,2);
  Matrix target(1,1);
  std::srand(std::time(NULL));
  for(int i = 0; i< 100000; i++){
    in(0,0) = std::rand()%2;
    //std::cout<<in[0][0]<<std::endl;
    in(0,1) = std::rand()%2;
    //in.show_gorgeous();
    //std::cout<<in[0][1]<<std::endl;
    p.feedforward(in);
    //std::cout<<"helloooo"<<std::endl;
    if(in(0,0) == in(0,1))target(0,0) = 0;
    else target(0,0) = 1;
    p.train(target);
  }

  in(0,0) = 0;
  in(0,1) = 0;
  p.feedforward(in);
  //in.show_gorgeous();
  p.Outputs.show_gorgeous();


  in(0,0) = 0;
  in(0,1) = 1;
  p.feedforward(in);
  //in.show_gorgeous();
  p.Outputs.show_gorgeous();


  in(0,0) = 1;
  in(0,1) = 0;
  p.Outputs.show_gorgeous();


  in(0,0) = 1;
  in(0,1) = 1;
  p.feedforward(in);
  //in.show_gorgeous();

  p.Outputs.show_gorgeous();

  return 0;
}
