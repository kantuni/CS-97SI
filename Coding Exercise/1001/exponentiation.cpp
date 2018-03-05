#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

template <typename T>
string to_string(const T& value) {
  stringstream ss;
  ss << value;
  return ss.str();
}

/*
 * Integer arithmetic: addition
 */

string iadd(string a, string b) {
  if (b.size() > a.size()) {
    return iadd(b, a);
  }
  
  int diff = a.size() - b.size();
  string leading_zeros;
  for (int i = 0; i < diff; i++) {
    leading_zeros += "0";
  }
  b = leading_zeros + b;
  
  string result;
  int carry = 0;
  
  for (int i = a.size() - 1; i >= 0; i--) {
    int x = a[i] - '0';
    int y = b[i] - '0';
    int sum = x + y + carry;
    carry = 0;
    
    if (sum > 9 && i != 0) {
      carry = sum / 10;
      sum %= 10;
    }
    
    if (i == 0) {
      string ssum = to_string(sum);
      reverse(ssum.begin(), ssum.end());
      result += ssum;
    } else {
      result += to_string(sum);
    }
  }
  
  reverse(result.begin(), result.end());
  return result;
}


/*
 * Integer arithmetic: multiplication
 */
 
string imul(string a, string b) {
  if (b.size() > a.size()) {
    return imul(b, a);
  }
  
  string result = "0";
  for (int i = b.size() - 1; i >= 0; i--) {
    string temp;
    int carry = 0;
    
    for (int j = a.size() - 1; j >= 0; j--) {
      int x = b[i] - '0';
      int y = a[j] - '0';
      int mult = x * y + carry;
      carry = 0;
      
      if (mult > 9 && j != 0) {
        carry = mult / 10;
        mult %= 10;
      }
      
      if (j == 0) {
        string smult = to_string(mult);
        reverse(smult.begin(), smult.end());
        temp += smult;
      } else {
        temp += to_string(mult);
      }
    }
    reverse(temp.begin(), temp.end());
    for (int k = 0; k < b.size() - 1 - i; k++) {
      temp += "0";
    }
    result = iadd(result, temp);
  }
  
  return result;
}


/*
 * Floating-point arithmetic: multiplication
 */
 
string fmul(string a, string b) {
  string result;
  int separator = 0;
  
  // find the separator and remove it
  for (int i = a.size() - 1; i >= 0; i--) {
    if (a[i] == '.') {
      a = a.substr(0, i) + a.substr(i + 1, a.size());
      break;
    }
    separator++;
  }
  
  // find the separator and remove it
  for (int i = b.size() - 1; i >= 0; i--) {
    if (b[i] == '.') {
      b = b.substr(0, i) + b.substr(i + 1, b.size());
      break;
    }
    separator++;
  }
  
  // ... now just multiply two integers
  result = imul(a, b);
  
  // put the separator in the right place
  if (separator == result.size()) {
    result = "0." + result;
  } else if (separator < result.size()) {
    string temp = result.substr(0, result.size() - separator);
    temp += '.';
    temp += result.substr(result.size() - separator, result.size());
    result = temp;
  }
  
  return result;
}

/*
 * Floating-point arithmetic: power function
 */

string fpow(string x, int y) {
  if (y == 1) {
    return x;
  }
  
  if (y % 2 == 0) {
    return fpow(fmul(x, x), y / 2);
  } else {
    return fmul(x, fpow(x, y - 1));
  }
}


void print(string s) {
  // leading zeros should be suppressed
  int start = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] - '0' != 0) {
      start = i;
      break;
    }
  }
  
  // remove trailing zeroes
  int stop = s.size() - 1;
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] - '0' != 0) {
      stop = i;
      break;
    }
  }
  
  // don't print the decimal point if s is an integer
  if (s[stop] == '.') {
    stop--;
  }
  
  cout << s.substr(start, stop + 1) << "\n";
}

int main() {
  string r;
  int n;
  while (cin >> r >> n) {
    string rn = fpow(r, n);
    print(rn);
  }
  return 0;
}
