#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();

int main() {
  int h,w; cin >> h >> w;
  vector<string> a(h);
  REP(i,h) cin >> a[i];

  auto update = [&](int i, int j, int di, int dj) -> void {
    while(1) {
      i += di; j += dj;
      if (i < 0 || j < 0 || i >= h || j >= w) return;
      char t = a[i][j];
      bool ok = t == '.' || t == '_';
      if (!ok) return;
      a[i][j] = '_';
    }
  };

  P s,g;
  REP(i,h) REP(j,w) {
    char t = a[i][j];
    if (t == 'S') s = {i,j};
    if (t == 'G') g = {i,j};
    if (t == '^') update(i,j,-1,0);
    if (t == 'v') update(i,j,1,0);
    if (t == '>') update(i,j,0,1);
    if (t == '<') update(i,j,0,-1);
  }

  const vector<P> moves = { {1,0}, {-1,0}, {0,1}, {0,-1} };
  vector dist(h,vector<int>(w,INF));
  queue<P> q;
  q.emplace(s);
  dist[s.first][s.second] = 0;
  while(q.size()) {
    auto [i,j] = q.front();
    q.pop();
    for(auto [di,dj]: moves) {
      int ni = i+di, nj = j+dj;
      if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      char t = a[ni][nj];
      bool ok = t == '.' || t == 'G';
      if (!ok) continue;
      int ndist = dist[i][j]+1;
      if (dist[ni][nj] <= ndist) continue;
      dist[ni][nj] = ndist;
      q.emplace(ni,nj);
    }
  }

  int ans = dist[g.first][g.second];
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}