#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector g(n,vector<int>());
  REP(i,n-1) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector cnt(2,vector<int>());
  auto dfs = [&](auto self, int i, int p, int f) -> void {
    cnt[f].push_back(i+1);
    for(int v: g[i]) if (v != p) self(self,v,i,f^1);
  };

  dfs(dfs,0,-1,0);
  auto ans = (int)cnt[0].size() >= n/2 ? cnt[0] : cnt[1];
  REP(i,n/2) cout << ans[i] << " ";
  return 0;
}