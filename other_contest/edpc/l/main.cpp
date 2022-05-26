#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; cin >> n;
  vector<double> p(n);
  REP(i,n) cin >> p[i];

  vector<double> dp(n+1);
  dp[1] = p[0];
  dp[0] = 1.0-p[0];

  for(int i = 1; i < n; i++) {
    vector<double> np(n+1);
    swap(dp,np);
    REP(j,n) {
      if (np[j] == 0) continue;
      dp[j+1] += np[j]*p[i]; // 表
      dp[j] += np[j]*(1.0-p[i]); // 裏
    }
  }

  double ans = accumulate(dp.begin()+n/2+1, dp.end(), 0.0);
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
