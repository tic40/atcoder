#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using mint = modint1000000007;

vector<vector<int>> g;
// dp[i][j] := dp[頂点i][白or黒] = 組み合わせの数
vector<vector<mint>> dp;

void dfs(int cur, int p) {
  dp[cur][0] = 1;
  dp[cur][1] = 1;

  for(int v: g[cur]) {
    if (v == p) continue; // 親に帰るのはだめ
    dfs(v, cur);
    // 白で塗る
    dp[cur][0] *= (dp[v][0]+dp[v][1]);
    // 黒で塗る
    dp[cur][1] *= dp[v][0];
  }
  return;
}

int main() {
  int n; cin >> n;
  g.resize(n);
  dp.resize(n, vector<mint>(2));

  REP(i,n-1) {
    int x,y; cin >> x >> y;
    x--; y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  dfs(0, -1);
  mint ans = dp[0][0] + dp[0][1];
  cout << ans.val() << endl;

  return 0;
}