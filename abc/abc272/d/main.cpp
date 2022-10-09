#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using P = pair<int,int>;
const int INF = 1e9;

int n,m;
vector dist(400,vector<int>(400,INF));
vector<P> moves;

void bfs() {
  queue<P> q;
  q.emplace(0,0);
  dist[0][0] = 0;

  while(q.size()) {
    auto [x,y] = q.front(); q.pop();
    int nd = dist[x][y] + 1;
    for(auto [i,j]: moves) {
      int nx = x+i, ny = y+j;
      if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
      if (nd < dist[nx][ny]) {
        dist[nx][ny] = nd;
        q.emplace(nx,ny);
      }
    }
  }
  return;
}

int main() {
  cin >> n >> m;
  REP(i,n) REP(j,n) {
    if (i*i+j*j == m) {
      moves.emplace_back(i,j);
      moves.emplace_back(-i,-j);
      if (i != 0) moves.emplace_back(-i,j);
      if (j != 0) moves.emplace_back(i,-j);
    }
  }

  bfs();
  REP(i,n) {
    REP(j,n) cout << (dist[i][j] == INF ? -1 : dist[i][j]) << " ";
    cout << endl;
  }
  return 0;
}