#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

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
  ll k; cin >> k;
  auto d = divisor(k);
  ll ans = 0;
  for(auto a: d) for(auto b: d) {
    if ((k/a) % b == 0) {
      ll c = (k / a) / b;
      if (a <= b && b <= c) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}