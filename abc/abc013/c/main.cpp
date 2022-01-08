#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll n, h;
  cin >> n >> h;
  ll a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  ll ans = c*n;

  for(ll x = 0; x<=n; x++) {
    // h + b*x + d*y -e*n + x*e + y*e > 0
    ll y = (e * n - x * e - b * x - h) / (d + e) + 1;
    if ((e * n - x * e - b * x - h) < 0) y = 0;
    ans = min(ans, a*x+c*y);
  }
  cout << ans << endl;
}