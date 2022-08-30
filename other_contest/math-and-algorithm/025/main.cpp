#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<double> a(n),b(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];

  double ans = 0;
  REP(i,n) ans += a[i]/3 + b[i]/3*2;

  printf("%.10f\n",ans);
  return 0;
}