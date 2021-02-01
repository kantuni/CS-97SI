#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

template <typename T>
string to_string(T n) {
  ostringstream oss;
  oss << n;
  return oss.str();
}

// coords are in lexicographical order
const int coords[8][2] = {
  {-1, -2}, {1, -2}, {-2, -1}, {2, -1},
  {-2, 1}, {2, 1}, {-1, 2}, {1, 2}
};

vvi B;
int p, q, counter;
string answer;

void DFS(int i, int j) {
  B[i][j] = 1;
  char letter = (char) ('A' + j);
  string number = to_string(i + 1);
  answer += letter + number;
  
  // check in lexicographical order
  for (int k = 0; k < 8; k++) {
    int x = i + coords[k][0];
    int y = j + coords[k][1];
    bool ok = x >= 0 && x < p && y >= 0 && y < q;
    
    if (ok && B[x][y] == 0) {
      counter++;
      DFS(x, y);
    }
  }
  
  // backtracking
  if (counter != p * q) {
    B[i][j] = 0;
    counter--;
    answer.resize(answer.size() - number.size() - 1);
  }
}

int main() {
  int T;
  cin >> T;
  
  for (int t = 1; t <= T; t++) {
    cin >> p >> q;
    
    // reset
    B.clear();
    B.resize(p, vi(q, 0));
    answer = "";
    counter = 1;
    
    DFS(0, 0);
    
    cout << "Scenario #" << t << ":" << "\n";
    if (counter != p * q) {
      cout << "impossible\n";
    } else {
      cout << answer << "\n";
    }
  }

  return 0;
}
