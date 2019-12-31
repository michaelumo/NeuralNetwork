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


int main(void){
  int nm = 3;
  int epochs = 1000;
  Matrix tmp(1,2);
  std::vector<int> layers;
  layers.push_back(2);
  layers.push_back(nm);
  layers.push_back(1);

  Parceptron p(layers, 0.2);
  Matrix in(4,3);
  in<<0,0,0,
      0,2,2,
      2,0,2,
      2,2,0;
  Matrix target(1,1);
  std::srand(std::time(NULL));
  for(int i = 0; i< epochs; i++){
    for(int k = 0; k < in.getRows(); k++){
      tmp<<in(k,0),in(k,1);
      p.feedforward(tmp);
      target<<in(k,2);
      p.train(target);
    }
  }

  tmp<<0,0;
  p.feedforward(tmp);
  //in.show_gorgeous();
  p.Outputs.show_gorgeous();


  tmp<<0,2;
  p.feedforward(tmp);
  //in.show_gorgeous();
  p.Outputs.show_gorgeous();


  tmp<<2,0;
  p.feedforward(tmp);
  p.Outputs.show_gorgeous();


  tmp<<2,2;
  p.feedforward(tmp);
  p.Outputs.show_gorgeous();

  return 0;
}
