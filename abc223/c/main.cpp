#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int n;
vector<double> a,b;

// 2分探索
/*
void solve() {

  double tot = 0;
  REP(i,n) tot += a[i]; // 合計距離
  double ok = tot;
  double ng = 0.0;

  // 距離
  while (abs(ok-ng) > 0.000001) {
    // 左からの距離
    double mid = (ok+ng)/2;

    double dl = 0;
    double lt = 0; // かかった時間
    REP(i,n) {
      if (dl+a[i] < mid) {
        dl += a[i];
        lt += a[i]/b[i];
      } else {
        lt += (mid - dl) / b[i];
        break;
      }
    }

    double dr = 0;
    double rt = 0; // かかった時間
    for(int i = n-1; 0 <= i; i--) {
      if (dr+a[i] < (tot-mid) ) {
        dr += a[i];
        rt += a[i]/b[i];
      } else {
        rt += (tot-mid - dr) / b[i];
        break;
      }
    }

    if (lt < rt) ng = mid;
    else ok = mid;
  }

  cout << fixed << setprecision(10) << ok << endl;
  return;
}
*/

void solve2() {
  // 片側からすべて燃やしたときの合計時間
  double total = 0;
  REP(i,n) total += a[i] / b[i];

  double mid_t = total/2;
  double ans = 0;
  double lt = 0; // 経過時間
  REP(i,n) {
    if (lt + a[i] / b[i] < mid_t) {
      lt += a[i] / b[i];
      ans += a[i];
    } else {
      ans += b[i] * (mid_t - lt);
      break;
    }
  }

  cout << fixed << setprecision(10) << ans << endl;
}

int main() {
  cin >> n;
  a.resize(n);
  b.resize(n);
  REP(i,n) cin >> a[i] >> b[i];

  // solve();
  solve2();
  return 0;
}