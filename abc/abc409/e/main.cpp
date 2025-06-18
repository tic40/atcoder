#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector<int> x(n);
  REP(i,n) cin >> x[i];
  vector g(n,vector<P>());
  REP(i,n-1) {
    int u,v,w; cin >> u >> v >> w; u--; v--;
    g[u].emplace_back(v,w);
    g[v].emplace_back(u,w);
  }

  auto dfs = [&](auto& dfs, int u, int p) -> ll {
    ll ans = 0;
    for(auto [v,w]: g[u]) if (v != p) {
      ans += dfs(dfs,v,u) + (ll)w * abs(x[v]);
      x[u] += x[v];
    }
    return ans;
  };

  cout << dfs(dfs,0,-1) << endl;
  return 0;
}