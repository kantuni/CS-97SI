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
    string s, t;
    iss >> s >> t;
    if (s.size() > t.size()) {
      cout << "No" << "\n";
      continue;
    }
    int i = 0;
    for (int j = 0; j < t.size(); j++) {
      if (s[i] == t[j]) {
        i++;
      }
    }
    if (i == s.size()) {
      cout << "Yes" << "\n";
    } else {
      cout << "No" << "\n";
    }
  }
  return 0;
}
