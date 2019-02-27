#include <iostream>
#include "matrix.hpp"

int main(void){
  Matrix m;
  int a[3][1] = {{1},{2},{3}};
  int b[1][3] = {{1,2,3}};
  int d[1][3] = {{1,2,3}};
  int c[3][3];
  m.subtract_matrix((int *)b, (int *)d, sizeof b / sizeof b[0], sizeof b[0] / sizeof (int), 0);
  std::cout<<std::endl;
  m.add_matrix((int *)b, (int *)d, sizeof b / sizeof b[0], sizeof b[0] / sizeof (int));
  std::cout<<std::endl;
  m.subtract_scalar((int *)b, 2, sizeof b / sizeof b[0], sizeof b[0] / sizeof (int), 0);
  std::cout<<std::endl;
  m.multiply_matrix((int *)a, (int *)b, sizeof a[0]/ sizeof (int), sizeof b[0]/ sizeof (int), (int *)c);
  return 0;
}
