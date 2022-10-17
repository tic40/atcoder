#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,k; ll p;
  cin >> n >> k >> p;
  vector<ll> a,b;
  REP(i,n) {
    ll x; cin >> x;
    if (i%2 == 0) a.push_back(x);
    else b.push_back(x);
  }

  auto f = [&](vector<vector<ll>> &g, vector<ll> x) {
    int sz = x.size();
    REP(bit, 1 << sz) {
      ll now = 0;
      int popcnt = 0;
      REP(i,sz) {
        if (bit >> i & 1) { now += x[i]; popcnt++; }
      }
      if (popcnt <= k) g[popcnt].push_back(now);
    }
    for(auto &v: g) sort(v.begin(),v.end());
  };

  vector<vector<ll>> ga(k+1), gb(k+1);
  f(ga,a);
  f(gb,b);

  ll ans = 0;
  REP(i,k+1) for(auto v: ga[i]) {
    auto it = upper_bound(gb[k-i].begin(), gb[k-i].end(), p-v);
    int idx = it - gb[k-i].begin();
    ans += idx;
  }
  cout << ans << endl;
  return 0;
}