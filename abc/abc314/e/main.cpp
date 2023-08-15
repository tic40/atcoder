#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

int main() {
  int n,m; cin >> n >> m;
  vector<double> c(n),p(n);
  vector s(n,vector<int>());
  REP(i,n) {
    cin >> c[i] >> p[i];
    s[i].resize(p[i]);
    REP(j,p[i]) cin >> s[i][j];
  }

  // 戦略: 残りポイント数 -> 最適なルーレット
  // dp[x]: 残り x 点の状態からの期待値
  vector<double> dp(m+1,INF);
  dp[0] = 0;
  REP(i,m+1) {
    REP(j,n) {
      double now = 0;
      double zero = 0;
      for(auto v: s[j]) {
        if (v == 0) zero++;
        else now += dp[max(0,i-v)];
      }
      now /= p[j]; // ランダムに選ばれるので 1 / p[j]
      now += c[j]; // 今の1回プレイする分
      // 0 ポイントがある場合の処理.
      // 高橋くんは 0 でないポイントを得るまで同じ i 番目のルーレットを回し続ける
      // 現在のポイントのまま高橋くんがこのルーレットを回す回数の期待値は p[j] / (p[j]-zero)
      now *= p[j] / (p[j] - zero);
      dp[i] = min(dp[i],now);
    }
  }
  printf("%.10f\n",dp[m]);
  return 0;
}