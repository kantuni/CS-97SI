#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define INF (int) 1e9

struct Graph {
  struct Edge {
    int from;
    int to;
    int weight;
    
    bool operator < (Edge e) const {
      // hack: invert sign
      return weight > e.weight;
    }
  };
  
  vector<Edge> edges;
  vvi cnn;
  
  // Dijkstra
  vi dist;
  
  Graph(int n) {
    cnn.assign(n, vi());
    dist.assign(n, INF);
  }
  
  void addEdge(int s, int t, int w) {
    cnn[s].push_back(edges.size());
    edges.push_back({s, t, w});
  }
  
  void Dijkstra(int s) {
    priority_queue<Edge> pq;
    dist[s] = 0;
    pq.push({s, s, 0});
    
    while (!pq.empty()) {
      Edge top = pq.top(); pq.pop();
      int u = top.to;
      int d = top.weight;
      
      if (d > dist[u]) continue;
      for (int j = 0; j < cnn[u].size(); j++) {
        int ie = cnn[u][j];
        int v = edges[ie].to;
        int w = edges[ie].weight;
        if (dist[v] > dist[u] + w) {
          dist[v] = dist[u] + w;
          pq.push({u, v, dist[v]});
        }
      }
    }
  }
};

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  a--; b--;
  
  Graph G(n);
  for (int i = 0; i < n; i++) {
    int ki;
    cin >> ki;
    for (int j = 0; j < ki; j++) {
      int t;
      cin >> t;
      t--;
      
      if (j == 0) {
        G.addEdge(i, t, 0);
      } else {
        G.addEdge(i, t, 1);
      }
    }
  }
  
  G.Dijkstra(a);
  if (G.dist[b] == INF) {
    cout << -1 << "\n";
  } else {
    cout << G.dist[b] << "\n";
  }
  
  return 0;
}
