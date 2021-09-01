#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int dp[105][10005];

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> a(n-1),b(n-1);
  REP(i,n-1) cin >> a[i];
  REP(i,n-1) cin >> b[i];

  REP(i,n) REP(j,m) dp[i][j] = -1;
  dp[0][0] = 0;

  REP(i,n-1) {
    REP(j,m) {
      if (dp[i][j] == -1) continue;
      dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
      if (j+a[i] < m) {
        dp[i+1][j+a[i]] = max(dp[i+1][j+a[i]], dp[i][j]+b[i]);
      }
    }
  }

  cout << dp[n-1][m-1] << endl;
  return 0;
}