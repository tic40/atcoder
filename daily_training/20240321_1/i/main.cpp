#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();
template<class T> void chmin(T& a, T b) { a = min(a,b); }

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  // dp[i][j][k]
  // i: 何個までみたか
  // j: 合計値
  // k: 最後の要素を操作したかどうか(0: 操作しない, 1: 操作する)
  vector dp(n+1,vector(m+1, vector<int>(2,INF)));
  dp[0][0][0] = 0;
  REP(i,n) REP(j,m+1) REP(k,2) {
    if (dp[i][j][k] == INF) continue;

    if (j+a[i] <= m) chmin(dp[i+1][j+a[i]][0], dp[i][j][k]);
    if (k == 0) chmin(dp[i+1][j][1], dp[i][j][k] + 1);
    if (k == 1) chmin(dp[i+1][j][1], dp[i][j][k]);
  }

  for(int i = 1; i <= m; i++) {
    int ans = min(dp[n][i][0], dp[n][i][1]);
    cout << (ans == INF ? -1 : ans) << endl;
  }
  return 0;
}