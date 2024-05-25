#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll a,b,c,d; cin >> a >> b >> c >> d;
  // 下駄で負の数をなくす
  a += 1e9; b += 1e9;
  c += 1e9; d += 1e9;

  auto f = [&](ll a, ll b) {
    ll ra = a % 4; a -= ra;
    ll rb = b % 2; b -= rb;
    ll res = a * b;
    if (rb) res += a;
    if (ra >= 1) {
      res += b * 3 / 2;
      if (rb) res += 2;
    }
    if (ra >= 2) {
      res += b * 3 / 2;
      if (rb) res += 1;
    }
    if (ra >= 3) res += b/2;
    return res;
  };

  ll ans = f(c,d) - f(a,d) - f(c,b) + f(a,b);
  cout << ans << endl;
  return 0;
}