#include <iostream>
#include <cmath>
#include "parceptron.hpp"
#include "matrix.hpp"

//Matrix m;

//Parceptron::Parceptron(){

//}

void Parceptron::train(){
  std::cout << "parceptron" << std::endl;
}

double Parceptron::sigmoid(double x){
  return 1/(1+std::exp(-x));
}
