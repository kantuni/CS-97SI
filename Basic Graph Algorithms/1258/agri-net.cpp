#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

struct UnionFind {
  vi parent, rank;
  
  UnionFind(int n) {
    parent.assign(n, 0);
    rank.assign(n, 0);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }
  
  int find(int x) {
    return (x == parent[x]) ? x : parent[x] = find(parent[x]);
  }
  
  bool same(int x, int y) {
    return find(x) == find(y);
  }
  
  void merge(int x, int y) {
    x = find(x); y = find(y);
    if (rank[x] > rank[y]) parent[y] = x;
    else parent[x] = y;
    if (rank[x] == rank[y]) rank[y]++;
  }
};

struct Graph {
  struct Edge {
    int from;
    int to;
    int weight;
    
    bool operator < (Edge e) const {
      return weight < e.weight;
    }
  };
  
  vector<Edge> edges;
  vvi cnn;
  
  Graph(int n) {
    cnn.assign(n, vi());
  }
  
  void addEdge(int s, int t, int w) {
    cnn[s].push_back(edges.size());
    edges.push_back({s, t, w});
  }
  
  int Kruskal() {
    int mstc = 0;
    UnionFind set(cnn.size());
    vector<Edge> all(edges);
    sort(all.begin(), all.end());
    for (int i = 0; i < all.size(); i++) {
      Edge e = all[i];
      if (!set.same(e.from, e.to)) {
        mstc += e.weight;
        set.merge(e.from, e.to);
      }
    }
    return mstc;
  }
};

int main() {
  int N;
  while (cin >> N) {
    Graph G(N);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        int w;
        cin >> w;
        if (i != j) {
          G.addEdge(i, j, w);
        }
      }
    }
    int ans = G.Kruskal();
    cout << ans << endl;
  }
  return 0;
}
