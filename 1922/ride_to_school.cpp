#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct Rider {
  double v;
  int t0;
};

bool sort_by_set_off(Rider a, Rider b) {
  if (a.t0 == b.t0) {
    return a.v > b.v;
  }
  return a.t0 < b.t0;
}

Rider first;
bool sort_by_catch_up(Rider a, Rider b) {
  double at = (a.v * a.t0) / (a.v - first.v);
  double bt = (b.v * b.t0) / (b.v - first.v);
  return at < bt;
}

int main() {
  while (true) {
    int n;
    cin >> n;
    
    if (n == 0) {
      break;
    }
    
    vector<Rider> riders;
    for (int i = 0; i < n; ++i) {
      int vi, ti;
      cin >> vi >> ti;
      
      if (ti < 0) {
        continue;
      }
      
      Rider r;
      r.v = vi;
      r.t0 = ti;
      riders.push_back(r);
    }
    
    // sort by set off time
    sort(riders.begin(), riders.end(), sort_by_set_off);
    first = riders[0];
    
    // remove riders that will never catch up
    for (int i = 1; i < riders.size(); ++i) {
      bool same_set_off = riders[i].t0 == first.t0;
      bool lesser_speed = riders[i].v <= first.v;
      if (same_set_off || lesser_speed) {
        riders.erase(riders.begin() + i);
        --i;
      }
    }
    
    // remove the first rider
    riders.erase(riders.begin());
    
    // sort by catch up time
    sort(riders.begin(), riders.end(), sort_by_catch_up);
    
    Rider fastest = riders[0];
    double catch_up_time = (fastest.v * fastest.t0) / (fastest.v - first.v);
    double catch_up = catch_up_time * first.v / 3600.0;
    
    if (catch_up < 4.5) {
      double until_finish = (4.5 - catch_up) * 3600 / fastest.v;
      cout << ceil(catch_up_time + until_finish) << "\n";
    } else {
      cout << ceil(4.5 * 3600 / first.v) << "\n";
    }
  }
  
  return 0;
}
