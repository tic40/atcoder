#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(k);
  REP(i,k) { cin >> a[i]; a[i]--; }

  vector<int> x(n),y(n);
  REP(i,n) cin >> x[i] >> y[i];

  double ans = 0;
  REP(i,n) {
    double d = 1e12;
    REP(j,k) {
      double dx = x[i] - x[a[j]];
      double dy = y[i] - y[a[j]];
      double dist = sqrt(dx*dx + dy*dy);
      d = min(dist,d);
    }
    ans = max(ans,d);
  }

  cout << printf("%0.10f\n", ans) << endl;
  return 0;
}