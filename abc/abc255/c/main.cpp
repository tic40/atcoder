#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  ll x,a,d,n; cin >> x >> a >> d >> n;

  x -= a;
  ll left, right;
  if (0 < d) {
    left = 0;
    right = d*(n-1);
  } else {
    left = d*(n-1);
    right = 0;
  }

  ll ans = min(abs(x-left), abs(x-right));
  if (d != 0 && left <= x && x <= right) {
    ll m = abs(x) % abs(d);
    ans = min(ans, m);
    ans = min(ans, abs(d) - m);
  }

  cout << ans << endl;
  return 0;
}