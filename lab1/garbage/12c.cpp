#include <bitset>
#include <cmath>
#include <iostream>
#define H_SIZE 4
#define V_SIZE 5

int factorial(int n) {
  long factorial = 1.0;
  for (int i = 1; i <= n; ++i) {
    factorial *= i;
  }
  return factorial;
}

void magic(int *path, int min_path, int lead_zeros, int lead_ones) {
  *path = *path + pow(2, lead_zeros) + pow(2, lead_ones - 1) - 1;
}

void helper(int path, int min_path, int *lead_zeros, int *lead_ones) {
  *lead_ones = 0;
  *lead_zeros = 0;
  for (int i = 0; i < min_path; i++) {
    int value = path >> i;
    if (!(value & 1)) {
      if (*lead_ones > 0) {
        break;
      }
      *lead_zeros += 1;
    } else if ((value & 1) && (*lead_zeros > 0)) {
      *lead_ones += 1;
    }
  }
}
// int main() {
//   std::cout << "Start testing" << std::endl;
//   int const min_path = H_SIZE + V_SIZE;
//   int lead_ones, lead_zeros;
//   int path = 0;
//   for (int i = 0; i < V_SIZE; i++) {
//     path += pow(2, i);
//   }
//   // path = 0b1111111111101;
//   std::cout << std::bitset<min_path + 10>(path) << std::endl;
//   helper(path, min_path, &lead_zeros, &lead_ones);
//   std::cout << "Lead zeros=" << lead_zeros << std::endl;
//   std::cout << "Lead ones=" << lead_ones << std::endl;
//   magic(&path, min_path, lead_zeros, lead_ones);
//   std::cout << std::bitset<min_path + 10>(path) << std::endl;
// }

int main() {
  int const min_path = H_SIZE + V_SIZE;
  int lead_ones, lead_zeros;
  int path = 0;
  for (int i = 0; i < V_SIZE; i++) {
    path += pow(2, i);
  }
  int total_combinations = factorial(min_path) /
                           (factorial(V_SIZE) * (factorial(min_path - V_SIZE)));
  for (int i = 1; i < total_combinations; i++) {
    helper(path, min_path, &lead_zeros, &lead_ones);
    std::cout << std::bitset<min_path>(path) << std::endl;
    magic(&path, min_path, lead_zeros, lead_ones);
  }
}
