#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int t; cin >> t;
  auto f = [&](int a, int b, int c, int k) {
    a -= k; c -= k;
    if (a < 0 || c < 0) return false;
    return a + b + c >= k;
  };

  REP(_,t) {
    int a,b,c; cin >> a >> b >> c;
    int ok = 0, ng = 1e9+1;
    while (ng-ok>1) {
      int mid = (ok+ng)/2;
      f(a,b,c,mid) ? ok = mid : ng = mid;
    }
    cout << ok << endl;
  }
  return 0;
}