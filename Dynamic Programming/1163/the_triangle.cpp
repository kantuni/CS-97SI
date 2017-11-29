#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
  int n;
  cin >> n;
  vvi t(n);
  for (int i = 0; i < n; i++) {
    vi r(i + 1);
    for (int j = 0; j < i + 1; j++) {
      cin >> r[j];
    }
    t[i] = r;
  }
  for (int i = t.size() - 2; i >= 0; i--) {
    for (int j = 0; j < t[i].size(); j++) {
      t[i][j] += max(t[i + 1][j], t[i + 1][j + 1]);
    }
  }
  cout << t[0][0] << "\n";
  return 0;
}
