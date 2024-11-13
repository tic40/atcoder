#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector g(n,vector<int>());
  REP(i,n-1) {
    int u,v; cin >> u >> v; u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  ll ans = 0;
  auto dfs = [&](auto self, int u, int p) -> int {
    int ret = 0; // 部分木における次数 = 2 の頂点(端点) の内、頂点 u から結べる数
    for(auto v: g[u]) if (v != p) {
      int f = self(self,v,u);

      // size == 2: 端点のとき
      if (g[u].size() == 2) {
        if (g[v].size() == 3) ans += f;
        ret = 1;
      }
      // size == 3 端点ではないとき
      if (g[u].size() == 3) {
        ans += ll(ret) * f;
        ret += f;
      }
    }
    return ret;
  };

  dfs(dfs,0,-1);
  cout << ans << endl;
  return 0;
}