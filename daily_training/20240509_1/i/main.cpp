#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector g(n,vector<int>());
  REP(i,n-1) {
    int u,v; cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  // 全方位木DP
  vector<int> t(n); // t[i] := 頂点 i から見た部分木のサイズ
  vector<ll> ans(n);
  auto dfs1 = [&](auto self, int i, int p) -> ll {
    ll res = 0;
    t[i] = 1;
    for(auto v: g[i]) {
      if (v == p) continue;
      // 頂点 v から見て i は親なので、その分 + t[v] する
      res += self(self,v,i) + t[v];
      t[i] += t[v];
    }
    return res;
  };
  ans[0] = dfs1(dfs1,0,-1);

  // dfs1 で求めた ans[0] から差分を求めていく
  auto dfs2 = [&](auto self, int i, int p) -> void {
    for(auto v: g[i]) {
      if (v == p) continue;
      // n-t[v] := 親の木のサイズ
      // t[v] := 部分木のサイズ
      ans[v] = ans[i] + (n-t[v]) - t[v];
      self(self,v,i);
    }
  };
  dfs2(dfs2,0,-1);
  for(auto v: ans) cout << v << endl;
  return 0;
}