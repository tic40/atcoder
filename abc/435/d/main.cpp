#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<vector<int>> g(n);
  vector<int> visited(n);
  REP(i,m) {
    int x,y; cin >> x >> y;
    x--; y--;
    g[y].emplace_back(x);
  }
  auto dfs = [&](auto dfs, int i) {
    if (visited[i]) return;
    visited[i] = 1;
    for(auto v: g[i]) dfs(dfs,v);
    return;
  };

  int q; cin >> q;
  REP(i,q) {
    int t,v; cin >> t >> v; v--;
    if (t == 1) dfs(dfs,v);
    if (t == 2) cout << (visited[v] ? "Yes" : "No") << endl;
  }
  return 0;
}
