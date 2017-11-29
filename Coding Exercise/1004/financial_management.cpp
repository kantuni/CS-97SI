#include <iostream>
using namespace std;

int main() {
  double total = 0, balance;
  int months = 12;
  for (int i = 0; i < months; i++) {
    cin >> balance;
    total += balance;
  }
  cout << "$" << total / months << "\n";
  return 0;
}
