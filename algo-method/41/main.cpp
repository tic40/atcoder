#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int a[1005][3];
int dp[1005][3]; // dp[i][j] := i日目にjを選んだときの最大

int main() {
  int n; cin >> n;
  REP(i,n) REP(j,3) cin >> a[i][j];
  REP(i,3) dp[0][i] = a[0][i];

  REP(i,n) {
    if (i == 0) continue;
    REP(j,3) {
      REP(k,3) {
        if (j == k) continue;
        dp[i][j] = max(dp[i][j], dp[i-1][k] + a[i][j]);
      }
    }
  }

  int ans = 0;
  REP(i,3) ans = max(ans, dp[n-1][i]);
  cout << ans << endl;
  return 0;
}