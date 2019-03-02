#include <iostream>
#include <cmath>
#include "parceptron.hpp"
#include "matrix.hpp"

//Matrix m;

Parceptron::Parceptron(int in, int hid, int out){
  inputSize = in;
  hiddenSize = hid;
  outputSize = out;
  WeightIH = Matrix(inputSize, hiddenSize);
  WeightHO = Matrix(hiddenSize, outputSize);
  BiasH = Matrix(1, hiddenSize, 1.0);
  BiasO = Matrix(1, outputSize, 1.0);
}

void Parceptron::train(double* t){
  target = Matrix(outputSize, 1, (double *)t);
  Errors = target-Outputs;
  HiddenErrors = Errors*WeightHO.transpose();

  Matrix grad = Outputs.dsigmoid();
  grad = Errors*grad;
  grad = grad*rate;
  delta_HO_Weight = Hidden.transpose()*grad;
  WeightHO = WeightHO+delta_HO_Weight;
  BiasO = BiasO+grad;

  Matrix hidgrad = Hidden.dsigmoid();
  //std::cout<<" "<<"INCORRECT INDEX "<<hidgrad.row<<" "<< hidgrad.col<<std::endl;
  //std::cout<<" "<<"INCORRECT INDEX "<<HiddenErrors.row<<" "<< HiddenErrors.col<<std::endl;
  hidgrad = HiddenErrors.merge(hidgrad);
  hidgrad = hidgrad*rate;
  //std::cout<<hidgrad.row<<" "<<hidgrad.col<<std::endl;
  delta_IH_Weight = Inputs.transpose()*hidgrad;
  //std::cout<<WeightIH.row<<" "<<WeightIH.col<<std::endl;
  //std::cout<<delta_IH_Weight.row<<" "<<delta_IH_Weight.col<<std::endl;
  WeightIH = WeightIH+delta_IH_Weight;
  BiasH = BiasH+hidgrad;
}

void Parceptron::feedforward(double* in){
  Inputs = Matrix(1, inputSize,(double *)in);
  //std::cout<<" "<<"INCORRECT INDEX 1 "<<WeightIH.row<<" "<< WeightIH.col<<std::endl;
  //std::cout<<" "<<"INCORRECT INDEX 1 "<<Inputs.row<<" "<< Inputs.col<<std::endl;
  Hidden = (Inputs*WeightIH+BiasH).map();
  //std::cout<<" "<<"INCORRECT INDEX 2 "<<Hidden.row<< " "<< Hidden.col<<std::endl;
  Outputs = (Hidden*WeightHO+BiasO).map();
}
