#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

struct Point {
  double px, py;
};
Point operator-(const Point& a1, const Point& a2) {
  return Point{ a1.px - a2.px, a1.py - a2.py };
}

int n;
Point g[2005];
const double pi = 3.141592653589793;

double getangle(Point p) {
  // double I = p.px / sqrt(p.px * p.px + p.py * p.py);
  // double kaku = acos(I) * 180.0 / pi;
  // return (0 <= p.py ? kaku : 360.0 - kaku);
  double kaku = atan2(p.py, p.px) * 180.0 / pi;
  return kaku;
}

double getangle2(double I1, double I2) {
  // [偏角 I1] - [原点] - [偏角 I2] のなす角度を求める
  // 例えば I1 = 240°、I2 = 30°のとき、求める角度は 150°
  double res = abs(I1 - I2);
  return 180.0 <= res ? 360.0 - res : res;
}

double solve(int pos) {
	// 最初に偏角の昇順にソートする
	vector<double> vec;
  REP(i,n) {
		if (i == pos) continue;
    Point sa = g[i] - g[pos];
    double angle = getangle(sa);
    vec.push_back(angle);
  }
  sort(vec.begin(), vec.end());

  // 点 A を全探索して、最も偏角の大きくなる点 C を二分探索（std::lower_bound）で求める
  double ret = 0.0;
  REP(i,vec.size()) {
    double target = vec[i] + 180.0;
    if (target >= 360.0) target -= 360.0;
    int pos1 = lower_bound(vec.begin(), vec.end(), target) - vec.begin();

    // 点 C の候補は高々 2 つに絞れる
    int CandIdx1 = pos1 % vec.size();
    int CandIdx2 = (pos1 + vec.size() - 1) % vec.size();
    double Candidate1 = getangle2(vec[i], vec[CandIdx1]);
    double Candidate2 = getangle2(vec[i], vec[CandIdx2]);
    ret = max({ ret, Candidate1, Candidate2 });
  }
  return ret;
}

int main() {
  cin >> n;
  REP(i,n) cin >> g[i].px >> g[i].py;

  double ans = 0;
  REP(i,n) ans = max(ans, solve(i));
  printf("%.10lf\n", ans);

  return 0;
}