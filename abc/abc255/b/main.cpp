#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(k),x(n),y(n);
  REP(i,k) { cin >> a[i]; a[i]--; }
  REP(i,n) cin >> x[i] >> y[i];

  double ans = 0;
  REP(i,n) {
    double now = 1e6;
    for(int j: a) {
      double dx = x[i]-x[j];
      double dy = y[i]-y[j];
      now = min(now, sqrt(dx*dx + dy*dy));
    }
    ans = max(ans,now);
  }

  printf("%0.10f\n", ans);
  return 0;
}