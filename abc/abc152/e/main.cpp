#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
using mint = modint1000000007;

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

int main() {
  int n; cin >> n;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  map<ll,ll> mp;
  REP(i,n) {
    auto pf = prime_factorize(a[i]);
    for(auto [x,y]: pf) mp[x] = max(mp[x],y);
  }

  mint l = 1; // lcm
  for(auto [k,v]: mp) l *= (ll)pow(k,v);

  mint ans = 0;
  REP(i,n) ans += l / a[i];
  cout << ans.val() << endl;
  return 0;
}