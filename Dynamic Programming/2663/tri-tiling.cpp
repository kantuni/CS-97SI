#include <iostream>
#include <vector>
using namespace std;

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == -1) {
      break;
    }
    vector<int> D(n + 1);
    D[0] = 1;
    D[1] = 0;
    vector<int> A(n + 1);
    A[0] = 0;
    A[1] = 1;
    for (int i = 2; i < n + 1; i++) {
      A[i] = D[i - 1] + A[i - 2];
      D[i] = D[i - 2] + 2 * A[i - 1];
    }
    cout << D[n] << endl;
  }
  return 0;
}
