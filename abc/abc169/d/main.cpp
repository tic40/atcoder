#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

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
  ll n; cin >> n;
  auto pf = prime_factorize(n);

  int ans = 0;
  for(auto v: pf) {
    int cnt = v.second;

    for(int i = 1; i <= cnt; i++) {
      cnt -= i;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
