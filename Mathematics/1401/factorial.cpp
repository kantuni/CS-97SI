#include <iostream>
using namespace std;

long long z(long long n) {
  long long cnt = 0;
  while (n >= 5) {
    n /= 5;
    cnt += n;
  }
  return cnt;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long n;
    cin >> n;
    cout << z(n) << endl;
  }
  return 0;
}
