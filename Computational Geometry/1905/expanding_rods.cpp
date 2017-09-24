#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
using namespace std;

#define PI 3.14159265359

int main() {
  string line;
  
  while (getline(cin, line)) {
    if (line.size() == 0) {
      continue;
    }
    
    istringstream iss(line);
    int l, n;
    double c;
    iss >> l >> n >> c;
    
    if (l < 0 && n < 0 && c < 0) {
      break;
    }
    
    double lp = (1 + n * c) * l;
    
    // n * c = 1
    if (lp == 2 * l) {
      cout << fixed << setprecision(3);
      cout << l / 2.0 << "\n";
      continue;
    }
    
    // n * c = 0
    if (lp == l) {
      cout << fixed << setprecision(3);
      cout << 0.0 << "\n";
      continue;
    }
    
    double start = 0, end = 90;
    double angle, radians = 0;
    
    while (true) {
      angle = (start + end) / 2;
      radians = angle * (PI / 180);
      
      // triangle + arc length formula
      double expression = radians * l / sin(radians);
      
      if (abs(lp - expression) < 0.0000001) {
        break;
      }
      
      if (lp > expression) {
        start = angle;
      } else {
        end = angle;
      }
    }
    
    double r = l / (2 * sin(radians));
    double h = r * (1 - cos(radians));
    
    cout << fixed << setprecision(3);
    cout << h << "\n";
  }
  
  return 0;
}
