#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

ll f(ll a,ll b) { return a*a*a + a*a*b + a*b*b + b*b*b; }
int main() {
  ll n; cin >> n;
  ll ans = 9e18;

  ll a = 0, b = 1e6;
  while(a <= b) {
    ll now = f(a,b);
    if (n <= now) {
      ans = min(ans, now);
      b--;
    } else {
      a++;
    }
  }

  cout << ans << endl;
  return 0;
}