#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

ll n,p;

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

ll solve() {
  auto pf = prime_factorize(p);
  ll ans = 1;
  for(auto v: pf) {
    REP(j, v.second/n) ans *= v.first;
  }
  return ans;
}

int main() {
  cin >> n >> p;
  cout << solve() << endl;
  return 0;
}