#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

const vector<pair<int, int>> moves = { {-1,0},{0,1},{1,0},{0,-1} };

int main() {
  int h,w; cin >> h >> w;
  vector<string> s(h);
  REP(i,h) cin >> s[i];

  vector t(h,vector<int>(w)); // t[i][j] := i,j の上下左右いずれかに磁石があるマス
  REP(i,h) REP(j,w) for(auto [di,dj]: moves) {
    int ni = i+di, nj = j+dj;
    if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
    if (s[ni][nj] == '#') t[i][j] = 1;
  }

  vector visited(h,vector<int>(w));
  auto bfs = [&](int i, int j, int id) -> int {
    if (s[i][j] == '#' || visited[i][j]) return 0;
    int res = 0;
    queue<P> q;
    q.emplace(i,j);

    while(q.size()) {
      auto [x,y] = q.front(); q.pop();
      if (visited[x][y] == id) continue;
      visited[x][y] = id;
      res++;
      if (t[x][y]) continue;

      for(auto [di,dj]: moves) {
        int ni = x+di, nj = y+dj;
        if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
        if (s[ni][nj] == '#') continue;
        q.emplace(ni,nj);
      }
    }
    return res;
  };

  int ans = 0;
  REP(i,h) REP(j,w) ans = max(ans,bfs(i,j,i*w+j+1));
  cout << ans << endl;
  return 0;
}