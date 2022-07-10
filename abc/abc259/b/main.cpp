#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int a,b,d;
  cin >> a >> b >> d;

  // 点a,bへの距離
  double r = hypot(a,b);
  // 点a,bの角度(radian)
  double t = atan2(b,a);
  t += d * M_PI / 180.0;

  double x = r * cos(t);
  double y = r * sin(t);

  printf("%.15f %.15f\n", x,y);
  return 0;
}