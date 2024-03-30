#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint;

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<int>());
  REP(i,n-1) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  mint::set_mod(m);
  // dp[i] := 頂点 i の部分木の塗り方において、
  // 頂点 i が黒色に塗られていて黒色の頂点が全て連結である塗り方の組み合わせ
  vector<mint> dp(n+1);
  vector<mint> ans(n+1);

  auto dfs1 = [&](auto self, int now, int p) -> void {
    dp[now] = 1;
    for(auto to: g[now]) {
      if (to == p) continue;
      self(self,to,now);
      // +1 は部分木 to 以下が全て白の場合
      dp[now] *= dp[to] + 1;
    }
  };

  // 全方位木の計算
  auto dfs2 = [&](auto self, int now, int p) -> void {
    ans[now] = 1;
    // now を親としたときの組み合わせを計算
    for(auto to: g[now]) ans[now] *= dp[to] + 1;

    int n = g[now].size();
    vector<mint> l(n),r(n); // left, right
    REP(i,n) l[i] = r[i] = dp[g[now][i]] + 1;
    for(int i = 1; i < n; i++) l[i] *= l[i-1];
    for(int i = n-2; i >= 0; i--) r[i] *= r[i+1];

    REP(i,n) {
      if (g[now][i] == p) continue;
      dp[now] = 1;
      if (i > 0) dp[now] *= l[i-1];
      if (i+1 < n) dp[now] *= r[i+1];
      self(self,g[now][i],now);
    }
  };

  dfs1(dfs1,0,-1);
  dfs2(dfs2,0,-1);

  REP(i,n) cout << ans[i].val() << endl;
  return 0;
}