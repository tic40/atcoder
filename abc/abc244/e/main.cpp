#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using mint = modint998244353;

int n,m,k,s,t,x;
vector<vector<int>> g(2005);
mint dp[2005][2005][2];

void solve() {
  dp[0][s][0] = 1;

  REP(i,k) REP(j,n) {
    for(auto v: g[j]) {
      dp[i+1][v][v == x ? 1 : 0] += dp[i][j][0];
      dp[i+1][v][v == x ? 0 : 1] += dp[i][j][1];
    }
  }

  cout << dp[k][t][0].val() << endl;
  return;
}

int main() {
  cin >> n >> m >> k >> s >> t >> x;
  s--; t--; x--;

  REP(i,m) {
    int u,v; cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  solve();
  return 0;
}