#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

vector<vector<int>> g(2e5);
vector<bool> visited(2e5), on(2e5);

// dfsでサイクルを検出する
int dfs(int v, int p) {
  if (visited[v]) return v;
  visited[v] = true;

  for(int u: g[v]) {
    if (u == p) continue;
    int r = dfs(u,v);
    if (r == -1) continue;
    on[v] = true;
    if (v == r) return -1;
    return r;
  }
  return -1;
}

int main() {
  int n; cin >> n;
  REP(i,n) {
    int u,v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(0,-1);
  dsu t(n);

  REP(i,n) for(int j: g[i]) {
    if (on[i] && on[j]) continue;
    t.merge(i,j);
  }

  int q; cin >> q;
  REP(_,q) {
    int a,b; cin >> a >> b;
    a--; b--;
    cout << (t.same(a,b) ? "Yes" : "No") << endl;
  }

  return 0;
}