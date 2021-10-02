#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
const int INF = 1e9;

int h,w;
int sx,sy,gx,gy;
vector<string> s(10);
vector<vector<int>> dist(10,vector<int>(10, INF));
vector<pair<int,int>> m = { {1,0}, {-1,0}, {0,1}, {0,-1} };

void dfs(int x, int y) {
  for(auto v: m) {
    int nx = x+v.first;
    int ny = y+v.second;
    if (nx < 0 || ny < 0) continue;
    if (h <= nx || w <= ny) continue;
    if (s[nx][ny] == 'B') continue;
    int nd = dist[x][y]+1;
    if (nd < dist[nx][ny]) {
      dist[nx][ny] = nd;
      dfs(nx,ny);
    }
  }

  return;
}

int main() {
  cin >> h >> w;
  cin >> sx >> sy >> gx >> gy;
  REP(i,h) cin >> s[i];

  dist[sx][sy]=0;
  dfs(sx,sy);
  cout << dist[gx][gy] << endl;
  return 0;
}