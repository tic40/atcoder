#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

vector<ll> divisor(ll x) {
  vector<ll> res;
  for(ll i = 1; i*i <= x; i++) {
    if (x % i == 0) {
      res.push_back(i);
      if (x / i != i) res.push_back(x/i);
    }
  }
  return res;
}

int main() {
  ll n; cin >> n;

  // (a+b) * (b-a+1) / 2 = n
  // (a+b) * (b-a+1) = 2*n
  // a+b, b-a+1 は 2nの約数

  int ans = 0;
  auto d = divisor(n*2);
  for(auto x: d) {
    ll y = 2 * n / x;
    // a+b = x
    // a = x - b
    // a = x - y - a + 1
    // 2a = x - y + 1
    // a = (x-y+1)/2

    // b-a+1 = y
    // b = y+a-1
    // b = y + x - b - 1
    // b = (x+y-1)/2
    if (x % 2 == y % 2) continue;
    ans++;
  }

  cout << ans << endl;
  return 0;
}