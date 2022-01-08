#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int h,w;
vector<string> s;
vector<pair<int, int>> moves = { {1,0},{0,1},{-1,0},{0,-1} };
int visited[16][16];
int ans = 0;
int sx, sy;

void dfs(int x, int y) {
  if (x == sx && y == sy && visited[x][y] > 0) {
    ans = max(ans, visited[x][y]);
    return;
  }

  for(auto v: moves) {
    int nx = x + v.first;
    int ny = y + v.second;
    if (visited[nx][ny] > 0) continue;
    if (nx < 0 || ny < 0 || h <= nx || w <= ny) continue;
    if (s[nx][ny] == '#') continue;

    visited[nx][ny] = visited[x][y]+1;
    dfs(nx,ny);
  }
  return;
}

void solve() {
  REP(i,h) REP(j,w) {
    REP(_i, h) REP(_j, w) visited[_i][_j] = 0;
    if (s[i][j] == '#') continue;
    sx = i; sy = j;
    dfs(sx, sy);
  }

  if (ans < 3) ans = -1;
  cout << ans << endl;
  return;
}

int main() {
  cin >> h >> w;
  s.resize(h);
  REP(i,h) cin >> s[i];

  solve();
  return 0;
}