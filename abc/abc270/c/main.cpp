#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int n,x,y;
vector<vector<int>> g(2e5);
vector<int> ans;

bool dfs(int i, int p) {
  if (i == y) { ans.push_back(i); return true; }

  for(int v: g[i]) {
    if (v == p) continue;
    if (dfs(v,i)) { ans.push_back(i); return true; }
  }
  return false;
}

int main() {
  cin >> n >> x >> y;
  x--; y--;
  REP(i,n-1) {
    int u,v; cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(x,-1);
  reverse(ans.begin(),ans.end());
  for(int v: ans) cout << v+1 << " ";
  return 0;
}