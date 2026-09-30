#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int t; cin >> t;
  REP(_,t) {
    int n,w; cin >> n >> w;
    vector<int> c(n);
    REP(i,n) cin >> c[i];

    int w2 = w*2;
    vector<ll> cost(w2);
    REP(i,n) cost[i%w2] += c[i];

    ll tot = 0;
    REP(i,w) tot += cost[i];
    ll ans = tot;

    REP(i,w2) {
      tot -= cost[i];
      tot += cost[(i+w) % w2];
      ans = min(ans,tot);
    }
    cout << ans << endl;
  }
  return 0;
}
