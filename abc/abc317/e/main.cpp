#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();

int main() {
  int h,w; cin >> h >> w;
  vector<string> a(h);
  REP(i,h) cin >> a[i];

  P s = {0,0};
  P g = {0,0};
  REP(i,h) REP(j,w) {
    char t = a[i][j];
    if (t == 'S') s = {i,j};
    if (t == 'G') g = {i,j};
    if (t == '^') {
      REP(k,h) {
        int ni = i-k-1;
        if (ni < 0) break;
        if (a[ni][j] != '.' && a[ni][j] != 'x') break;
        a[ni][j] = 'x';
      }
    }
    if (t == '>') {
      REP(k,w) {
        int nj = j+k+1;
        if (nj >= w) break;
        if (a[i][nj] != '.' && a[i][nj] != 'x') break;
        a[i][nj] = 'x';
      }
    }
    if (t == '<') {
      REP(k,w) {
        int nj = j-k-1;
        if (nj < 0) break;
        if (a[i][nj] != '.' && a[i][nj] != 'x') break;
        a[i][nj] = 'x';
      }
    }
    if (t == 'v') {
      REP(k,h) {
        int ni = i+k+1;
        if (ni >= h) break;
        if (a[ni][j] != '.' && a[ni][j] != 'x') break;
        a[ni][j] = 'x';
      }
    }
  }

  const vector<pair<int, int>> moves = { {1,0},{0,1},{-1,0},{0,-1} };

  auto bfs = [&]() {
    vector dist(h,vector<int>(w, INF));
    queue<P> q;
    q.push(s);
    dist[s.first][s.second] = 0;
    while(q.size()) {
      auto [x,y] = q.front();
      q.pop();
      for(auto [dx,dy]: moves) {
        int nx = x+dx;
        int ny = y+dy;
        if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
        if (a[nx][ny] != '.' && a[nx][ny] != 'G') continue;
        int ndist = dist[x][y]+1;
        if (dist[nx][ny] <= ndist) continue;
        dist[nx][ny] = ndist;
        q.emplace(nx,ny);
      }
    }
    return dist;
  };

  auto dist = bfs();
  int ans = dist[g.first][g.second];
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}