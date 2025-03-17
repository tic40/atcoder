#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  int nk = n*k;
  vector g(nk,vector<int>());
  REP(i,nk-1) {
    int u,v; cin >> u >> v; u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  // DFS: まだ分解していない頂点 i の部分木のパスの長さを返す
  auto dfs = [&](auto& dfs, int i, int p) -> int {
    int len = 1, cnt = 0;
    for(auto v: g[i]) if (v!=p) {
      int res = dfs(dfs,v,i);
      if (res == -1) return -1;
      if (res > 0) { len+=res; cnt++; }
    }

    if (cnt <= 1) return len == k ? 0 : len;
    if (cnt == 2) return len == k ? 0 : -1;
    return -1;
  };

  cout << (dfs(dfs,0,-1) == 0 ? "Yes" : "No") << endl;
  return 0;
}
