#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

vector<vector<int>> g(2e5);
vector<bool> visited(2e5),on(2e5);

// サイクルを検出するdfs
int dfs(int v, int p) {
  if (visited[v]) return v;
  visited[v] = true;

  for(int u: g[v]) {
    if (u == p) continue;
    int r = dfs(u,v);
    if (r == -1) continue;
    on[v] = true;

    return v == r ? -1 : r;
  }
  // サイクルでなければ -1 を返す
  return -1;
}

int main() {
  int n; cin >> n;
  REP(i,n) {
    int u,v; cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(0,-1);
  dsu uf(n);

  REP(i,n) for(int j: g[i]) {
    // サイクル同士以外を連結する
    if (on[i] && on[j]) continue;
    uf.merge(i,j);
  }

  int q; cin >> q;
  REP(i,q) {
    int x,y; cin >> x >> y;
    x--; y--;
    cout << (uf.same(x,y) ? "Yes" : "No") << endl;
  }
  return 0;
}