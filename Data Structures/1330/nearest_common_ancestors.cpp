#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
  int T;
  cin >> T;
  
  for (int t = 0; t < T; ++t) {
    int n;
    cin >> n;
    
    map<int, int> tree;
    for (int i = 0; i < n - 1; ++i) {
      int parent, child;
      cin >> parent >> child;
      tree[child] = parent;
    }
    
    int x, y;
    cin >> x >> y;
    
    vector<int> anc(n + 100, 0);
    anc[x] = anc[y] = 1;
    
    while (true) {
      x = tree.count(x) > 0 ? tree[x] : -1;
      if (x > 0) {
        if (anc[x] == 1) {
          cout << x << "\n";
          break;
        } else {
          anc[x] = 1;
        }
      }
      
      y = tree.count(y) > 0 ? tree[y] : -1;
      if (y > 0) {
        if (anc[y] == 1) {
          cout << y << "\n";
          break;
        } else {
          anc[y] = 1;
        }
      }
    }
  }
  
  return 0;
}
