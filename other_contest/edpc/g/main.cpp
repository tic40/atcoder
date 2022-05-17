#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

vector<int> memo; // [i] = iを始点としたときの最長パス長
vector<vector<int>> g;

int f(int x) {
  if (0 <= memo[x]) return memo[x];
  int res = 0;
  for(int v: g[x]) res = max(res, f(v)+1);
  return memo[x] = res;
}

int main() {
  int n,m; cin >> n >> m;
  g.resize(n); memo.resize(n,-1);
  REP(i,m) {
    int x,y; cin >> x >> y;
    x--; y--;
    g[x].push_back(y);
  }

  int ans = 0;
  REP(i,n) ans = max(ans, f(i));
  cout << ans << endl;

  return 0;
}
