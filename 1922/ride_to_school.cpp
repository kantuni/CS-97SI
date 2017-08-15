#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Rider {
  double v, t0;
};

Rider first;

bool sort_by_time(const Rider &a, const Rider &b) {
  if (a.t0 == b.t0) {
    return a.v > b.v;
  }
  return a.t0 < b.t0;
}

bool sort_by_overtakes(const Rider &a, const Rider &b) {
  // TODO: handle denominator = 0 case
  double t1 = (a.v * a.t0) / (a.v - first.v);
  double t2 = (b.v * b.t0) / (b.v - first.v);
  return t1 < t2;
}

int main() {
  while (true) {
    int n;
    cin >> n;
    
    if (n == 0) {
      break;
    }
    
    vector<Rider> info;
    for (int i = 0; i < n; ++i) {
      Rider temp;
      cin >> temp.v >> temp.t0;
      
      if (temp.t0 >= 0) {
        temp.v = (temp.v * 1000) / 3600;
        info.push_back(temp);
      }
    }
    
    // sort by set off time
    sort(info.begin(), info.end(), sort_by_time);
    
    // find the first rider
    first = info[0];
    
    // remove riders with 0 set off time
    for (int i = 0; i < info.size(); ++i) {
      if (info[i].t0 == 0) {
        info.erase(info.begin() + i);
      }
    }
    
    // sort by overtakes
    sort(info.begin(), info.end(), sort_by_overtakes);
    
    for (int i = 0; i < info.size(); ++i) {
      cout << info[i].v << ", " << info[i].t0 << "\n";
    }
  }
  
  return 0;
}
