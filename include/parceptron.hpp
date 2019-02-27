#include "matrix.hpp"

#ifndef PARCEPTRON_
  #define PARCEPTRON_

class Parceptron {
private:
  //static double sigmoid(double);
public:
  Matrix Inputs;
  Matrix Outputs;
  Matrix Hidden;
  Matrix WeightIH;
  Matrix WeightHO;
  Matrix BiasH;
  Matrix BiasO;
  Matrix target;
  Matrix Errors;
  Matrix HiddenErrors;
  Matrix delta_IH_Weight, delta_HO_Weight;
  int inputSize, outputSize, hiddenSize;
  double rate = 0.1;
  Parceptron(int, int, int);
  void feedforward(double*);
  void train(double*);
  double sigmoid(double);
};

#endif
