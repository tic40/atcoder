#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<int>());
  vector<int> deg(n);
  REP(i,m) {
    int x,y; cin >> x >> y;
    x--; y--;
    g[x].push_back(y);
    deg[y]++;
  }

  vector<int> memo(n,-1);
  auto dfs = [&](auto self, int i) {
    if (memo[i] != -1) return memo[i];
    int res = 0;
    for(auto v: g[i]) res = max(res,self(self,v)+1);
    return memo[i] = res;
  };

  int ans = 0;
  REP(i,n) if (deg[i] == 0) ans = max(ans,dfs(dfs,i));
  cout << ans << endl;
  return 0;
}