#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int dp[105][10005];

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> w(n);
  REP(i,n) cin >> w[i];

  REP(i,n+1) REP(j,m+1) dp[i][j] = INF;

  dp[0][0] = 0;
  REP(i,n) {
    REP(j,m+1) {
      dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
      if (0 <= j - w[i])
      dp[i+1][j] = min(dp[i+1][j], dp[i][j-w[i]] + 1);
    }
  }

  cout << (dp[n][m] == INF ? -1 : dp[n][m]) << endl;
  return 0;
}