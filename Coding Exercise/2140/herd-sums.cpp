#include <iostream>
using namespace std;

int main() {
  long long n;
  cin >> n;
  long long ans = 1;
  for (long long i = 2; i < n; i++) {
    // solution to x + (x + 1) + (x + 2) ... = n, where x > 0
    long long num = 2 * n - i * (i - 1);
    long long denom = 2 * i;
    if (num > 0 && num % denom == 0) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
