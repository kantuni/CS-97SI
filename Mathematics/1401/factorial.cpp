#include <iostream>
using namespace std;

typedef long long ll;

ll z(ll n) {
  ll counter = 0;
  while (n >= 5) {
    n /= 5;
    counter += n;
  }
  return counter;
}

int main() {
  int t;
  cin >> t;
  
  for (int i = 0; i < t; ++i) {
    ll n;
    cin >> n;
    cout << z(n) << "\n";
  }
  
  return 0;
}
