#include <iostream>
#include <cmath>
#include <cfloat>
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
    
    // remove riders that have the same set off time (leave one)
    for (int i = 1; i < riders.size(); ++i) {
      if (riders[i - 1].t0 == riders[i].t0) {
        riders.erase(riders.begin() + i);
        --i;
      }
    }
    
    double seconds_so_far = 0.0;
    double km_so_far = 0.0;
    
    Rider prev = riders[0];
    int current = 0;
    
    while (km_so_far < 4.5 * 3600) {
      double tmin = DBL_MAX;
      for (int i = current + 1; i < riders.size(); ++i) {
        double t = (riders[i].v * riders[i].t0 - prev.v * prev.t0) / (riders[i].v - prev.v);
        if (t < tmin) {
          tmin = t;
          current = i;
        }
      }
      
      if (tmin * prev.v > 4.5 * 3600) {
        break;
      }
      
      km_so_far += (tmin - seconds_so_far) * prev.v;
      seconds_so_far = tmin;
      prev = riders[current];
    }
    
    if (km_so_far < 4.5 * 3600) {
      seconds_so_far += (4.5 * 3600 - km_so_far) / prev.v;
    }
    
    cout << ceil(seconds_so_far) << "\n";
  }
  
  return 0;
}
