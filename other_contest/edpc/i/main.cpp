#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<double> p(n);
  REP(i,n) cin >> p[i];
  // dp[i][j] := i 枚目までみたとき、表が j 毎出ている確率
  vector dp(n+1,vector<double>(n+1));
  dp[0][0] = 1;

  REP(i,n) REP(j,i+1) {
    if (dp[i][j] == 0) continue;
    // 表
    dp[i+1][j+1] += dp[i][j] * p[i];
    // 裏
    dp[i+1][j] += dp[i][j] * (1 - p[i]);
  }
  double ans = 0;
  for(int i = (n+1)/2; i <= n; i++) ans += dp[n][i];
  printf("%.10f\n",ans);
  return 0;
}