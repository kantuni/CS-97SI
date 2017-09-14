#include <iostream>
#include <set>
using namespace std;

int main() {
  set<int> V;
  set<int> S;
  int E = 0;
  
  int i = 1;
  bool is_a_tree = true;
  
  while (true) {
    int s, t;
    cin >> s >> t;
    
    if (s == 0 && t == 0) {
      bool c1 = E == 0;  // empty tree
      bool c2 = E == V.size() - 1;  // |E| = n - 1
      bool c3 = S.size() == V.size() - 1;  // has only one root
      
      if (!c1 && !(is_a_tree && c2 && c3)) {
        is_a_tree = false;
      }
      
      cout << "Case " << i << " is ";
      if (!is_a_tree) cout << "not ";
      cout << "a tree." << "\n";
      
      // start from scratch
      is_a_tree = true;
      E = 0;
      V.clear();
      S.clear();
      
      // next case
      ++i;
    } else if (s < 0 && t < 0) {
      break;
    } else if (s == t) {
      is_a_tree = false;
    } else {
      V.insert(s);
      V.insert(t);
      
      if (S.count(t) == 0) {
        S.insert(t);
      } else {
        is_a_tree = false;
      }
      
      ++E;
    }
  }
  
  return 0;
}
