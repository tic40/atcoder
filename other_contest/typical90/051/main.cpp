#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,k; ll p;
  cin >> n >> k >> p;
  vector<ll> a,b;
  REP(i,n) {
    ll v; cin >> v;
    i%2 ? a.push_back(v) : b.push_back(v);
  }

  auto f = [&](vector<ll> x) {
    vector g(k+1,vector<ll>());
    int sz = x.size();
    REP(bit,1<<sz) {
      int popcnt = __builtin_popcount(bit);
      if (popcnt > k) continue;

      ll now = 0;
      REP(i,sz) if (bit >> i & 1) now += x[i];
      if (now <= p) g[popcnt].push_back(now);
    }
    for(auto &v: g) sort(v.begin(),v.end());
    return g;
  };

  auto ga = f(a);
  auto gb = f(b);
  ll ans = 0;
  REP(i,k+1) for(auto v: ga[i]) {
    auto& t = gb[k-i];
    auto it = upper_bound(t.begin(), t.end(),p-v);
    ans += it - t.begin(); // p-v 以下の数を答えに足す。index なのでこれでよい
  }
  cout << ans << endl;
  return 0;
}