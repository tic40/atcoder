#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

int main() {
  int n; cin >> n;
  vector a(n,vector<int>(n));
  REP(i,n) REP(j,n) cin >> a[i][j];
  int m; cin >> m;
  vector g(n,set<int>());
  REP(_,m) {
    int x,y; cin >> x >> y;
    x--; y--;
    g[x].insert(y);
    g[y].insert(x);
  }

  auto dfs = [&](auto self, int p, int total, int s) {
    int now = __builtin_popcount(s);
    if (now == n) return total;

    int ans = INF;
    REP(i,n) {
      if ((s >> i & 1)) continue;
      if (g[i].count(p)) continue;
      ans = min(ans, self(self,i,total+a[i][now], (s|1<<i)));
    }
    return ans;
  };

  int ans = dfs(dfs,-1,0,0);
  cout << (ans == INF ? -1 : ans) << endl;
  return 0;
}