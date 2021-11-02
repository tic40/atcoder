#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

vector<ll> divisor(ll n) {
  vector<ll> vec;
  for(ll i = 1; i*i <= n; i++) {
    if (n % i == 0) {
      vec.push_back(i);
      if (i != n / i) vec.push_back(n / i);
    }
  }
  return vec;
}

ll gcd(ll a, ll b) {
  return b ? gcd(b, a%b) : a;
}

int main() {
  ll g,m;
  cin >> g >> m;
  if (m%g != 0) {
    cout << -1 << endl;
    return 0;
  }

  ll ab = m/g;
  auto d = divisor(ab);

  ll ans = LINF;
  for(auto a: d) {
    ll b = ab/a;
    if (gcd(a,b) != 1) continue;
    ans = min( ans, (a+b)*g );
  }

  cout << ans << endl;
  return 0;
}