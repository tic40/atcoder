#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  double n,m;
  cin >> n >> m;

  double ng = 0, ok = 10000;
  while (abs(ok-ng) > 1e-4) {
    double mid = (ok+ng)/2;
    double cur = n+1;
    REP(i,5) {
      cur*=mid;
      cur+=1.0;
    }
    if (m <= cur) ok = mid;
    else ng = mid;
  }

  cout << ok << endl;
  return 0;
}