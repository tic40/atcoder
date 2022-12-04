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

int n;
vector<Point> vp;

// 座標(x,y) の偏角を返す
double getangle(double x, double y) {
  return atan2(y,x) * 180.0 / M_PI;
}

// [偏角a]-[原点]-[偏角b] のなす角度を求める
// 例えば a = 240°、b = 30°のとき、求める角度は 150°
double getangle2(double a, double b) {
  double x = abs(a-b);
  return x >= 180 ? 360 - x : x;
}

double solve(int x) {
  vector<double> vs;
  REP(i,n) {
    if (i == x) continue;
    auto now = vp[x] - vp[i];
    vs.push_back(getangle(now.px, now.py));
  }
  sort(vs.begin(),vs.end());

  double res = 0;
  int nvs = vs.size();
  for(double v: vs) {
    double target = v+180;
    if (target >= 360) target -= 360;
    int idx = lower_bound(vs.begin(),vs.end(),target) - vs.begin();
    int idx1 = idx % nvs;
    int idx2 = ((idx - 1) % nvs + nvs) % nvs;

    res = max({
      res,
      getangle2(v,vs[idx1]),
      getangle2(v,vs[idx2])
    });
  }
  return res;
}

int main() {
  cin >> n;
  REP(i,n) {
    double x,y; cin >> x >> y;
    vp.emplace_back(x,y);
  }

  double ans = 0;
  REP(i,n) ans = max(ans, solve(i));
  printf("%.10f",ans);
  return 0;
}