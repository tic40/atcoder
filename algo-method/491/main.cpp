#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<pair<ll,ll>> vp(n);
  REP(i,n) {
    ll a,b; cin >> a >> b;
    vp[i] = { a, b };
  }
  sort(vp.begin(), vp.end());

  ll ans = 0;
  REP(i,n) {
    if (k <= 0) break;
    auto [ price, num ] = vp[i];
    if (num <= k) {
      ans += price * num;
      k -= num;
    } else {
      ans += price * k;
      k = 0;
    }
  }

  cout << ans << endl;
  return 0;
}