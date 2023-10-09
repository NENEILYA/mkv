
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

void magic(int *B, int n, int N, int E) {
  int remove = pow(2, n - E);
  int restore = pow(2, n - N + 1) - pow(2, n - N - E + 1);
  int transpose = pow(2, n - N - E - 1);
  if (restore < 0) {
    restore = ~restore + 1;
  }
  *B = *B + remove + restore + transpose;
}

void helper(int B, int n, int *N, int *E) {
  *E = 0;
  *N = 0;
  for (int i = (n - 1); i >= 0; i--) {
    int value = B >> i;
    if (value & 1) {
      if (*N > 0) {
        break;
      }
      *E += 1;
    } else {
      *N += 1;
    }
  }
}

void utils(int B, int n) {
  for (int i = (n - 1); i >= 0; i--) {
    int value = B >> i;
    if (value & 1) {
      printf("V");
    } else {
      printf("H");
    }
  }
  printf("\n");
}

int main() {
  int const n = H_SIZE + V_SIZE;
  int E, N;
  int B = 0;
  for (int i = 0; i < V_SIZE; i++) {
    B += pow(2, i);
  }

  int total_combinations =
      factorial(n) / (factorial(V_SIZE) * (factorial(n - V_SIZE)));

  for (int i = 0; i < total_combinations; i++) {
    helper(B, n, &N, &E);
    utils(B, n);
    magic(&B, n, N, E);
  }
}
