#include <iostream>
#include <set>
using namespace std;

int main() {
  set<int> V, S;
  int E = 0, i = 1;
  bool tree = true;
  while (true) {
    int s, t;
    cin >> s >> t;
    if (s == 0 && t == 0) {
      bool c1 = E == 0;  // empty tree
      bool c2 = E == V.size() - 1;  // |E| = n - 1
      bool c3 = S.size() == V.size() - 1;  // has only one root
      if (!c1 && !(tree && c2 && c3)) {
        tree = false;
      }
      cout << "Case " << i << " is ";
      if (!tree) {
        cout << "not ";
      }
      cout << "a tree." << "\n";
      // start from scratch
      tree = true;
      E = 0;
      V.clear();
      S.clear();
      // next case
      i++;
    } else if (s < 0 && t < 0) {
      break;
    } else if (s == t) {
      tree = false;
    } else {
      V.insert(s);
      V.insert(t);
      if (S.count(t) == 0) {
        S.insert(t);
      } else {
        tree = false;
      }
      E++;
    }
  }
  return 0;
}
