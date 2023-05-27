#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint1000000007;

int main() {
  int n; cin >> n;
  vector g(n,vector<int>());
  REP(i,n-1) {
    int x,y; cin >> x >> y;
    x--; y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  // 0: 白, 1: 黒
  // dp[i][j] := i 頂点 で j(0: 白, 1: 黒) のときの組み合わせ数
  vector dp(n,vector<mint>(2));
  dp[0][0] = dp[0][1] = 1;

  auto dfs = [&](auto self, int i, int p) -> void {
    dp[i][0] = dp[i][1] = 1;
    for(auto v: g[i]) {
      if (v == p) continue;
      self(self,v,i);
      dp[i][0] *= (dp[v][0] + dp[v][1]);
      dp[i][1] *= dp[v][0];
    }
  };

  dfs(dfs,0,-1);
  cout << (dp[0][0] + dp[0][1]).val() << endl;
  return 0;
}