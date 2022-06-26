#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;
const ll LINF = 1e18+5;

vector<ll> divisor(ll n) {
  vector<ll> res;
  for(ll i = 1; i*i <= n; i++) {
    if (n % i == 0) {
      res.push_back(i);
      if (i != n/i) res.push_back(n/i);
    }
  }
  return res;
}

int main() {
  ll n; cin >> n;

  auto d = divisor(n);
  ll ans = LINF;
  for(ll v: d) {
    ll now = v-1 + (n/v-1);
    ans = min(ans,now);
  }
  cout << ans << endl;
  return 0;
}