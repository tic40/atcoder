#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,u,v; cin >> n >> u >> v;
  u--; v--;
  vector g(n,vector<int>());
  REP(i,n-1) {
    int a,b; cin >> a >> b; a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> dist(n);
  auto dfs = [&](auto self, int i, int p) -> void {
    for(auto v: g[i]) if(v != p) {
      dist[v] = dist[i]+1;
      self(self,v,i);
    }
  };

  auto d = [&](int i) {
    dist = vector<int>(n);
    dfs(dfs,i,-1);
    return dist;
  };

  auto distU = d(u);
  auto distV = d(v);
  int ans = 0;
  REP(i,n) if (distU[i] < distV[i]) ans = max(ans,distV[i]);
  cout << ans-1 << endl;
  return 0;
}