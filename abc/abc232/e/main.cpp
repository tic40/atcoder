#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using mint = modint998244353;

int main() {
  int h,w,k;
  cin >> h >> w >> k;
  int sx,sy,tx,ty;
  cin >> sx >> sy >> tx >> ty;

  // dp[i][j]
  //   i: txと同じ列の場合は1, 異なる場合は0
  //   j: tyと同じ行の場合は1, 異なる場合は0
  vector dp(2, vector<mint>(2));

  // 初期値
  dp[sx == tx][sy == ty] = 1;

  REP(ki,k) {
    vector p(2, vector<mint>(2));
    swap(p,dp); // pからdpへの遷移

    REP(j,2) {
      // txと異なる列から別のtxと異なる列への移動
      dp[0][j] += p[0][j]*(h-2);
      // txと異なる列からtxと同じ列への移動
      dp[1][j] += p[0][j];
      // txと同じ列からtxと異なる列への移動
      dp[0][j] += p[1][j]*(h-1);
    }

    REP(i,2) {
      dp[i][0] += p[i][0]*(w-2);
      dp[i][1] += p[i][0];
      dp[i][0] += p[i][1]*(w-1);
    }
  }

  cout << dp[1][1].val() << endl;
  return 0;
}