#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  double a,b,x;
  cin >> a >> b >> x;

  double v = a*a*b;

  // ラジアンtだけ傾けたときに入る水の体積
  auto f = [&](double t) {
    // 半分より多いとき: 容器全体から水が入ってない部分を引くことで入っている水の体積を求める
    if (v < 2*x) return a*a*b - a*a*(a*tan(t))/2;
    // 半分以下のとき: 水の体積を直接求める
    else return a*b*(b/tan(t))/2;
  };

  // ラジアン. 0度〜90度まで
  double left = 0, right = M_PI/2;
  // 2分探索. 100回繰り返す
  REP(i,100) {
    double mid = (left+right)/2;
    if (f(mid) >= x) left = mid;
    else right = mid;
  }
  cout << printf("%0.10f",left*180/M_PI);

  return 0;
}