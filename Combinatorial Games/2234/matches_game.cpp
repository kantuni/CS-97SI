#include <iostream>
#include <string>
#include <sstream>
using namespace std;

typedef unsigned long long ull;

int main() {
  string line;
  
  while (getline(cin, line)) {
    if (line.size() == 0) {
      continue;
    }
    
    istringstream iss(line);
    ull m;
    iss >> m;
    
    ull nimsum = 0;
    for (int i = 0; i < m; ++i) {
      ull temp;
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
