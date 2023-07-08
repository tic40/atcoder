#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<int>());
  for(int i = 1; i < n; i++) {
    int p; cin >> p; p--;
    g[p].push_back(i);
  }

  vector<int> d(n);
  REP(i,m) {
    int x,y; cin >> x >> y; x--;
    d[x] = max(d[x],y);
  }

  auto dfs = [&](auto self, int i, int p) -> int {
    int res = 0;
    if (p > 0 || d[i] > 0) res++;
    int np = max(p-1,d[i]);
    for(auto v: g[i]) res += self(self,v,np);
    return res;
  };

  cout << dfs(dfs,0,0) << endl;
  return 0;
}