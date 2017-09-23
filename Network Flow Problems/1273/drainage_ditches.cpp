#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
using namespace std;

#define INF (int) 1e9

typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
  string line;
  
  while (getline(cin, line)) {
    if (line.size() == 0) {
      continue;
    }
    
    istringstream iss(line);
    int n, m;
    iss >> n >> m;
    
    // create the adjacency matrix
    vvi G;
    for (int i = 0; i < m; ++i) {
      vi row(m, INF);
      G.push_back(row);
    }
    
    // read input data
    for (int i = 0; i < n; ++i) {
      int si, ei, ci;
      cin >> si >> ei >> ci;
      
      // IMPORTANT: combine all flows from u -> v
      if (G[si - 1][ei - 1] == INF) {
        G[si - 1][ei - 1] = ci;
      } else {
        G[si - 1][ei - 1] += ci;
      }
      
      // default value for back edges
      if (G[ei - 1][si - 1] == INF) {
        G[ei - 1][si - 1] = 0;
      }
    }
    
    // Ford-Fulkerson
    ull max_flow = 0;
    
    while (true) {
      deque<int> s;
      s.push_front(0);
      vi color(m, 0);
      color[0] = 1;
      
      // DFS
      while (!s.empty() && s.front() != m - 1) {
        bool adjacent = false;
        for (int i = 0; i < m; ++i) {
          if (G[s.front()][i] != INF && 
              G[s.front()][i] != 0 &&
              color[i] == 0) {
            adjacent = true;
            color[i] = 1;
            s.push_front(i);
            break;
          }
        }
        
        if (!adjacent) {
          s.pop_front();
        }
      }
      
      // no more flow paths
      if (s.empty()) {
        break;
      }
      
      // there is a flow from the pond to the stream
      if (s.front() == m - 1) {
        ull f = INF;
        for (int i = 0; i < s.size() - 1; ++i) {
          int u = s[i];
          int v = s[i + 1];
          
          if (G[v][u] < f) {
            f = G[v][u];
          }
        }
        
        max_flow += f;
        
        while (s.size() > 1) {
          int u = s.front();
          s.pop_front();
          int v = s.front();
          
          // back edges
          G[v][u] -= f;
          G[u][v] += f;
        }
      }
    }
    
    cout << max_flow << "\n";
  }
  
  return 0;
}
