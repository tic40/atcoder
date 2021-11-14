#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
const int INF = 1e9;
using P = pair<int,int>;

const int base = 205;
const int ma = 500;
int n,x,y;
vector<vector<int>> d(ma,vector<int>(ma,INF));
map<pair<int,int>,bool> block;

const vector<pair<int,int>> m = {
  { 1, 1 },
  { 0, 1 },
  { -1, 1 },
  { 1, 0 },
  { -1, 0 },
  { 0, -1 }
};

int main() {
  cin >> n >> x >> y;
  x += base; y += base;

  REP(i,n) {
    int _x,_y; cin >> _x >> _y;
    _x += base;
    _y += base;
    block[P(_x,_y)] = true;
  }

  queue<P> q;
  q.push({ base,base });
  d[base][base] = 0;

  while(q.size()) {
    auto [cx, cy] = q.front(); q.pop();
    int nd = d[cx][cy] + 1;
    for(auto [mx,my]: m) {
      int nx = cx+mx, ny = cy+my;
      // range
      if (nx < 0 || ny < 0 || ma <= nx || ma <= ny) continue;
      // block
      if (block[P(nx,ny)]) continue;
      // visited
      if (d[nx][ny] <= nd) continue;
      d[nx][ny] = nd;
      q.push(P(nx,ny));
    }
  }

  int ans = d[x][y];
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}