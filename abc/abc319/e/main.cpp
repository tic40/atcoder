#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,x,y; cin >> n >> x >> y;
  vector<int> p(n-1),t(n-1);
  REP(i,n-1) cin >> p[i] >> t[i];
  int m = 1;
  // lcm(1,2,...8)
  for(int i = 1; i <= 8; i++) m = lcm(m,i);

  vector<ll> d(m);
  REP(i,m) {
    ll now = i+x;
    REP(j,n-1) {
      if (now % p[j]) now += p[j] - (now % p[j]);
      now += t[j];
    }
    now += y;
    d[i] = now - i;
  }

  int q; cin >> q;
  REP(_,q) {
    ll t; cin >> t;
    ll ans = t + d[t%m];
    cout << ans << endl;
  }
  return 0;
}