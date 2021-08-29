#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int dp[20][20];

int main() {
  int n; cin >> n;

  dp[0][0]=1;
  REP(i,n) REP(j,n) {
    if (j+1 < n) dp[i][j+1] += dp[i][j];
    if (i+1 < n) dp[i+1][j] += dp[i][j];
  }
  cout << dp[n-1][n-1] << endl;
  return 0;
}