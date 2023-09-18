#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,x,y; cin >> n >> x >> y;
  vector<int> p(n-1),t(n-1);
  REP(i,n-1) cin >> p[i] >> t[i];
  const int m = 840; // lcm(1,2,...8)

  vector<ll> d(m);
  REP(si,m) {
    ll now = si+x;
    REP(i,n-1) {
      while(now % p[i]) now++;
      now += t[i];
    }
    now += y;
    d[si] = now - si;
  }

  int q; cin >> q;
  REP(_,q) {
    ll t; cin >> t;
    ll ans = t + d[t % m];
    cout << ans << endl;
  }
  return 0;
}