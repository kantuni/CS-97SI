#include <iostream>
#include <vector>
#include <deque>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define INF 1e9

int main() {
  int N, M;
  cin >> N >> M;
  
  const int L = N + M + 2;
  vvi A;
  for (int i = 0; i < L; ++i) {
    vi row(L, INF);
    A.push_back(row);
  }
  
  // source
  for (int i = 1; i < N + 1; ++i) {
    A[0][i] = 1;
    A[i][0] = 0;
  }
  
  // target
  for (int i = N + 1; i < N + M + 1; ++i) {
    A[i][L - 1] = 1;
    A[L - 1][i] = 0;
  }
  
  for (int i = 1; i < N + 1; ++i) {
    int s;
    cin >> s;
    
    for (int j = 0; j < s; ++j) {
      int sj;
      cin >> sj;
      A[i][N + sj] = 1;
      A[N + sj][i] = 0;
    }
  }
  
  // Ford-Fulkerson
  int max_flow = 0;
  
  while (true) {
    vector<int> color(L, 0);
    deque<int> s;
    s.push_front(0);
    color[0] = 1;
    
    // DFS
    while (!s.empty() && s.front() != L - 1) {
      bool adjacent = false;
      for (int i = 0; i < L; ++i) {
        if (A[s.front()][i] != INF &&
            A[s.front()][i] != 0 &&
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
    
    if (s.empty()) {
      break;
    }
    
    if (s.front() == L - 1) {
      int f = INF;
      for (int i = 0; i < s.size() - 1; ++i) {
        int u = s[i];
        int v = s[i + 1];
        
        if (A[v][u] < f) {
          f = A[v][u];
        }
      }
      
      max_flow += f;
      
      while (s.size() > 1) {
        int u = s.front();
        s.pop_front();
        int v = s.front();
        
        A[v][u] -= f;
        A[u][v] += f;
      }
    }
  }
  
  cout << max_flow << "\n";
  return 0;
}
