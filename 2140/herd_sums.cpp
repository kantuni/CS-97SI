#include <iostream>
using namespace std;

typedef unsigned long long ull;

int main() {
  ull N;
  cin >> N;
  
  int counter = 1;
  for (int i = 2; i <= (N + 1) / 2; ++i) {
    // solution to x + (x + 1) + (x + 2) ... = N
    int numerator = 2 * N - i * (i - 1);
    int denominator = 2 * i;
    if (numerator != 0 && numerator % denominator == 0) {
      ++counter;
    }
  }
  
  cout << counter << "\n";
  return 0;
}
