#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector g(n,vector<int>());
  vector<int> deg(n);
  REP(i,n-1) {
    int u,v; cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
    deg[u]++; deg[v]++;
  }

  int leaf = -1;
  REP(i,n) if (deg[i] == 1) leaf = i;

  vector<int> ans;
  auto dfs = [&](auto self, int i, int p, int d) -> void {
    if (d % 3 == 1) ans.push_back(deg[i]);
    for(auto v: g[i]) {
      if (v == p) continue;
      self(self,v,i,d+1);
    }
  };

  dfs(dfs,leaf,-1,0);
  sort(ans.begin(),ans.end());
  for(auto v: ans) cout << v << " ";
  return 0;
}