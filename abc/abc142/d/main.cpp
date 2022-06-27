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
  ll a,b; cin >> a >> b;
  auto pf = prime_factorize(gcd(a,b));

  // gcd(a,b)を素因数分解して、その数に1の分を足した値が答え
  cout << pf.size()+1 << endl;
  return 0;
}
