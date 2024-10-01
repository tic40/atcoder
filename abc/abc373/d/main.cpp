#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<P>());
  REP(i,m) {
    int u,v,w; cin >> u >> v >> w;
    u--; v--;
    g[u].emplace_back(v,w);
    g[v].emplace_back(u,-w);
  }

  vector<ll> ans(n);
  vector<int> visited(n);
  auto dfs = [&](auto self, int i) {
    if (visited[i]) return;
    visited[i] = true;
    for(auto [to,cost]: g[i]) if (!visited[to]) {
      ans[to] = cost + ans[i];
      self(self,to);
    }
  };
  REP(i,n) dfs(dfs,i);
  for(auto v: ans) cout << v << " ";
  return 0;
}