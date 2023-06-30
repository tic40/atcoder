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

  vector<int> dist(n);
  auto dfs = [&](auto self, int i, int p) -> void {
    for(auto v: g[i]) {
      if (v == p) continue;
      dist[v] = dist[i]+1;
      self(self,v,i);
    }
  };
  dfs(dfs,0,-1);
  auto idx = max_element(dist.begin(),dist.end()) - dist.begin();
  dist = vector<int>(n);
  dfs(dfs,idx,-1);
  int ans = *max_element(dist.begin(),dist.end()) + 1;
  cout << ans << endl;

  return 0;
}