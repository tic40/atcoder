#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

int main() {
  int n; cin >> n;
  vector<int> x(n),y(n),z(n);
  REP(i,n) cin >> x[i] >> y[i] >> z[i];

  // dp[bit][j] := [訪れた都市集合][今いる都市] = 最小コスト
  vector<vector<int>> dp(1<<n,vector<int>(n,INF));

  // 都市iから都市jへのコストを事前計算
  vector cost(n,vector<int>(n));
  REP(i,n) REP(j,n) cost[i][j] = abs(x[j]-x[i]) + abs(y[j]-y[i]) + max(0,z[j]-z[i]);

  // 開始点0から各都市への移動
  REP(i,n) dp[1<<i][i] = cost[0][i];

  // bitの状態のときにiからjへの移動
  REP(bit,1<<n) REP(i,n) REP(j,n) {
    if ((bit >> i & 1) && (bit >> j & 1) == 0) {
      chmin(dp[bit | 1<<j][j], dp[bit][i] + cost[i][j]);
    }
  }

 // 全てに訪問済みで今いる都市が0(開始点に戻ってきている)の最小コスト
  cout << dp[(1<<n)-1][0] << endl;
}