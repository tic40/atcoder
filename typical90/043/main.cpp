#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int h,w;
int sy,sx,gy,gx;
vector<string> s;
vector<pair<int, int>> moves = { {1,0},{0,1},{-1,0},{0,-1} };

int dist[1005][1005][4];
struct State {
  int y, x, dir;
};

void bfs() {
  REP(i,h) REP(j,w) REP(k,4) dist[i][j][k] = INF;
  queue<State> q;

  REP(i,4) {
    dist[sy][sx][i] = 0;
    q.push({ sy, sx, i });
  }

  while(q.size()) {
    auto state = q.front(); q.pop();
    REP(i,4) {
      auto move = moves[i];
      int ny = state.y + move.first;
      int nx = state.x + move.second;
      int cost = dist[state.y][state.x][state.dir] + (state.dir != i ? 1 : 0);
      if (ny < 0 || h <= ny || nx < 0 || w <= nx) continue;
      if (s[ny][nx] == '#') continue;
      if (dist[ny][nx][i] <= cost) continue;

      dist[ny][nx][i] = cost;
      q.push({ ny, nx, i });
    }
  }
  return;
}

int main() {
  cin >> h >> w;
  cin >> sy >> sx;
  cin >> gy >> gx;
  sy--,sx--,gy--,gx--;

  s.resize(h);
  REP(i,h) cin >> s[i];

  bfs();

  int ans = INF;
  REP(i,4) ans = min(ans, dist[gy][gx][i]);
  cout << ans << endl;
  return 0;
}