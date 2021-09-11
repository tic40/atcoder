#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int n;
vector<pair<ll,ll>> p;

ll choose(ll n, ll a) {
  ll x = 1, y = 1;
  for (ll i = 0; i < a; i++) {
    x *= n-i;
    y *= i+1;
  }
  return x / y;
}

void solve() {
  sort(p.begin(), p.end());

  // x軸で平行
  map<pair<ll,ll>, int> xp;
  REP(i,n) {
    for (int j = i+1; j < n; j++) {
      if (p[i].first != p[j].first) break;
      xp[ {p[i].second, p[j].second} ]++;
    }
  }

  ll ans = 0;
  for (auto v: xp) {
    auto mp = v.first;
    ans += choose(v.second, 2);
  }
  cout << ans << endl;
  return;
}

int main() {
  cin >> n;
  p.resize(n);
  REP(i,n) {
    ll x,y;
    cin >> x >> y;
    p[i] = {x,y};
  }

  solve();
  return 0;
}