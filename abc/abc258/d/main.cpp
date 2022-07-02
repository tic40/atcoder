#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;
const ll LINF = numeric_limits<ll>::max();

int main() {
  ll n, x; cin >> n >> x;
  vector<ll> a(n),b(n);
  REP(i,n) cin >> a[i] >> b[i];

  ll ans = LINF, tot = 0;
  REP(i,min(x,n)) {
    tot += a[i] + b[i];
    ans = min(ans, tot + b[i] * (x-i-1));
  }

  cout << ans << endl;
  return 0;
}