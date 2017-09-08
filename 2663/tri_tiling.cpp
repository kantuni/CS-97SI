#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main() {
  while (true) {
    int n;
    cin >> n;
    
    if (n == -1) {
      break;
    }
    
    vi D(n + 1);
    D[0] = 1;
    D[1] = 0;
    D[2] = 3;
    
    vi A(n + 1);
    A[0] = A[1] = A[2] = 0;
    
    vi C(n + 1);
    C[0] = C[1] = 0;
    C[2] = 1;
    
    for (int i = 3; i < n + 1; ++i) {
      A[i] = 3 * A[i - 2] + D[i - 1] + 2 * C[i - 1];
      C[i] = 3 * C[i - 2] + D[i - 2] + A[i - 1];
      D[i] = D[i - 2] + 2 * A[i - 1] + 2 * C[i];
      cout << A[i] << "\t" << C[i] << "\t" << D[i] << "\n";
    }
  }
  
  return 0;
}
