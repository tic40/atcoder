#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,ll>;
const ll LINF = numeric_limits<ll>::max();

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<P>());
  REP(i,m) {
    int u,v; ll w; cin >> u >> v >> w; u--; v--;
    g[u].emplace_back(v,w);
    g[v].emplace_back(u,w);
  }

  vector<bool> visited(n);
  auto dfs = [&](auto& dfs, int i, ll cur) -> ll {
    if (i == n-1) return cur;

    ll res = LINF;
    for(auto [ni,w]: g[i]) if (!visited[ni]) {
      visited[ni] = true;
      res = min(res,dfs(dfs,ni,cur^w));
      visited[ni] = false;
    }
    return res;
  };

  visited[0] = true;
  cout << dfs(dfs,0,0) << endl;
  return 0;
}
