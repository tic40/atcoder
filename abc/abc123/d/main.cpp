#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();

int main() {
  int x,y,z,k; cin >> x >> y >> z >> k;
  vector<ll> a(x),b(y),c(z);
  REP(i,x) cin >> a[i];
  REP(i,y) cin >> b[i];
  REP(i,z) cin >> c[i];
  vector<ll> ab;
  REP(i,x) REP(j,y) ab.push_back(a[i]+b[j]);
  sort(ab.begin(),ab.end());
  sort(c.begin(),c.end());

  // a+b+c >= x となる組み合わせが k 個以下であるか
  auto f = [&](ll x) {
    ll cnt = 0;
    for(auto v: c) {
      auto id = lower_bound(ab.begin(),ab.end(),x-v) - ab.begin();
      cnt += ab.size() - id;
      if (k <= cnt) return true;
    }
    return false;
  };

  // k 番目の値を二分探索で求める
  ll ok = 0, ng = 1e12;
  while(ng-ok>1) {
    ll mid = (ok+ng)/2;
    if (f(mid)) ok = mid;
    else ng = mid;
  }

  vector<ll> ans;
  reverse(ab.begin(),ab.end());
  reverse(c.begin(),c.end());
  for(auto v: ab) for(auto w: c) {
    if (ok >= v+w) break;
    ans.push_back(v+w);
  }
  sort(ans.rbegin(),ans.rend());
  while((int)ans.size() < k) ans.push_back(ok);
  REP(i,k) cout << ans[i] << endl;
  return 0;
}