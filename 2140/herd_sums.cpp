#include <iostream>
using namespace std;

typedef long long ll;

int main() {
  ll N;
  cin >> N;
  
  ll counter = 1;
  for (ll i = 2; i < N; ++i) {
    // solution to x + (x + 1) + (x + 2) ... = N, where x > 0
    ll numerator = 2 * N - i * (i - 1);
    ll denominator = 2 * i;
    if (numerator > 0 && numerator % denominator == 0) {
      ++counter;
    }
  }
  
  cout << counter << "\n";
  return 0;
}
