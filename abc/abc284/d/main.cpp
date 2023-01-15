#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = unsigned long long;

vector<pair<ll,ll>> prime_factorize(ll n) {
  vector<pair<ll,ll>> res;
  for(ll a = 2; a*a <= n; a++) {
    if (n%a != 0) continue;
    ll ex = 0;
    while(n%a == 0) { ex++; n /= a; }
    res.emplace_back(a,ex);
    break;
  }
  return res;
}

int main() {
  int t; cin >> t;
  REP(i,t) {
    ll n; cin >> n;
    ll p,q;
    auto pf = prime_factorize(n);
    auto [x,y] = pf[0];
    if (y == 2) {
      p = x;
      q = n / p / p;
    } else {
      q = x;
      p = sqrt(n / q);
    }
    cout << p << " " << q << endl;
  }
  return 0;
}