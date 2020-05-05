#include <iostream>
#include <iomanip>
#include <string>
#include <map>
using namespace std;

int main() {
  map<string, int> trees;
  string name;
  int count = 0;
  
  while (getline(cin, name)) {
    if (trees.find(name) == trees.end()) {
      trees.insert(pair<string, int>(name, 1));
    } else {
      trees.find(name)->second += 1;
    }
    count++;
  }
  
  map<string, int>::iterator it;
  for (it = trees.begin(); it != trees.end(); it++) {
    cout << it->first << " ";
    cout << fixed << setprecision(4);
    cout << 100.0 * it->second / count << "\n";
  }
  
  return 0;
}
