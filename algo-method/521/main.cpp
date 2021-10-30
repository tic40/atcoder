#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

int main() {
  ll n,m; cin >> n >> m;

  /*
    a0 + a1 + a2...+an = M
    gcd(a0,a1,a2,...an) = x < これが何通りあるか
    gcd(a0,a1,a2,...an) = G と置く
    G は Mの約数である
  */
  vector<ll> d;
  for(int i = 1; i*i <= m; i++) {
    if (m%i==0) {
      d.push_back(i);
      if (m/i != i) d.push_back(m/i);
    }
  }

  int ans = 0;
  for (ll v: d) if (v*n <= m) ans++;

  cout << ans << endl;
  return 0;
}