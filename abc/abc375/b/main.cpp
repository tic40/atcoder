#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  int nx = 0, ny = 0;
  double ans = 0;
  REP(i,n) {
    int x,y; cin >> x >> y;
    ans += hypot(x-nx,y-ny);
    nx = x, ny = y;
  }
  ans += hypot(nx,ny);
  printf("%.10f\n", ans);
  return 0;
}