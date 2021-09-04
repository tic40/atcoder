#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

// [i][j] := [何個まで見たか][重さ] = 最大の価値
int dp[105][10005];

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> w(n),v(n);

  REP(i,n) cin >> w[i];
  REP(i,n) cin >> v[i];

  REP(i,n) REP(j,m+1) {
    dp[i+1][j] = max(dp[i][j], dp[i+1][j]);
    if (0 <= j - w[i]) {
      dp[i+1][j] = max(dp[i+1][j], dp[i][j-w[i]] + v[i]);
    }
  }

  cout << dp[n][m] << endl;
  return 0;
}