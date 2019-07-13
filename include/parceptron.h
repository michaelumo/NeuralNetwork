#ifndef PARCEPTRON_
  #define PARCEPTRON_

  #include <iostream>
  #include <cmath>
  #include <ctime>
  #include <vector>
  #include <iomanip>
  #include "MT.h"
  #include "matrix.h"


class Parceptron {
private:
  struct neurons{
    Matrix Weight;
    Matrix Bias;
    Matrix Fire;
  };

  std::vector<neurons> layer;
  //static double sigmoid(double);
public:
  Matrix Inputs;
  Matrix Outputs;
  int inputSize, outputSize, hiddenSize;
  double rate = 0.01;
  Parceptron(std::vector<int> v);
  ~Parceptron();
  void feedforward(Matrix &in);
  void train(Matrix &target);
  double sigmoid(double);
};

Parceptron::Parceptron(std::vector<int> v){
  neurons tmp;
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
    //std::cout<<"helloooo"<<std::endl;
    //n.Weight.show_gorgeous();
    n.Bias = Matrix(1,v[i],1.0);
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
  //Output Neuron
  //std::cout<<"helloooo"<<std::endl;
  Errors = target-Outputs;
  //Errors.show_gorgeous();
  //std::cout<<"helloooo"<<std::endl;
  HiddenErrors = Errors*layer[layer.size()-1].Weight.t();

  Matrix grad = Outputs.dsigmoid();
  grad = Errors*grad;
  grad = grad*rate;
  delta_Weight = layer[layer.size()-2].Fire.t()*grad;
  layer[layer.size()-1].Weight = layer[layer.size()-1].Weight+delta_Weight;
  //std::cout<<"helloooo"<<std::endl;
  layer[layer.size()-1].Bias = layer[layer.size()-1].Bias+grad;
  //
  //HiddenErrors.show_gorgeous();

  for(int i = layer.size()-2; i > 0; i--){
    Matrix hidgrad = layer[i].Fire.dsigmoid();
    hidgrad = HiddenErrors.merge(hidgrad);
    HiddenErrors = HiddenErrors*layer[i].Weight.t();
    hidgrad = hidgrad*rate;
    delta_Weight = layer[i-1].Fire.t()*hidgrad;
    //std::cout<<WeightIH.row<<" "<<WeightIH.col<<std::endl;
    //std::cout<<delta_IH_Weight.row<<" "<<delta_IH_Weight.col<<std::endl;
    layer[i].Weight = layer[i].Weight+delta_Weight;
    layer[i].Bias = layer[i].Bias+hidgrad;
  }

}

void Parceptron::feedforward(Matrix &in){
  layer[0].Fire = in;
  for(int i = 1; i < layer.size(); i++){
    layer[i].Fire = (layer[i-1].Fire*layer[i].Weight+layer[i].Bias).map();
  }
  Outputs = layer[layer.size()-1].Fire;
}



#endif
