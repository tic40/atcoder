#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; ll k;
  cin >> n >> k;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  // x周したときに食べるりんごの個数はK個以下か？を二分探索する
  ll ok = 0, ng = 1e13;
  while(ng-ok > 1) {
    ll mid = (ok+ng)/2;
    ll tot = 0;
    REP(i,n) tot += min(a[i],mid);
    if (tot <= k) ok = mid;
    else ng = mid;
  }

  REP(i,n) {
    ll sub = min(a[i], ok);
    a[i] -= sub;
    k -= sub;
  }

  REP(i,n) {
    if (k == 0) break;
    if (a[i] > 0) { a[i]--; k--; }
  }

  REP(i,n) cout << a[i] << " ";
  return 0;
}