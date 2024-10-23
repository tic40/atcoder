#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  vector g(n+1,vector<int>());
  REP(_,q) {
    int l,r; cin >> l >> r; l--;
    g[l].push_back(r);
    g[r].push_back(l);
  }

  vector<int> visited(n+1);
  auto dfs = [&](auto self, int i) {
    if (i == n) return true;
    visited[i] = true;
    bool res = false;
    for(auto v: g[i]) if (!visited[v]) {
      res = res || self(self,v);
    }
    return res;
  };
  cout << (dfs(dfs,0) ? "Yes" : "No") << endl;;
  return 0;
}