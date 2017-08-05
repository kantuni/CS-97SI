#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vc> vvc;

vvc transpose(vvc matrix, int row, int col) {
  vvc matrixT;
  for (int i = 0; i < col; ++i) {
    vc temp(row, ' ');
    for (int j = 0; j < row; ++j) {
      temp[j] = matrix[j][i];
    }
    matrixT.push_back(temp);
  }
  return matrixT;
}

int main() {
  vi letters(26, 0);
  string line;
  
  while (getline(cin, line)) {
    for (int i = 0; i < line.length(); ++i) {
      int index = line[i] - 'A';
      // only uppercase letters
      if (index >= 0 && index <= 25) {
        ++letters[index];
      }
    }
  }
  
  int max = *max_element(letters.begin(), letters.end());
  vvc histogram;
  for (int i = 0; i < 26; ++i) {
    vc letter(max, ' ');
    for (int j = 0; j < letters[i]; ++j) {
      letter[max - j - 1] = '*';
    }
    histogram.push_back(letter);
  }
  
  vvc histogramT = transpose(histogram, 26, max);
  for (int i = 0; i < histogramT.size(); ++i) {
    for (int j = 0; j < histogramT[i].size(); ++j) {
      cout << histogramT[i][j] << " ";
    }
    cout << "\n";
  }
  
  for (int i = 0; i < 26; ++i) {
    cout << (char) ('A' + i) << " ";
  }
  cout << "\n";
  
  return 0;
}
