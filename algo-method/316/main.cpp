#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
const int INF = 1e9;

int c[105][105];
int dp[105][105]; // [i][j] := [aからi個][bからj個] まで取ったときの最小コスト

int main() {
  int n,m;
  cin >> n >> m;
  REP(i,n) REP(j,m) cin >> c[i][j];
  REP(i,n+5) REP(j,m+5) dp[i][j] = INF;

  dp[0][0]=0;
  REP(i,n) {
    REP(j,m) {
      dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + c[i][j]);
      dp[i+1][j+1] = min(dp[i+1][j+1], dp[i+1][j] + c[i][j]);
      dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j+1] + c[i][j]);
    }
  }

  cout << dp[n][m] << endl;

  return 0;
}