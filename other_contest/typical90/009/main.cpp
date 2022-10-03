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
vector<Point> g;

double getangle(double x, double y) {
  return atan2(y,x) * 180.0 / M_PI;
}
double getangle2(double a, double b) {
  // [偏角 a] - [原点] - [偏角 b] のなす角度を求める
  // 例えば a = 240°、b = 30°のとき、求める角度は 150°
  double res = abs(a-b);
  return res >= 180.0 ? 360.0 - res : res;
}

double solve(int x) {
  vector<double> vc;
  REP(i,n) {
    if (i == x) continue;
    auto np = g[i] - g[x];
    vc.push_back(getangle(np.px, np.py));
  }
  sort(vc.begin(),vc.end());

  int nv = vc.size();
  double res = 0.0;
  REP(i,nv) {
    double target = vc[i] + 180.0;
    if (target >= 360.0) target -= 360.0;
    // 二分探索で最大になる候補を2つに絞る
    auto it = lower_bound(vc.begin(),vc.end(),target);
    int idx = it - vc.begin();

    int idx1 = idx % nv;
    int idx2 = ((idx - 1) % nv + nv) % nv;
    res = max({ res, getangle2(vc[i],vc[idx1]), getangle2(vc[i],vc[idx2]) });
  }
  return res;
}

int main() {
  cin >> n;
  REP(i,n) {
    double x,y; cin >> x >> y;
    g.emplace_back(x,y);
  }

  double ans = 0;
  REP(i,n) ans = max(ans, solve(i)); // 真ん中を決め打つ
  printf("%.10lf\n",ans);
  return 0;
}