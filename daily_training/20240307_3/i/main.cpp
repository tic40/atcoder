#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = 1e9;

int main() {
  int n,m; cin >> n >> m;
  // 隣接行列
  vector g(n,vector<int>(n,INF));
  REP(i,n) g[i][i] = 0;
  REP(i,m) {
    int u,v,w; cin >> u >> v >> w;
    u--; v--;
    // 同じ辺がある場合はコストが小さい方が最適
    g[u][v] = min(g[u][v],w);
  }

  // warshall floyd
  REP(k,n) REP(i,n) REP(j,n) g[i][j] = min(g[i][j], g[i][k]+g[k][j]);

  // dp[s][i] := 任意の頂点から始まって
  // 頂点 i で終わるようなウォークのうち、
  // 通った頂点の集合が S であるようなものに対する通る辺の重みの総和の最小値
  int n2 = 1<<n;
  vector dp(n2,vector<int>(n,INF));
  REP(i,n) dp[1<<i][i] = 0;

  REP(bit,n2) REP(i,n) {
    // INF のときは到達不可
    if (dp[bit][i] == INF) continue;
    // 集合 s(bit) のときの 頂点　i から 頂点　j へ動くことを考える
    REP(j,n) {
      // INF のときは到達不可
      if (g[i][j] == INF) continue;
      int nbit = bit | 1<<j;
      dp[nbit][j] = min(dp[nbit][j], dp[bit][i]+g[i][j]);
    }
  }

  int ans = INF;
  REP(i,n) ans = min(ans, dp[n2-1][i]);
  if (ans == INF) cout << "No" << endl;
  else cout << ans << endl;
  return 0;
}