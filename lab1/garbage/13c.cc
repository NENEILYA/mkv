#include <stdio.h>
#define H_SIZE 4
#define V_SIZE 5

int factorial(int n) {
  long factorial = 1.0;
  for (int i = 1; i <= n; ++i) {
    factorial *= i;
  }
  return factorial;
}

int helper(int *path, int *idx) {
  int count = 0;
  for (int i = 0; i < *idx; i++) {
    if (path[i] == 0) {
      count++;
    }
  }
  return count;
}

void transposed(int *path, int len, int *idx) {
  int prev = 1;
  int cur, memory;
  for (int i = 0; i < len; i++) {
    cur = path[i];
    if (cur == 1 && prev == 0) {
      *idx = i - 1;
      break;
    }
    prev = cur;
  }
  memory = path[*idx];
  path[*idx] = path[*idx + 1];
  path[*idx + 1] = memory;
}

void move_one_to_transosed(int *path, int *idx) {
  int prev = 1;
  for (int j = 0; j < helper(path, idx); j++) {
    for (int i = *idx - 1; i >= 0; i--) {
      if (path[i] == 1 && prev == 0) {
        path[i] = 0;
        path[i + 1] = 1;
      }
      prev = path[i];
    }
  }
}

void print_path(int *bin_path, int min_path) {
  for (int i = 0; i < min_path; i++) {
    if (bin_path[i] == 0) {
      printf("H");
    } else if (bin_path[i] == 1) {
      printf("V");
    } else {
      printf("ERROR");
    }
  }
  printf("\n");
}

int main() {
  int const min_path = H_SIZE + V_SIZE;
  int bin_path[min_path] = {};
  int idx;
  for (int i = H_SIZE; i < min_path; i++) {
    bin_path[i] = 1;
  }
  print_path(bin_path, min_path);
  int total_combinations = factorial(min_path) /
                           (factorial(V_SIZE) * (factorial(min_path - V_SIZE)));
  for (int i = 1; i < total_combinations; i++) {
    transposed(bin_path, min_path, &idx);
    move_one_to_transosed(bin_path, &idx);
    print_path(bin_path, min_path);
  }
}
