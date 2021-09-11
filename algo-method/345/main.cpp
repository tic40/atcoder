#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

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

int main() {
  ll a,b;
  cin >> a >> b;

  auto d = divisor(a-b);
  int ans = 0;
  for(ll v: d) if (b < v) ans++;
  cout << ans << endl;

  return 0;
}