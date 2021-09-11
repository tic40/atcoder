#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

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
  ll n; cin >> n;
  auto d = divisor(n);
  ll tot = 0;
  for (ll v: d) {
    tot += v;
  }
  cout << (tot == n+n ? "Yes" : "No") << endl;
  return 0;
}