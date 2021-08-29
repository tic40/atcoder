#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int dp[105][105];

int main() {
  int n; cin >> n;
  REP(i,n) {
    int a; cin >> a;
    dp[0][i] = a;
  }

  REP(i,n) REP(j,n) {
    if (i == 0) continue;
    dp[i][j] += dp[i-1][j];
    if (j-1 >= 0) dp[i][j] += dp[i-1][j-1];
    if (j+1 < n) dp[i][j] += dp[i-1][j+1];
    dp[i][j] %= 100;
  }

  cout << dp[n-1][n-1] << endl;
  return 0;
}