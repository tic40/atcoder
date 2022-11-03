#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

vector<pair<ll,ll>> prime_factorize(ll n) {
  vector<pair<ll,ll>> res;
  for(ll a = 2; a*a <= n; a++) {
    if (n%a != 0) continue;
    ll ex = 0;
    while(n%a == 0) { ex++; n /= a; }
    res.emplace_back(a,ex);
  }
  if (n != 1) res.emplace_back(n,1);
  return res;
}

int main() {
  ll n; cin >> n;
  auto pf = prime_factorize(n);
  int cnt = 0;
  for(auto [_,x]: pf) cnt += x;

  int ans = 0, i = 1;
  while(i < cnt) { i *= 2; ans++; }
  cout << ans << endl;
  return 0;
}