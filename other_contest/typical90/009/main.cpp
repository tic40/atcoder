#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

struct Point {
  double px,py;
  Point(double px, double py) : px(px), py(py) {}
  Point operator-(const Point& p1) {
    return Point(px - p1.px, py - p1.py);
  }
};

double getangle(double x, double y) { return atan2(y,x) * 180.0 / M_PI; }
double getangle2(double x, double y) {
  double res = abs(x-y);
  return res > 180.0 ? 360 - res : res;
}

int main() {
  int n; cin >> n;
  vector<Point> vp;
  REP(i,n) {
    double x,y; cin >> x >> y;
    vp.emplace_back(x,y);
  }

  auto solve = [&](int x) {
    // vp[x] を原点に移動したときの各点の偏角
    vector<double> va;
    REP(i,n) {
      if (i == x) continue;
      auto now = vp[i] - vp[x];
      va.push_back(getangle(now.px, now.py));
    }
    sort(va.begin(),va.end());
    double res = 0;
    int sz = n-1;
    for(auto angle: va) {
      double target = angle + 180;
      if (target >= 360) target -= 360;
      int idx = lower_bound(va.begin(),va.end(),target) - va.begin();
      int idx1 = idx % sz;
      int idx2 = (idx1 - 1 + sz) % sz;
      res = max({ res, getangle2(angle, va[idx1]), getangle2(angle, va[idx2]) });
    }
    return res;
  };

  double ans = 0;
  REP(i,n) ans = max(ans, solve(i)); // 真ん中を決め打つ
  printf("%.10f",ans);
  return 0;
}