#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n,m,l,s,t; cin >> n >> m >> l >> s >> t;
  vector g(n, vector<P>());
  REP(i,m) {
    int u,v,c; cin >> u >> v >> c; u--; v--;
    g[u].emplace_back(v,c);
  }

  vector<int> ans(n);
  auto dfs = [&](auto& dfs, int i, int cost, int cnt) -> void {
    if (cnt == l) {
      ans[i] |= s <= cost && cost <= t;
      return;
    }
    for(auto [v,c]: g[i]) dfs(dfs,v,cost+c,cnt+1);
  };
  dfs(dfs,0,0,0);

  REP(i,n) if (ans[i]) cout << i+1 << " ";
  return 0;
}
