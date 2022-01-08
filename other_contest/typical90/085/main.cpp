#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

vector<ll> divisor(ll n) {
  vector<ll> vec;
  for(ll i = 1; i*i < n; i++) {
    if (n % i == 0) {
      vec.push_back(i);
      if (i != n / i) vec.push_back(n / i);
    }
  }
  return vec;
}

int main() {
  ll k; cin >> k;
  vector<ll> d = divisor(k);
  int n = d.size();

  ll ans = 0;
  REP(i, d.size()) {
    for(int j = i; j < d.size(); j++) {
      ll a = d[i], b = d[j], c = 0;
      if (k / a < b) continue;
      if (k % (a*b) != 0) continue;
      c = k / (a * b);
      if (b <= c) ans++;
    }
  }

  cout << ans << endl;
  return 0;
}