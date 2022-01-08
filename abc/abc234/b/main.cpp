#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

double dist(int x, int y, int x2, int y2) {
  int dx = abs(x-x2);
  int dy = abs(y-y2);
  int r = dx*dx + dy*dy;
  return sqrt(r);
}

int main() {
  int n; cin >> n;
  vector<int> x(n),y(n);
  REP(i,n) cin >> x[i] >> y[i];

  double ans = 0.0;
  REP(i,n) REP(j,n) ans = max(ans, dist(x[i],y[i],x[j],y[j]));
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}