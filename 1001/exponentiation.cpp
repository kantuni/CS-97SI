#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

string iadd(string a, string b) {
  if (b.size() > a.size()) {
    return iadd(b, a);
  }
  
  int diff = a.size() - b.size();
  string leading_zeros;
  for (int i = 0; i < diff; ++i) {
    leading_zeros += "0";
  }
  b = leading_zeros + b;
  
  string result;
  int carry = 0;
  
  for (int i = a.size() - 1; i >= 0; --i) {
    int x = a[i] - '0';
    int y = b[i] - '0';
    int sum = x + y + carry;
    
    if (sum > 10 && i != 1) {
      carry = 1;
      sum %= 10;
    }
    
    result += to_string(sum);
  }
  
  reverse(result.begin(), result.end());
  return result;
}

string imul(string a, string b) {
  if (b.size() > a.size()) {
    return imul(b, a);
  }
  
  string result = "0";
  for (int i = b.size() - 1; i >= 0; --i) {
    string temp = "0";
    for (int j = a.size() - 1; j >= 0; --j) {
      int x = b[i] - '0';
      int y = a[j] - '0';
      int mult = x * y + carry;
      // TODO: continue here
      
    }
  }
}

string fmul(string a, string b) {
  string result;
  int separator = 0;
  
  // find the place for the separator, and remove .s
  for (int i = a.size() - 1; i >= 0; --i) {
    if (a[i] == '.') {
      a = a.substr(0, i) + a.substr(i + 1, a.size());
      break;
    }
    ++separator;
  }
  
  for (int i = b.size() - 1; i >= 0; --i) {
    if (b[i] == '.') {
      b = b.substr(0, i) + b.substr(i + 1, b.size());
      break;
    }
    ++separator;
  }
  
  // TODO: 0.05 case (remove leading zeroes)
  
  // ... now just multiply two integers
  result = imul(a, b);
  
  // put the separator in the right place
  if (separator > result.size()) {
    result = "0." + result;
  } else {
    string temp = result.substr(0, result.size() - separator);
    temp += '.';
    temp += result.substr(result.size() - separator, result.size());
    result = temp;
  }
  
  return result;
}

string fpow(string x, int y) {
  string xy = x;
  for (int i = 1; i < y; ++i) {
    xy = fmul(xy, x);
  }
  return xy;
}

void print(string s) {
  // leading zeros should be suppressed
  int start = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] - '0' != 0) {
      start = i;
      break;
    }
  }
  
  // remove trailing zeroes
  int stop = s.size() - 1;
  for (int i = s.size() - 1; i >= 0; --i) {
    if (s[i] - '0' != 0) {
      stop = i;
      break;
    }
  }
  
  // don't print the decimal point if s is an integer
  if (s[stop] == '.') {
    --stop;
  }
  
  cout << s.substr(start, stop + 1) << "\n";
}

int main() {
  string r;
  int n;
  
  cout << imul("412", "86") << "\n";
  
  /*
  while (cin >> r >> n) {
    string rn = fpow(r, n);
    print(rn);
  }
  */
  
  return 0;
}
