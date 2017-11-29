#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
  string line;
  while (getline(cin, line)) {
    if (line.size() == 0) {
      continue;
    }
    
    istringstream iss(line);
    unsigned long long m;
    iss >> m;
    
    unsigned long long nimsum = 0;
    for (int i = 0; i < m; i++) {
      unsigned long long temp;
      iss >> temp;
      nimsum ^= temp;
    }
    
    if (nimsum == 0) {
      cout << "No" << "\n";
    } else {
      cout << "Yes" << "\n";
    }
  }
  return 0;
}
