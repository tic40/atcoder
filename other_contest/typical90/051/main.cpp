#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,k; ll p;
  cin >> n >> k >> p;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  auto f = [&](vector<vector<ll>> &g, int sz, int base) {
    REP(bit, 1 << sz) {
      ll now = 0;
      int popcnt = 0;
      REP(i,sz) {
        if (bit >> i & 1) { now += a[i+base]; popcnt++; }
      }
      g[popcnt].push_back(now);
    }
    for(auto &v: g) sort(v.begin(),v.end());
  };

  vector<vector<ll>> ga(n+1), gb(n+1);
  f(ga,n/2,0);
  f(gb,n-n/2,n/2);

  ll ans = 0;
  REP(i,k+1) for(auto v: ga[i]) {
    auto it = lower_bound(gb[k-i].begin(), gb[k-i].end(), p-v+1);
    int idx = it - gb[k-i].begin();
    ans += idx;
  }
  cout << ans << endl;
  return 0;
}