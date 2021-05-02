#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const double pi = 3.141592653589793;

double t,l,x,y,q;
vector<double> e;

void solve() {
  REP(i,q) {
    // 観覧車のx,y,z座標
    double deg = 360 * e[i] / t * pi / 180.0;
    double nx = 0;
    double ny = -l/2.0*sin(deg);
    double nz = l/2.0 - l/2.0*cos(deg);

    double a = sqrt(x*x + (ny-y)*(ny-y));
    double b = nz;
    double ans = atan2(b,a) * 180 / pi;
    cout << fixed << setprecision(10) << ans << endl;
  }
  return;
}

int main() {
  cin >> t >> l >> x >> y >> q;
  e.resize(q);
  REP(i,q) cin >> e[i];

  solve();
  return 0;
}