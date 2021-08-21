#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

ll n,m;
set<ll> a;
vector<int> num(100001);

vector<pair<ll, ll>> prime_factorize(ll n) {
  vector<pair<ll,ll>> res;
  for (ll a = 2; a * a <= n; a++) {
    if (n % a != 0) continue;
    ll ex = 0;
    while (n % a == 0) { ++ex; n /= a; }
    res.push_back({a, ex});
  }
  if (n != 1) res.push_back({n, 1});
  return res;
}


void solve() {
  set<ll> pfact;
  for(ll v: a) {
    auto pf = prime_factorize(v);
    for(auto p: pf) pfact.insert(p.first);
  }

  for (auto v: pfact) {
    if (num[v] == 1) continue;
    for(int i = v; i <= m; i+=v) num[i] = 1;
  }

  vector<int> ans;
  for(int i = 1; i <= m; i++) {
    if (num[i] == 0) ans.push_back(i);
  }

  cout << ans.size() << endl;
  for (int res: ans) cout << res << endl;
  return;
}

int main() {
  cin >> n >> m;
  REP(i,n) {
    ll _; cin >> _;
    a.insert(_);
  }

  solve();
  return 0;
}