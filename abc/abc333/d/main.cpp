#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector g(n,vector<int>());
  REP(i,n-1) {
    int u,v; cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  auto dfs = [&](auto self, int i, int p) -> int {
    int res = 1;
    for(auto v: g[i]) {
      if (v == p) continue;
      res += self(self,v,i);
    }
    return res;
  };

  vector<int> s;
  for(auto v: g[0]) s.push_back(dfs(dfs,v,0));
  sort(s.begin(),s.end());

  s.pop_back();
  int ans = 1;
  for(auto v: s) ans += v;
  cout << ans << endl;

  return 0;
}