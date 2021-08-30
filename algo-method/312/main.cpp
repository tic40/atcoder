#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
const int INF = 1e9;

int dp[505][10005];

int main() {
  int n,m,k;
  cin >> n >> m >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  REP(i,n+1) REP(j,m+1) dp[i][j] = INF;
  dp[0][0] = 0;

  REP(i,n) {
    REP(j,m+1) {
      dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
      if (j - a[i] >= 0) {
        dp[i+1][j] = min(dp[i][j], dp[i][j-a[i]] + 1);
      }
    }
  }

  cout << (dp[n][m] <= k ? "Yes" : "No") << endl;
  return 0;
}