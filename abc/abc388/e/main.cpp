#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  // x 個の鏡餅を作れるか？
  auto f = [&](int x) -> bool {
    int ri = 0;
    REP(i,x) {
      auto it = lower_bound(a.begin()+ri,a.end(),a[i]*2);
      if (it == a.end()) return false;
      ri = it-a.begin()+1;
    }
    return true;
  };

  int ok = 0, ng = n/2+1;
  while(ng-ok>1) {
    int mid = (ok+ng)/2;
    if (f(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
  return 0;
}