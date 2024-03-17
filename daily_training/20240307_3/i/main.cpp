#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const int INF = 1e9;

int main() {
  int n,m; cin >> n >> m;
  vector<vector<int>> g(n,vector<int>(n,INF));
  REP(i,n) g[i][i] = 0;
  REP(i,m) {
    int u,v,w; cin >> u >> v >> w;
    u--; v--;
    g[u][v] = min(g[u][v],w);
  }

  REP(k,n) REP(i,n) REP(j,n) {
    g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
  }

  // dp[s][i] := 任意の頂点から始まって
  // 頂点 i で終わるようなウォークのうち、
  // 通る頂点の集合が S であるようなものに対する通る辺の重みの総和の最小値
  int n2 = 1<<n;
  vector<vector<int>> dp(n2,vector<int>(n,INF));
  REP(i,n) dp[1<<i][i] = 0;

  REP(s,n2) REP(i,n) {
    if (dp[s][i] == INF) continue;
    REP(j,n) {
      if ((~s>>j&1) && g[i][j] != INF) {
        int ns = s | 1<<j;
        dp[ns][j] = min(dp[ns][j], dp[s][i]+g[i][j]);
      }
    }
  }

  int ans = INF;
  REP(i,n) ans = min(ans, dp[n2-1][i]);
  if (ans == INF) cout << "No" << endl;
  else cout << ans << endl;
  return 0;
}