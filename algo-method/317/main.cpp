#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int g[105][105];

int main() {
  int t; cin >> t;
  REP(i,t) REP(j,t) cin >> g[i][j];

  // dp[t]:= 時刻 [t−1,t] ではオフにしていた場合の、時刻 t までの総利得の最大値
  vector<int> dp(t+2);

  REP(k,t+2) REP(i,k) REP(j,k) {
    if (i < j) {
      dp[k] = max(dp[k], dp[i] + g[i][j-1]);
    }
  }

  cout << dp[t+1] << endl;
  return 0;
}