#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int a[105][105];
int dp[105][105];

int main() {
  int n; cin >> n;
  REP(i,n) REP(j,n) cin >> a[i][j];

  dp[0][0]=a[0][0];
  REP(i,n) REP(j,n) {
    dp[i+1][j] = max(dp[i+1][j], dp[i][j] + a[i+1][j]);
    dp[i][j+1] = max(dp[i][j+1], dp[i][j] + a[i][j+1]);
  }
  cout << dp[n-1][n-1] << endl;
  return 0;
}