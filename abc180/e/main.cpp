#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
template<class T>bool chmin(T &a,const T &b) {if(b<a){a=b; return 1;} return 0;}
const int INF = 1e9;

int main() {
  int n; cin >> n;
  int x[n],y[n],z[n];
  REP(i,n) cin >> x[i] >> y[i] >> z[i];

  // dp定義: [訪れた都市集合][今いる都市] = 最小コスト
  // 訪れた都市集合はbitで表現する
  // INF(十分大きい値)で初期化する
  vector<vector<int>> dp(1<<n,vector<int>(n,INF));

  // 都市iから都市jへのコストを事前計算
  int cost[n][n];
  REP(i,n) REP(j,n) {
    int c1 = abs(x[j]-x[i]);
    int c2 = abs(y[j]-y[i]);
    int c3 = max(0,z[j]-z[i]);
    cost[i][j] = c1+c2+c3;
  }

  // 開始点0から各都市への移動
  REP(i,n) {
    // 0から0への移動はスキップ
    if (i==0) continue;
    dp[1<<i][i] = cost[0][i];
  }

  REP(i,1<<n) {
    REP(j,n) {
      // j都市のフラグが立っていない場合
      // 未訪問のj都市からは移動できないのでスキップ
      if (~i>>j&1) continue;
      REP(k,n) {
        // k都市のフラグが立っている場合
        // 訪問済みなのでスキップ
        if (i>>k&1) continue;
        chmin(dp[i|1<<k][k], dp[i][j]+cost[j][k]);
      }
    }
  }

 // 全てに訪問済みで今いる都市が0(開始点に戻ってきている)の最小コスト
  cout << dp[(1<<n)-1][0] << endl;
}