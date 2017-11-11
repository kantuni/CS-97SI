#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define UNVISITED -1
#define VISITED 1
#define INF (int) 1e9

vvi res, cnn;
vi parent, color;
int s, t, f;

// augment along s -> t path
void augment(int v, int minf) {
  if (v == s) { f = minf; return; }
  else if (parent[v] != -1) {
    int u = parent[v];
    augment(parent[v], min(minf, res[u][v]));
    res[u][v] -= f; res[v][u] += f;
  }
}

int main() {
  int N, M; cin >> N >> M;
  int V = N + M + 2;
  
  // keep both adjacency matrix and 
  // adjacency list for O(VE^2) max flow
  s = 0; t = V - 1;
  res.assign(V, vi(V));
  cnn.assign(V, vi());
  
  // super source
  for (int i = 1; i <= N; i++) {
    res[s][i] = 1; cnn[s].push_back(i);
    res[i][s] = 0; cnn[i].push_back(s);
  }
  
  // super sink
  for (int i = N + 1; i <= N + M; i++) {
    res[i][t] = 1; cnn[i].push_back(t);
    res[t][i] = 0; cnn[t].push_back(i);
  }
  
  // in
  for (int i = 1; i <= N; i++) {
    int si; cin >> si;
    for (int j = 0; j < si; j++) {
      int sj; cin >> sj;
      res[i][N + sj] = 1; cnn[i].push_back(N + sj);
      res[N + sj][i] = 0; cnn[N + sj].push_back(i);
    }
  }
  
  // Edmonds-Karp's Algorithm
  int mf = 0;
  while (true) {
    f = 0;
    
    // BFS
    color.assign(V, UNVISITED); color[s] = VISITED;
    parent.assign(V, -1);
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
  cout << mf << "\n";
  return 0;
}
