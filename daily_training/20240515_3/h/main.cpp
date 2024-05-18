#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using mint = modint998244353; // modint1000000007;

int main() {
  int n,m,k,s,t,x;
  cin >> n >> m >> k >> s >> t >> x;
  s--; t--; x--;
  vector g(n,vector<int>());
  REP(i,m) {
    int u,v; cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector dp(k+1,vector(n,vector<mint>(2)));
  dp[0][s][0] = 1;
  REP(i,k) REP(j,n) REP(l,2) for(auto v: g[j]) {
    if (dp[i][j][l] == 0) continue;
    if (v == x) dp[i+1][v][l^1] += dp[i][j][l];
    else dp[i+1][v][l] += dp[i][j][l];
  }

  cout << dp[k][t][0].val() << endl;
  return 0;
}