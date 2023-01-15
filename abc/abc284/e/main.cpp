#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int n,m;
vector<vector<int>> g(2e5);
vector<bool> visited(2e5);
int tot = 0;
bool flag = false;

void dfs(int i) {
  tot++;
  if (tot >= 1000000) { flag = true; return; }
  visited[i] = true;
  for(auto v: g[i]) {
    if (visited[v]) continue;
    dfs(v);
  }
  visited[i] = false;
  return;
}

int main() {
  cin >> n >> m;
  REP(i,m) {
    int u,v; cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(0);
  int ans = min(tot, 1000000);
  cout << ans << endl;
  return 0;
}