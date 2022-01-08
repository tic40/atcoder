#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
const int INF = 1e9;

int n,x,y;
vector<int> a,b;
int dp[305][305][305];

void solve() {
  REP(i,301) REP(j,301) REP(k,301) dp[i][j][k] = INF;
  REP(i,301) dp[i][0][0] = 0;

  REP(i,n) REP(j,x+1) REP(k,y+1) {
    dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
    if (dp[i][j][k] != INF) {
      dp[i+1][min(x, j+a[i])][min(y, k+b[i])] = min(
        dp[i+1][min(x, j+a[i])][min(y, k+b[i])],
        dp[i][j][k]+1
      );
    }
  }

  cout << (dp[n][x][y] == INF ? -1 : dp[n][x][y]) << endl;
  return;
}

int main() {
  cin >> n >> x >> y;
  a.resize(n);
  b.resize(n);
  REP(i,n) cin >> a[i] >> b[i];

  solve();
  return 0;
}