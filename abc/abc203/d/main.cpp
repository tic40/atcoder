#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector a(n, vector<int>(n));
  REP(i,n) REP(j,n) cin >> a[i][j];

  int ok = 1e9, ng = -1;
  while(ok - ng > 1) {
    int mid = (ok+ng) / 2;

    // 累積和
    vector dp(n+1, vector<int>(n+1));
    REP(i,n) REP(j,n) {
      dp[i+1][j+1] += a[i][j] > mid ? 1 : 0;
      dp[i+1][j+1] += dp[i+1][j];
      dp[i+1][j+1] += dp[i][j+1];
      dp[i+1][j+1] -= dp[i][j];
    }

    bool possible = false;
    REP(i,n-k+1) REP(j,n-k+1) {
      int now = dp[i+k][j+k] - dp[i+k][j] - dp[i][j+k] + dp[i][j];
      if (now <= k*k/2) possible = true;
    }

    if (possible) ok = mid;
    else ng = mid;
  }

  cout << ok << endl;
  return 0;
}