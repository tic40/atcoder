#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  double x,y,d; cin >> x >> y >> d;

  double r = d * M_PI / 180.0;
  double nx = x*cos(r) - y*sin(r);
  double ny = x*sin(r) + y*cos(r);

  printf("%.10f %.10f\n", nx, ny);

  return 0;
}