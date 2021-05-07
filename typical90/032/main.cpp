#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
const int INF = 1e9;

int n,m, a[10][10];
vector<int> x,y;
vector<bool> used;
vector<vector<int>> g;
int ans = INF;

void dfs(int num, int prev, int tot) {
  if (ans <= tot) return;
  if (num == n) {
    ans = min(ans, tot);
    return;
  }

  REP(i,n) {
    if (used[i]) continue;
    if (prev != -1) {
      bool ok = true;
      for(int x: g[prev]) if (x == i) ok = false;
      if (!ok) continue;
    }
    used[i] = true;
    dfs(num+1, i, tot+a[i][num]);
    used[i] = false;
  }
  return;
}

void solve() {
  used.resize(n,false);
  REP(i,n) dfs(0, -1, 0);

  if (ans == INF) ans = -1;
  cout << ans << endl;
  return;
}

int main() {
  cin >> n;
  REP(i,n) REP(j,n) cin >> a[i][j];
  cin >> m;

  g.resize(n);
  int x,y;
  REP(i,m) {
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  solve();
  return 0;
}