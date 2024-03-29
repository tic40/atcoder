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

  vector<ll> sz(n);
  auto dfs = [&](auto self, int i, int p) -> ll {
    ll res = 0;
    sz[i] = 1;
    for(auto v: g[i]) {
      if (v == p) continue;
      res += self(self,v,i);
      res += sz[v] * (n - sz[v]);
      sz[i] += sz[v];
    }
    return res;
  };
  cout << dfs(dfs,0,-1) << endl;
  return 0;
}