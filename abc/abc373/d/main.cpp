#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

struct Edge { int to, cost; };
int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<Edge>());
  REP(i,m) {
    int u,v,w; cin >> u >> v >> w;
    u--; v--;
    g[u].emplace_back(v,w);
    g[v].emplace_back(u,-w);
  }

  vector<int> visited(n);
  vector<ll> ans(n,0);
  auto dfs = [&](auto self, int i) -> void {
    if (visited[i]) return;
    visited[i] = true;

    for(auto [to, cost]: g[i]) {
      if (visited[to]) continue;
      ans[to] = ans[i] + cost; // ans[to] - ans[i] = cost;
      self(self,to);
    }
  };

  REP(i,n) dfs(dfs,i);
  for(auto v: ans) cout << v << " ";
  return 0;
}