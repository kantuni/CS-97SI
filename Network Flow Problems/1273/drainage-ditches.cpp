#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define all(c) (c).begin(), (c).end()
#define UNVISITED -1
#define VISITED 1
#define INF (int) 1e9

vvll res, cnn;
vll parent, color;
ll s, t, f, mf;

// augment along s -> t path
void augment(int v, ll minf) {
  if (v == s) { f = minf; return; }
  else if (parent[v] != -1) {
    int u = parent[v];
    augment(u, min(minf, res[u][v]));
    res[u][v] -= f; res[v][u] += f;
  }
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    s = 0; t = m - 1;
    res.assign(m, vll(m));
    cnn.assign(m, vll());
    
    // in
    for (int i = 0; i < n; i++) {
      int si, ei, ci;
      cin >> si >> ei >> ci;
      
      if (find(all(cnn[si - 1]), ei - 1) == cnn[si - 1].end()) {
        cnn[si - 1].push_back(ei - 1);
        cnn[ei - 1].push_back(si - 1);
      }
      
      // combine all flows from u -> v
      res[si - 1][ei - 1] += ci;
    }
    
    // Edmonds-Karp's Algorithm
    mf = 0;
    while (true) {
      f = 0;
      
      // BFS
      color.assign(m, UNVISITED); color[s] = VISITED;
      parent.assign(m, -1);
      queue<int> q; q.push(s);
      
      while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == t) break;
        for (int i = 0; i < cnn[u].size(); i++) {
          int v = cnn[u][i];
          if (res[u][v] > 0 && color[v] == UNVISITED) {
            color[v] = VISITED;
            parent[v] = u;
            q.push(v);
          }
        }
      }
      
      augment(t, INF);
      if (f == 0) break;
      mf += f;
    }
    
    // out
    cout << mf << endl;
  }
  
  return 0;
}
