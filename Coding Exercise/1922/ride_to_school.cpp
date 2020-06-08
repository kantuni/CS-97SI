#include <iostream>
#include <cmath>
#include <cfloat>
using namespace std;

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0) {
      break;
    }
    double tmin = DBL_MAX;
    for (int i = 0; i < n; i++) {
      int vi, ti;
      cin >> vi >> ti;
      if (ti < 0) {
        continue;
      }
      double t = ti + (4.5 * 3600) / vi;
      if (t < tmin) {
        tmin = t;
      }
    }
    cout << ceil(tmin) << endl;
  }
  return 0;
}
