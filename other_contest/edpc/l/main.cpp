#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; cin >> n;
  vector<double> p(n);
  REP(i,n) cin >> p[i];

  vector<double> dp(n+1);
  dp[0] = 1;

  REP(i,n) {
    vector<double> ndp(n+1);
    swap(dp,ndp);
    REP(j,n) {
      dp[j+1] += ndp[j] * p[i];
      dp[j] += ndp[j] * (1.0-p[i]);
    }
  }

  double ans = accumulate(dp.begin()+n/2+1,dp.end(),0.0);
  printf("%0.10f\n", ans);
  return 0;
}