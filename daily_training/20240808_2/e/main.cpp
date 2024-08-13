#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector g(2*n+2,vector<int>());
  REP(i,n) {
    int a; cin >> a;
    g[a].push_back((i+1)*2+1);
    g[a].push_back((i+1)*2);
  }

  vector<int> depth(2*n+2);
  auto dfs = [&](auto self, int i, int p) -> void {
    for(auto v: g[i]) {
      if (v == p) continue;
      depth[v] = depth[i]+1;
      self(self,v,i);
    }
  };
  dfs(dfs,1,-1);
  for(int i = 1; i <= n*2+1; i++) cout << depth[i] << endl;
  return 0;
}