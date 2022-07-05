#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  double a,b,x;
  cin >> a >> b >> x;

  double v = a*a*b; // 容器の体積

  double left = 0, right = M_PI/2;
  // while(right-left > 0.000001) {
  REP(_,100) {
    // ラジアン mid だけ傾けたときにギリギリまで入る水の体積を調べる
    double mid = (right+left)/2;

    // 水の体積が全体の体積の半分以下かどうかで分岐
    double now = x <= v/2 ?
      a * (b / tan(mid)) * b / 2
      : v - (a * a * a * tan(mid) / 2);

    if (now >= x) left = mid;
    else right = mid;
  }

  printf("%.10f\n", left * 180 / M_PI);
  return 0;
}