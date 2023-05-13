#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  double t,l,x,y; cin >> t >> l >> x >> y;
  int q; cin >> q;
  REP(_,q) {
    double e; cin >> e;
    // 現在の観覧車の角度
    double deg = 360.0 * e / t;
    double rad = deg * M_PI / 180.0;
    // 観覧車の座標 y,z
    double ny = -l / 2.0 * sin(rad);
    double nz = l / 2.0 - l / 2.0 * cos(rad);
    // 高橋像までの水平、垂直距離
    double a = sqrt(x*x + (ny-y)*(ny-y));
    double b = nz;
    // 俯角を求める
    double ans = atan2(b,a) * 180.0 / M_PI;
    printf("%.10lf\n", ans);
  }

  return 0;
}