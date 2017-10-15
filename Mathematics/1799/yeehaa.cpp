#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define PI 3.14159265359

int main() {
  int N;
  cin >> N;
  
  for (int i = 1; i <= N; i++) {
    double R;
    int n;
    cin >> R >> n;
    
    if (n == 2) {
      cout << "Scenario #" << i << ":" << "\n";
      cout << fixed << setprecision(3);
      cout << R / 2.0 << "\n\n";
      continue;
    }
    
    double a = 360.0 / n;
    double b = (180.0 - a) / 2;
    
    double r = R / (2 * sin(b * PI / 180) / sin(a * PI / 180) + 1);
    cout << "Scenario #" << i << ":" << "\n";
    cout << fixed << setprecision(3);
    cout << r << "\n\n";
  }
  
  return 0;
}
