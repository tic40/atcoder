#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<int>());
  REP(i,m) {
    int a,b; cin >> a >> b; a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<bool> visited(n);
  auto dfs = [&](auto dfs, int i, int p) {
    if (visited[i]) return;
    visited[i] = true;
    if (g[i].size() != 2) return;
    for(auto v: g[i]) if (v != p) dfs(dfs,v,i);
  };

  dfs(dfs,0,-1);
  REP(i,n) if (!visited[i]) { cout << "No" << endl; return 0; }
  cout << "Yes" << endl;
  return 0;
}