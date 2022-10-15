#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  ll x; int k;
  cin >> x >> k;

  ll m = 1, m10 = 10;
  REP(i,k) {
    ll v = x % (m10) / m;
    x /= m10;
    if (v >= 5) x += 1;
    x *= m10;
    m *= 10;
    m10 *= 10;
  }

  cout << x << endl;
  return 0;
}