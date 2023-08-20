#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector g(n,vector<int>());
  REP(i,n) {
    int c; cin >> c;
    g[i].resize(c);
    REP(j,c) {
      cin >> g[i][j];
      g[i][j]--;
    }
  }

  vector<int> ans, visited(n);
  auto dfs = [&](auto self, int i) {
    if (visited[i]) return;
    visited[i] = true;
    for(auto v: g[i]) self(self,v);
    ans.push_back(i);
  };

  dfs(dfs,0);
  ans.pop_back();
  for(auto v: ans) cout << v+1 << " ";
  return 0;
}