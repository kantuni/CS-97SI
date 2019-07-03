#include <iostream>
using namespace std;

int main() {
  while (true) {
    double c;
    cin >> c;
    if (c == 0) {
      break;
    }
    double total = 0.5;
    int i = 2;
    while (total < c) {
      i++;
      total += 1.0 / i;
    }
    cout << i - 1 << " card(s)" << endl;
  }
  return 0;
}
