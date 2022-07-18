#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

vector<ll> divisor(ll n) {
  vector<ll> res;
  for(ll i = 1; i*i <= n; i++) {
    if (n%i == 0) {
      res.push_back(i);
      if (n/i != i) res.push_back(n/i);
    }
  }
  return res;
}

int main() {
  ll k; cin >> k;
  auto d = divisor(k);
  int n = d.size();

  int ans = 0;
  REP(i,n) for(int j = i; j < n; j++) {
    ll a = d[i];
    ll b = d[j];
    ll c = k / a / b;
    if (a*b*c == k && a <= b && b <= c) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}