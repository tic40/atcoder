#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353; // modint1000000007;

int main() {
  int n,m,k; cin >> n >> m >> k;
  vector g(n,vector<int>());
  REP(i,m) {
    int u,v; cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  // dp[i][j] := i 日間までみたときに最後に都市 j にいるときの場合の数
  vector dp(k+1,vector<mint>(n));
  dp[0][0] = 1;

  REP(i,k) {
    mint tot = 0;
    REP(j,n) tot += dp[i][j];
    REP(j,n) {
      auto ntot = tot;
      for(int v: g[j]) ntot -= dp[i][v];
      ntot -= dp[i][j];
      dp[i+1][j] = ntot;
    }
  }
  cout << dp[k][0].val() << endl;
  return 0;
}