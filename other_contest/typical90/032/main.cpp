#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

int main() {
  int n; cin >> n;
  vector a(n,vector<int>(n));
  REP(i,n) REP(j,n) cin >> a[i][j];
  int m; cin >> m;
  vector g(n,vector<int>(n));
  REP(i,m) {
    int x,y; cin >> x >> y;
    x--; y--;
    g[x][y] = g[y][x] = true;
  }

  int ans = INF;
  vector<int> b(n);
  iota(b.begin(),b.end(), 0);
  do {
    int now = a[b[0]][0];
    for(int i = 1; i < n; i++) {
      if (g[b[i-1]][b[i]]) { now = INF; break; }
      now += a[b[i]][i];
    }
    ans = min(ans,now);
  } while (next_permutation(b.begin(), b.end()));

  cout << (ans == INF ? -1 : ans) << endl;
  return 0;
}