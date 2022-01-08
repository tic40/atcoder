#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

vector<ll> convert_base(ll n, ll base=2) {
  vector<ll> a;
  while(n) {
    ll m = abs(n%base);
    a.push_back(m);
    if (base < 0 && m) n--;
    n /= base;
  }
  reverse(a.begin(), a.end());
  return a;
}

int main() {
  ll k; cin >> k;
  vector<ll> r = convert_base(k);
  for(auto v: r) cout << (v == 1 ? 2 : 0);
  cout << endl;

  return 0;
}