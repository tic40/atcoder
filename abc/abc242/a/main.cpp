#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  double a,b,c,x;
  cin >> a >> b >> c >> x;

  double ans = 0;
  if (a >= x) ans = 1;
  else if (b >= x) ans = c / (b - a);

  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}