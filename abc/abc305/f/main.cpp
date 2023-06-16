#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;

  auto get = [&]() -> vector<int> {
    int k; cin >> k;
    vector<int> res(k);
    REP(i,k) cin >> res[i];
    return res;
  };

  vector<bool> visited(n+1);
  auto dfs = [&](auto self, int now) -> bool {
    if (now == n) return true;
    visited[now] = true;
    auto to = get();
    for(int v: to) {
      if (visited[v]) continue;
      cout << v << endl;
      if (self(self,v)) return true;
      cout << now << endl;
      get();
    }
    return false;
  };

  dfs(dfs,1);
  return 0;
}