#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();

int main() {
  int t; cin >> t;
  REP(_,t) {
    int n,w; cin >> n >> w;
    vector<int> c(n);
    REP(i,n) cin >> c[i];

    int w2 = 2*w;
    vector<ll> cost(w2);
    REP(i,n) cost[i%w2] += c[i];

    ll now = 0;
    REP(i,w) now += cost[i];

    ll ans = now;
    REP(l,w2) {
      now -= cost[l];
      now += cost[(l+w) % w2];
      ans = min(ans,now);
    }
    cout << ans << endl;
  }
  return 0;
}
