#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n;
    cin >> n;
    vector<int> anc(n + 2, 0);
    for (int i = 0; i < n - 1; i++) {
      int parent, child;
      cin >> parent >> child;
      anc[child] = parent;
    }
    int x, y;
    cin >> x >> y;
    vector<int> common(n + 2, 0);
    common[x] = common[y] = 1;
    while (true) {
      if (x > 0) {
        x = anc[x] > 0 ? anc[x] : -1;
        if (common[x] == 1) {
          cout << x << "\n";
          break;
        } else {
          common[x] = 1;
        }
      }
      if (y > 0) {
        y = anc[y] > 0 ? anc[y] : -1;
        if (common[y] == 1) {
          cout << y << "\n";
          break;
        } else {
          common[y] = 1;
        }
      }
    }
  }
  return 0;
}
