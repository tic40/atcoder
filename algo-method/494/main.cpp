#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

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

int mobius(ll n) {
  if (n == 1) return 1;

  auto p = prime_factorize(n);
  for (auto v: p) {
    if (2 <= v.second) return 0;
  }
  return p.size() % 2 == 0 ? 1 : -1;
}

int main() {
  ll n; cin >> n;
  cout << mobius(n) << endl;
  return 0;
}