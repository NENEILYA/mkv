#include <bitset>
#include <cmath>
#include <iostream>
unsigned char word[] = "INTEGRAL";
unsigned char lead = 128; // 10000000

void printSequence(unsigned char B) {
  static int inRow = 0;
  if (inRow == 4) {
    std::cout << std::endl;
    inRow = 0;
  }
  std::cout << '{';
  for (int i = 0; i < 8; i++) {
    char digit = (B >> i) & 1;
    if (digit) {
      std::cout << word[i];
    }
  }
  std::cout << "} ";
  inRow++;
}
unsigned char nextSequence(unsigned char B, int n) {
  int E = 0, N = 0, counter = n;
  unsigned char testB = B;
  // count '1'
  while ((testB & lead) && counter) {
    E++;
    counter--;
    testB = testB << 1;
  }
  // count '0'
  while (!(testB & lead) && counter) {
    N++;
    counter--;
    testB = testB << 1;
  }
  printf("zeros = %d, ones = %d\n", N, E);
  unsigned char wipe = pow(2, n - E);
  printf("\n%d\n", n - E);
  int shift = pow(2, n - N + 1) - pow(2, n - N - E + 1);

  // additional code in direct
  if (shift < 0) {
    shift = ~shift + 1;
  }
  unsigned char transpose = pow(2, n - N - E - 1);

  printf("wipe = %d, shift = %d, transpose = %d\n", wipe, shift, transpose);
  return B + wipe + shift + transpose;
}
int main() {
  int const n = 8;
  unsigned char B = 15, newB = 15; // m = 4 (00001111)
  do {
    // printSequence(newB);
    std::cout << std::bitset<n>(newB) << std::endl;
    newB = nextSequence(newB, n);
  } while ((B & newB));
  printSequence(newB);
  std::cout << std::endl;
  return 0;
}
