#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();
const vector<int> di = {-1,0,1,0};
const vector<int> dj = {0,1,0,-1};

int main() {
  int h,w; cin >> h >> w;
  vector<string> a(h);
  REP(i,h) cin >> a[i];

  vector dist(h,vector(w,vector<int>(2,INF)));
  auto bfs = [&](int x, int y) {
    queue<tuple<int,int,int>> q;
    q.emplace(x,y,0);
    dist[x][y][0] = 0;
    while(q.size()) {
      auto [i,j,t] = q.front(); q.pop();
      if (a[i][j] == 'G') return dist[i][j][t];

      REP(k,4) {
        int ni = i+di[k], nj = j+dj[k];
        if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
        if (a[ni][nj] == '#') continue;
        if (a[ni][nj] == 'o' && t) continue;
        if (a[ni][nj] == 'x' && !t) continue;
        int nt = a[ni][nj] == '?' ? t^1 : t;
        if (dist[ni][nj][nt] <= dist[i][j][t]+1) continue;
        dist[ni][nj][nt] = dist[i][j][t]+1;
        q.emplace(ni,nj,nt);
      }
    }
    return -1;
  };

  REP(i,h) REP(j,w) if (a[i][j] == 'S') cout << bfs(i,j) << endl;
  return 0;
}