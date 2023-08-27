#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353;

int main() {
  int n; cin >> n;
  dsu uf(n);
  vector g(n,vector<int>());
  // sv[i] := 頂点 i のプレイヤー数
  vector<int> sz(n*2-1,1);
  // gv[i] := 直近でプレイヤー i を含む頂点の番号
  vector<int> gv(n);
  REP(i,n) gv[i] = i;

  REP(i,n-1) {
    int p,q; cin >> p >> q;
    p--; q--;

    p = uf.leader(p);
    q = uf.leader(q);

    int v = g.size();
    g.push_back(vector<int>({gv[p], gv[q]}));
    uf.merge(p,q);
    gv[uf.leader(p)] = v;
    sz[v] = uf.size(p);
  }

  vector<mint> dp(g.size());
  auto dfs = [&](auto self, int v) -> void {
    for(int u: g[v]) {
      dp[u] = dp[v] + mint(sz[u]) / sz[v];
      self(self,u);
    }
  };

  int root = g.size()-1;
  dfs(dfs,root);

  REP(i,n) cout << dp[i].val() << " ";
  return 0;
}