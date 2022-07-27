#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();

int main() {
  int n,k; cin >> n >> k;
  vector<int> x(n),y(n);
  set<int> sx,sy;
  REP(i,n) {
    cin >> x[i] >> y[i];
    sx.insert(x[i]);
    sy.insert(y[i]);
  }

  ll ans = LINF;
  for(int x1: sx) for(int x2: sx) {
    for(int y1: sy) for(int y2: sy) {
      auto [lx,rx] = minmax(x1,x2);
      auto [ly,ry] = minmax(y1,y2);
      int cnt = 0;
      REP(i,n) {
        if (lx <= x[i] && x[i] <= rx && ly <= y[i] && y[i] <= ry) cnt++;
      }
      if (k <= cnt) {
        ll now = (ll)abs(rx-lx) * abs(ry-ly);
        ans = min(ans,now);
      }
    }
  }

  cout << ans << endl;
  return 0;
}