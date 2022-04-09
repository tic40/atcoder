#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9+5;

using P = pair<int, tuple<int,int,int>>;
vector<pair<int,int>> m = { {1,1}, {1,-1}, {-1,-1}, {-1,1} };
int dist[1500][1500][5];

int main() {
  int n, ax,ay,bx,by;
  cin >> n >> ax >> ay >> bx >> by;
  ax--; ay--; bx--; by--;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  REP(i,1500) REP(j,1500) REP(k,5) dist[i][j][k] = INF;
  priority_queue<P, vector<P>, greater<P>> q;
  q.push({0, {ax,ay,0}});
  dist[ax][ay][0] = 0;

  while(q.size()) {
    auto [d,p] = q.top(); q.pop();
    auto [x,y,dir] = p;
    if (x == bx && y == by) continue;

    REP(i,4) {
      int nx = x+m[i].first;
      int ny = y+m[i].second;
      int ndir = i+1;
      int nd = d + (dir != ndir);

      if (nx < 0 || n <= nx) continue;
      if (ny < 0 || n <= ny) continue;
      if (s[nx][ny] == '#') continue;
      if (dist[nx][ny][ndir] <= nd) continue;

      dist[nx][ny][ndir] = nd;
      q.push({nd, {nx,ny,ndir}});
    }
  }

  int ans = INF;
  REP(i,5) ans = min(ans,dist[bx][by][i]);
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}