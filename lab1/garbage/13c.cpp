#include <iostream>

#define H_SIZE 4
#define V_SIZE 5

int main() {
  int const min_path = H_SIZE + V_SIZE;
  int bin_path[min_path] = {};
  for (int i = H_SIZE; i < min_path; i++) {
    bin_path[i] = 1;
  }
  for (int i = 0; i < min_path; i++) {
    std::cout << "bin_path[" << i << "] = " << bin_path[i] << std::endl;
  }
  return 0;
}
