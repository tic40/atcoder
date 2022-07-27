#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();

int main() {
  int n,k; cin >> n >> k;
  vector<int> x(n),y(n);
  REP(i,n) cin >> x[i] >> y[i];

  ll ans = LINF;
  for(int x1: x) for(int x2: x) for(int y1: y) for(int y2: y) {
    auto [lx,rx] = minmax(x1,x2);
    auto [ly,ry] = minmax(y1,y2);
    int cnt = 0;
    REP(i,n) {
      if (lx <= x[i] && x[i] <= rx && ly <= y[i] && y[i] <= ry) cnt++;
    }
    ll area = abs((ll)(rx-lx) * (ry-ly));
    if (k <= cnt) ans = min(ans, area);
  }
  cout << ans << endl;
  return 0;
}