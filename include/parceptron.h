#ifndef PARCEPTRON_
  #define PARCEPTRON_

  // #include <iostream>
  // #include <cmath>
  // #include <ctime>
  // #include <vector>
  // #include <iomanip>
//  #include "MT.h"
//  #include "matrix.h"


class Parceptron {
private:
  struct neurons{
    Matrix Weight;
    Matrix Bias;
    Matrix Fire;
  };
  std::vector<neurons> layer;
  Matrix map(const Matrix &a);
  Matrix dsigmoid(const Matrix &a);
  Matrix merge(const Matrix &a, const Matrix &b);
public:
  Matrix Inputs;
  Matrix Outputs;
  int inputSize, outputSize, hiddenSize;
  double rate = 0.01;
  Parceptron(std::vector<int> v, double r);
  ~Parceptron();
  void feedforward(Matrix &in);
  void train(Matrix &target);
  double sigmoid(double x);
};

Parceptron::Parceptron(std::vector<int> v, double r){
  neurons tmp;
  rate = r;
  layer.push_back(tmp);
  std::srand(std::time(NULL));//TODO: not truely random
  init_genrand(std::rand());
  for(int i = 1; i < v.size(); i++){
    neurons n;
    n.Weight = Matrix(v[i-1],v[i]);
    for(int j = 0; j < n.Weight.getRows(); j++){
      for(int k = 0; k < n.Weight.getCols(); k++){
        n.Weight(j,k) = (genrand_int32()%2001-1000.0)/1000.0;
      }
    }
    n.Bias = Matrix(v[i]);
    for(int j = 0; j < v[i]; j++){
      n.Bias(j) = 1.0;
    }
    n.Bias = n.Bias.t();
    layer.push_back(n);
  }

}

Parceptron::~Parceptron()
{
	;
}

void Parceptron::train(Matrix &target){
  Matrix Errors;
  Matrix HiddenErrors;
  Matrix delta_Weight;
  //--Output Neuron
  Errors = target-Outputs;
  HiddenErrors = Errors;
  delta_Weight = layer[layer.size()-2].Fire.t()*(Errors*rate);
  layer[layer.size()-1].Weight = layer[layer.size()-1].Weight+delta_Weight;
  //std::cout<<"helloooo"<<std::endl;
  layer[layer.size()-1].Bias = layer[layer.size()-1].Bias+(Errors*rate);
  //--

  for(int i = layer.size()-2; i > 0; i--){
    HiddenErrors = HiddenErrors*layer[i+1].Weight.t();
    Matrix hidgrad = dsigmoid(layer[i].Fire);
    hidgrad = merge(HiddenErrors, hidgrad);
    hidgrad = hidgrad*rate;
    delta_Weight = layer[i-1].Fire.t()*hidgrad;
    layer[i].Weight = layer[i].Weight+delta_Weight;
    layer[i].Bias = layer[i].Bias+hidgrad;
  }

}

void Parceptron::feedforward(Matrix &in){
  layer[0].Fire = in;
  for(int i = 1; i < layer.size(); i++){
    if(i == layer.size()-1)layer[i].Fire = layer[i-1].Fire*layer[i].Weight+layer[i].Bias;
    else layer[i].Fire = map(layer[i-1].Fire*layer[i].Weight+layer[i].Bias);
  }
  Outputs = layer[layer.size()-1].Fire;
}

Matrix Parceptron::map(const Matrix &a){
  Matrix d(a.getRows(), a.getCols());
  for (int i = 0; i < a.getRows(); i++){
    for(int j = 0; j < a.getCols(); j++){
      d(i,j) = sigmoid(a(i,j));
    }
  }
  return d;
}

Matrix Parceptron::dsigmoid(const Matrix &a){
  Matrix d(a.getRows(),a.getCols());
  for (int i = 0; i < a.getRows(); i++){
    for(int j = 0; j < a.getCols(); j++){
      d(i,j) = a(i,j)*(1.0-a(i,j));
    }
  }
  return d;
}

Matrix Parceptron::merge(const Matrix &a, const Matrix &b){
  if(a.getRows() != b.getRows() || a.getCols() != b.getCols()){
    std::cout<<"INDEX ERROR merge"<<std::endl;
    exit(1);
  }
  Matrix d(a.getRows(), a.getCols());
  for (int i = 0; i < a.getRows(); i++){
    for(int j = 0; j < a.getCols(); j++){
      d(i,j) = a(i,j)*b(i,j);
    }
  }
  return d;
}

double Parceptron::sigmoid(double x){
  return 1.0/(1.0+std::exp(-x));
}

#endif
