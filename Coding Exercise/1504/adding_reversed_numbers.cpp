#include <iostream>
using namespace std;

typedef long long ll;

ll reverse(ll x) {
  ll rx = 0;
  while (x != 0) {
    rx *= 10;
    rx += x % 10;
    x /= 10;
  }
  return rx;
}

ll rsum(ll x, ll y) {
  ll rx = reverse(x);
  ll ry = reverse(y);
  
  ll s = rx + ry;
  ll rs = reverse(s);
  
  // remove trailing zeroes
  while (rs % 10 == 0) {
    rs /= 10;
  }
  
  return rs;
}

int main() {
  lll N;
  cin >> N;
  for (ll i = 0; i < N; i++) {
    ll x, y;
    cin >> x >> y;
    cout << rsum(x, y) << "\n";
  }
  return 0;
}
