#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n,m;
  cin >> n >> m;
  scc_graph g(n);
  vector<vector<int>> to(n);
  REP(i,m) {
    int u,v; cin >> u >> v;
    u--; v--;
    g.add_edge(u,v);
    to[u].push_back(v);
  }

  auto d = g.scc();
  int s = d.size();
  vector<int> di(n); // 頂点のグループ番号
  REP(i,s) for(int v: d[i]) di[v] = i;
  vector<bool> dp(s);

  for(int i = s-1; i >= 0; i--) {
    dp[i] = d[i].size() > 1;

    if (d[i].size() == 1) {
      for(int u: to[d[i][0]]) {
        if (dp[di[u]]) dp[i] = true;
      }
    }
  }

  int ans = 0;
  REP(i,s) if (dp[i]) ans += d[i].size();
  cout << ans << endl;
  return 0;
}