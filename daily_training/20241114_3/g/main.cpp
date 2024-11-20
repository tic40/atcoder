#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<P>());

  vector<tuple<ll,ll,ll>> tp;
  REP(i,m) {
    int u,v,w; cin >> u >> v >> w;
    u--; v--;
    g[u].emplace_back(v,w);
    g[v].emplace_back(u,-w);
    tp.emplace_back(u,v,w);
  }

  vector<int> visited(n);
  vector<ll> ans(n);
  auto dfs = [&](auto dfs, int u) {
    if (visited[u]) return;
    visited[u] = 1;
    for(auto [v,w]: g[u]) if (!visited[v]) {
      ans[v] = w + ans[u];
      dfs(dfs,v);
    }
  };

  REP(i,n) dfs(dfs,i);
  for(auto [u,v,w]: tp) assert(w == ans[v]-ans[u]);
  REP(i,n) cout << ans[i] << " ";
  return 0;
}