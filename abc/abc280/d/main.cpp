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

ll f(ll n, ll x) {
  if (n == 0) return 0;
  return n/x + f(n/x,x);
}

int main() {
  ll k; cin >> k;

  auto pf = prime_factorize(k);

  ll ok = k, ng = 0;
  while(ok-ng>1) {
    ll mid = (ok+ng)/2;
    bool possible = true;
    for(auto v: pf) {
      if (v.second > f(mid,v.first)) possible = false;
    }

    if (possible) ok = mid;
    else ng = mid;
  }

  cout << ok << endl;
  return 0;
}