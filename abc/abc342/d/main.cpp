#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

vector<ll> prime_factorize(ll n) {
  vector<ll> res;
  for(ll a = 2; a*a <= n; a++) {
    if (n%a != 0) continue;
    ll ex = 0;
    while(n%a == 0) { ex++; n /= a; }
    if (ex % 2) res.emplace_back(a);
  }
  if (n != 1) res.emplace_back(n);
  return res;
}

int main() {
  int n; cin >> n;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  map<ll,ll> mp;
  REP(i,n) {
    auto pf = prime_factorize(a[i]);
    ll now = 1;
    for(auto v: pf) now *= v;
    mp[now]++;
  }

  ll ans = 0;
  for(auto [k,v]: mp) {
    if (k == 0) ans += (n-1)*v;
    else ans += (mp[0] + (v-1))*v;
  }
  cout << ans/2 << endl;
  return 0;
}