#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
  int N;
  cin >> N;
  
  vvi F;
  for (int i = 0; i < N; i++) {
    vi row(N);
    F.push_back(row);
  }
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      char c;
      cin >> c;
      if (c == 'J') F[i][j] = 1;
      else if (c == 'B') F[i][j] = -1;
      else F[i][j] = 0;
    }
  }
  
  int max = 0;
  
  // normal
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N - 1; j++) {
      int A = F[i][j];
      for (int k = j + 1; k < N; k++) {
        if (i + k - j < N) {
          int B = F[i][k];
          int C = F[i + k - j][j];
          int D = F[i + k - j][k];
          
          // none or only one *
          if (A + B + C + D >= 3) {
            int area = (k - j) * (k - j);
            max = area > max ? area : max;
          }
        } 
      }
    }
  }
  
  // diagonal
  for (int i = 0; i < N - 1; i++) {
    for (int j = 1; j < N - 1; j++) {
      int A = F[i][j];
      for (int k = 1; k <= (N - 1) / 2; k++) {
        bool ok = (i + k < N) && (i + 2 * k < N);
        ok = ok && (j - k >= 0) && (j + k < N);

        if (ok) {
          // F[i + k][j] is a center
          int B = F[i + k][j - k];
          int C = F[i + k][j + k];
          int D = F[i + 2 * k][j];
          
          // none or only one *
          if (A + B + C + D >= 3) {
            int area = 2 * k * k;
            max = area > max ? area : max;
          }
        }
      }
    }
  }
  
  cout << max << "\n";
  return 0;
}
