#include <iostream>
using namespace std;

int main() {
  long long N;
  cin >> N;
  long long counter = 1;
  for (long long i = 2; i < N; i++) {
    // solution to x + (x + 1) + (x + 2) ... = N, where x > 0
    long long num = 2 * N - i * (i - 1);
    long long denom = 2 * i;
    if (num > 0 && num % denom == 0) {
      counter++;
    }
  }
  cout << counter << "\n";
  return 0;
}
