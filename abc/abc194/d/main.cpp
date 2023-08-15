#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int n; cin >> n;
  double ans = 0;
  REP(i,n-1) {
    /*
      x: 期待値, p: 未連結の頂点を選ぶ確率
      x = 1 + (1-p) * x
      x = 1 + x - px
      px = 1
      x = 1/p
    */
    ans += 1.0 / ( (double)(n-i-1)/n );
  }
  printf("%.10f\n",ans);
  return 0;
}