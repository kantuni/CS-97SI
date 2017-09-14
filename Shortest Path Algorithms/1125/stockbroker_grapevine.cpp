#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF (int) 1e9

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
  while (true) {
    int n;
    cin >> n;
    
    if (n == 0) {
      break;
    }
    
    // create the adjacency matrix
    vvi D;
    for (int i = 0; i < n; ++i) {
      vi row(n, INF);
      D.push_back(row);
      D[i][i] = 0;
    }

    // read input data
    for (int i = 0; i < n; ++i) {
      int m;
      cin >> m;
      
      for (int j = 0; j < m; ++j) {
        int t, c;
        cin >> t >> c;
        D[i][t - 1] = c;
      }
    }
    
    // Floyd-Warshall
    for (int k = 1; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
        }
      }
    }
    
    // check if all nodes are reachable at least from one node
    bool reachable = true;
    int s, sc = 0;
    
    for (int i = 0; i < n; ++i) {
      reachable = false;
      for (int j = 0; i != j && j < n; ++j) {
        if (D[j][i] != INF) {
          reachable = true;
          break;
        }
      }
      
      if (!reachable) {
        ++sc;
        s = i;
        break;
      }
    }
    
    bool disjoint = false;
    if (sc > 1) {
      disjoint = true;
    } else if (sc == 1) {
      for (int i = 0; i != s && i < n; ++i) {
        if (D[s][i] == INF) {
          disjoint |= true;
        }
      }
    }
    
    if (disjoint) {
      cout << "disjoint" << "\n";
      continue;
    }
    
    // find the fastest stockbroker and the time it takes
    // to spread the news to all his contractors
    int stockbroker;
    int min = INF;
    
    for (int i = 0; i < D.size(); ++i) {
      int max = *max_element(D[i].begin(), D[i].end());
      if (max != INF && max < min) {
        min = max;
        stockbroker = i;
      }
    }
    
    // output the answer
    cout << stockbroker + 1 << " " << min << "\n";
  }
  
  return 0;
}
