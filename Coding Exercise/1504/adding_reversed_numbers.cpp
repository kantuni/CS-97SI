#include <iostream>
using namespace std;

typedef long long ull;

ull reverse(ull x) {
  ull rx = 0;
  while (x != 0) {
    rx *= 10;
    rx += x % 10;
    x /= 10;
  }
  return rx;
}

ull rsum(ull x, ull y) {
  ull rx = reverse(x);
  ull ry = reverse(y);
  
  ull s = rx + ry;
  ull rs = reverse(s);
  
  // remove trailing zeroes
  while (rs % 10 == 0) {
    rs /= 10;
  }
  
  return rs;
}

int main() {
  ull N;
  cin >> N;
  
  for (ull i = 0; i < N; ++i) {
    ull x, y;
    cin >> x >> y;
    cout << rsum(x, y) << "\n";
  }
  
  return 0;
}
