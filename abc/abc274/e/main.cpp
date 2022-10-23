#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();

int main() {
  int n,m; cin >> n >> m;
  n+=1; // 原点分を追加
  int w = n+m;
  vector<int> x(w),y(w);
  for(int i = 1; i < w; i++) cin >> x[i] >> y[i];
  vector dist(w,vector<double>(w)); // dist[i][j] := iからjへの距離
  REP(i,w) REP(j,w) dist[i][j] = sqrt(powl(x[i]-x[j],2) + powl(y[i]-y[j],2));

  // dp[n][i] := すでに訪れた集合が n であって、最後にいる場所が i であるときの、合計コストの最小値
  vector dp(1<<w, vector<double>(w,LINF));
  dp[0][0] = 0;

  REP(bit, 1<<w) {
    int cnt = 0; // bitの状態で取得している宝箱数
    REP(i,m) if (bit>>(n+i) & 1) cnt++;

    // 各bitの状態でiからjへの遷移を考える
    REP(i,w) {
      if (dp[bit][i] == LINF) continue;
      REP(j,w) {
        if (bit>>j & 1) continue;
        int nb = bit | 1<<j;
        dp[nb][j] = min(dp[nb][j], dp[bit][i] + dist[i][j]/(1<<cnt));
      }
    }
  }

  double ans = LINF;
  int t = (1<<n)-1;
  REP(bit,1<<w) if ((bit&t)==t) ans = min(ans,dp[bit][0]);
  printf("%.10f\n",ans);
  return 0;
}