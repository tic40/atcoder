#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
const int INF = 1e9;

int a[105][105];
int dp[105][105];

int main() {
  int n;
  cin >> n;
  REP(i,n) REP(j,n) cin >> a[i][j];
  REP(i,n) REP(j,n) dp[i][j] = INF;
  dp[0][n-1] = a[0][n-1];

  REP(i,n) for(int j = n-1; j>=0; j--) {
    if (j-1 >= 0) dp[i][j-1] = min(dp[i][j-1], dp[i][j] + a[i][j-1]);
    if (i+1 < n) dp[i+1][j] = min(dp[i+1][j], dp[i][j] + a[i+1][j]);
  }

  cout << dp[n-1][0] << endl;
  return 0;
}