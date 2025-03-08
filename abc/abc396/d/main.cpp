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
    int u,v; ll w;
    cin >> u >> v >> w; u--; v--;
    g[u].emplace_back(v,w);
    g[v].emplace_back(u,w);
  }

  vector<int> visited(n);
  ll ans = LINF;
  auto dfs = [&](auto& dfs, int i, ll cur) -> void {
    if (i == n-1) { ans = min(ans,cur); return; }

    for(auto [ni,nw]: g[i]) if (visited[ni] == 0) {
      visited[ni] = 1;
      dfs(dfs,ni,cur^nw);
      visited[ni] = 0;
    }
  };

  visited[0] = 1;
  dfs(dfs,0,0);
  cout << ans << endl;
  return 0;
}
