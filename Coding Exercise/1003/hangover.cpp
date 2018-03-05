#include <iostream>
using namespace std;

int main() {
  double c, total;
  int i;

  while (true) {
    cin >> c;

    if (c == 0) {
      break;
    }

    total = 0.5;
    i = 2;
    while (total < c) {
      i++;
      total += 1.0 / i;
    }

    cout << i - 1 << " card(s)" << "\n";
  }
  
  return 0;
}
