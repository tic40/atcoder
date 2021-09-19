#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main() {
  int n; cin >> n;
  REP(i,n) {
    ll x; cin >> x;
    ll ok = min((ll)1e10,x), ng = 0;
    while(abs(ok-ng) > 1) {
      ll mid = (ok+ng)/2;
      ll cur = (1+mid)*mid/2;
      if (x <= cur) ok = mid;
      else ng = mid;
    }
    cout << ok << endl;
  }
  return 0;
}