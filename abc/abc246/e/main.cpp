#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9+5;
using M = tuple<int,int,int>;
using P = pair<int, M>;

int n,ax,ay,bx,by;
vector<string> s(1505);
int dist[1505][1505][5];
vector<pair<int,int>> moves = {{1,1},{1,-1},{-1,-1},{-1,1}};

void solve() {
  REP(i,1500) REP(j,1500) REP(k,5) dist[i][j][k] = INF;
  priority_queue<P, vector<P>, greater<P>> q;
  q.push({ 0, {ax, ay, 0} });
  dist[ax][ay][0] = 0;

  auto push = [&](M from, M to) {
    auto [x,y,d] = from;
    auto [nx,ny,nd] = to;
    if (nx < 0 || n <= nx) return;
    if (ny < 0 || n <= ny) return;
    if (s[nx][ny] == '#') return;

    int c = dist[x][y][d] + (d != nd ? 1 : 0);
    if (dist[nx][ny][nd] <= c) return;

    dist[nx][ny][nd] = c;
    q.push({ c, to });
  };

  while(q.size()) {
    auto [d,from] = q.top(); q.pop();
    auto [x,y,dir] = from;
    REP(i,4) push(from, { x+moves[i].first, y+moves[i].second, i+1 });
  }

  int ans = INF;
  REP(i,5) ans = min(ans, dist[bx][by][i]);
  if (ans == INF) ans = -1;
  cout << ans << endl;

  return;
}

int main() {
  cin >> n >> ax >> ay >> bx >> by;
  ax--, ay--, bx--, by--;
  REP(i,n) cin >> s[i];
  solve();
  return 0;
}