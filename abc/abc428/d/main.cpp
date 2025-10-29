#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

// 二分探索で、 r 以下の平方数の数を求める = sqrt(r)
ll s(ll r) {
  ll ok = 0, ng = 2e9;
  while(ng-ok > 1) {
    ll mid = (ok+ng)/2;
    if (mid * mid <= r) ok = mid;
    else ng = mid;
  }
  return ok;
}
// f(c,r) を求める
ll g(ll c, ll r) {
  ll res = 0;
  for (ll l = 1;; l *= 10) { // 桁毎に見る
    ll base = c*l*10;
    ll nl = base + l;
    ll nr = min(base+r, base + (l*10-1));
    if (nr < nl) break;
    res += s(nr) - s(nl-1);
  }
  return res;
}

int main() {
  int t; cin >> t;
  REP(_,t) {
    ll c,d; cin >> c >> d;
    // f(c,c+x) = f(c,c+d) - f(c,c)
    ll ans = g(c,c+d) - g(c,c);
    cout << ans << endl;
  }
  return 0;
}