#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  double n; cin >> n;

  double ok = 100.0;
  double ng = 0.0;
  while(1) {
    double mid = (ok+ng)/2;
    double cur = mid*(mid*(mid+1)+2)+3;
    if (abs(cur-n) < 0.01) {
      cout << mid << endl;
      return 0;
    }
    if (cur < n) {
      ng = mid;
    } else {
      ok = mid;
    }
  }
  return 0;
}