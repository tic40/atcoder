#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

bool is_prime(ll N) {
  if (N == 1) return false;
  for (ll i = 2; i * i <= N; ++i) {
    if (N % i == 0) return false;
  }
  return true;
}

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
  if (is_prime(n)) {
    cout << 0 << endl;
    return 0;
  }

  auto pf = prime_factorize(n);
  int cnt = 0;
  for(auto v: pf) cnt += v.second;
  int ans = 0;
  int i = 1;
  while(i < cnt) {
    i *= 2;
    ans++;
  }
  cout << ans << endl;

  return 0;
}