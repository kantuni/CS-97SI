#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
  const int P = 1000000;
  vector<bool> primes(P, 1);
  primes[0] = primes[1] = 0;
  for (int i = 2; i * i < P; i++) {
    if (primes[i]) {
      for (int j = 0; i * i + j * i < P; j++) {
        primes[i * i + j * i] = 0;
      }
    }
  }
  while (true) {
    int n;
    cin >> n;
    if (n == 0) {
      break;
    }
    bool found = false;
    int a, b;
    for (int i = 3; i <= n / 2; i++) {
      if (primes[i] && primes[n - i]) {
        found = true;
        a = i;
        b = n - i;
        break;
      }
    }
    if (found) {
      cout << n << " = " << a << " + " << b << endl;
    } else {
      cout << "Goldbach's conjecture is wrong." << endl;
    }
  }
  return 0;
}
