#include <iostream>
#include <cmath>
#include "parceptron.hpp"
#include "matrix.hpp"

//Matrix m;

Parceptron::Parceptron(int in, int hid, int out){
  inputSize = in;
  hiddenSize = hid;
  outputSize = out;
  WeightIH = Matrix(hiddenSize, inputSize);
  WeightHO = Matrix(outputSize, hiddenSize);
  BiasH = Matrix(hiddenSize, 1, 1.0);
  BiasO = Matrix(outputSize, 1, 1.0);
}

void Parceptron::train(double* t){
  target = Matrix(outputSize, 1, (double *)t);
  Errors = target-Outputs;
  HiddenErrors = WeightHO.transpose()*Errors;

  Matrix grad = Outputs+(Matrix(Outputs.row, Outputs.col, 1)-Outputs);
  grad = grad*Errors;
  grad = grad*rate;
  delta_HO_Weight = grad*Hidden.transpose();
  WeightHO = WeightHO+delta_HO_Weight;
  BiasO = BiasO+grad;

  Matrix hidgrad = Hidden+(Matrix(Hidden.row, Hidden.col, 1)-Hidden);
  std::cout<<" "<<"INCORRECT INDEX "<<hidgrad.row<< " "<< hidgrad.col<<std::endl;
  std::cout<<" "<<"INCORRECT INDEX "<<HiddenErrors.row<< " "<< HiddenErrors.col<<std::endl;
  hidgrad = hidgrad*HiddenErrors;
  std::cout<<" "<<"WTF!!!!!!!!!"<<std::endl;
  hidgrad = hidgrad*rate;

  delta_IH_Weight = hidgrad*Inputs.transpose();
  WeightIH = WeightIH+delta_IH_Weight;
  BiasH = BiasH+hidgrad;
}

void Parceptron::feedforward(double* in){
  Inputs = Matrix(inputSize, 1,(double *)in);
  std::cout<<" "<<"INCORRECT INDEX 1 "<<WeightIH.data[0][0]<< " "<< WeightIH.data[0][1]<<std::endl;
  std::cout<<" "<<"INCORRECT INDEX 1 "<<WeightHO.data[0][0]<< " "<< WeightHO.data[0][1]<<std::endl;
  Hidden = (WeightIH*Inputs+BiasH).map();
  std::cout<<" "<<"INCORRECT INDEX 2 "<<Hidden.data[0][0]<< " "<< Hidden.data[1][0]<<std::endl;
  Outputs = (WeightHO*Hidden+BiasO).map();
}
