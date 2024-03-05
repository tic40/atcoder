#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353;

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

  // dp[i][j][k]
  // i 回目の移動
  // j 今いる地点
  // k x の偶奇
  vector dp(k+1, vector(n, vector<mint>(2)));
  dp[0][s][0] = 1;
  REP(i,k) {
    REP(j,n) {
      for(auto v: g[j]) {
        if (v == x) {
          dp[i+1][v][1] += dp[i][j][0];
          dp[i+1][v][0] += dp[i][j][1];
        } else {
          dp[i+1][v][0] += dp[i][j][0];
          dp[i+1][v][1] += dp[i][j][1];
        }
      }
    }
  }
  cout << dp[k][t][0].val() << endl;
  return 0;
}