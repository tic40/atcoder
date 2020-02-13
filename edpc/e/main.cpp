#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  int N,W;
  cin >> N >> W;
  int w[N], v[N];
  REP(i,N) cin >> w[i] >> v[i];

  int mxV = 1000 * N;
  int dp[N+1][mxV+1];
  REP(i,N+1) REP(j,mxV+1) dp[i][j] = 1001001001;
  dp[0][0] = 0;

  REP(i,N) REP(j,mxV+1) {
    dp[i+1][j] = dp[i][j];
    if (j-v[i] >= 0 && (dp[i][j-v[i]]+w[i]) <= W) {
      dp[i+1][j] = min(dp[i+1][j],dp[i][j-v[i]]+w[i]);
    }
  }

  int ans = 0;
  REP(i,mxV+1) if (dp[N][i] <= W) ans = i;
  cout << ans << endl;
}