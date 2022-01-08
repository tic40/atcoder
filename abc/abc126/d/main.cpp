#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

struct Edge {
  int to, d;
};

int n;
vector<vector<Edge>> g;
vector<int> ans;

void dfs(int cur) {
  for(auto v: g[cur]) {
    if (ans[v.to] != -1) continue;
    ans[v.to] = v.d % 2 == 0 ? ans[cur] : ans[cur] ^ 1;
    dfs(v.to);
  }

  return;
}

void solve() {
  ans.resize(n, -1);
  ans[0] = 0;
  dfs(0);

  for(int v: ans) cout << v << endl;
  return;
}

int main() {
  cin >> n;
  g.resize(n);
  int u,v,w;
  REP(i,n-1) {
    cin >> u >> v >> w;
    u--; v--;
    g[u].emplace_back(Edge({v, w}));
    g[v].emplace_back(Edge({u, w}));
  }

  solve();
  return 0;
}