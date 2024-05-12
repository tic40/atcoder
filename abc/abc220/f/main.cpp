#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector g(n,vector<int>());
  REP(i,n-1) {
    int u,v; cin >> u >> v; u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> t(n); // 部分木サイズ
  vector<ll> ans(n);
  auto dfs1 = [&](auto self, int i, int p, int dist) -> ll {
    ll res = dist;
    t[i] = 1;
    for(auto v: g[i]) {
      if (v == p) continue;
      res += self(self,v,i,dist+1);
      t[i] += t[v];
    }
    return res;
  };
  ans[0] = dfs1(dfs1,0,-1,0);

  auto dfs2 = [&](auto self, int i, int p) -> void {
    for(auto v: g[i]) {
      if (v == p) continue;
      ans[v] = ans[i] + (n-t[v]) - t[v];
      self(self,v,i);
    }
  };
  dfs2(dfs2,0,-1);

  for(auto v: ans) cout << v << endl;
  return 0;
}