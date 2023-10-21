#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

const vector<P> moves = {
  {-1,-1}, {-1,0}, {-1,1},
  {0,-1}, {0,1},
  {1,-1}, {1,0}, {1,1}
};

int main() {
  int h,w; cin >> h >> w;
  vector<string> s(h);
  REP(i,h) cin >> s[i];

  vector visited(h,vector<bool>(w));
  auto dfs = [&](auto self, int i, int j) -> void {
    if (visited[i][j]) return;
    visited[i][j] = true;

    for(auto [di,dj]: moves) {
      int ni = i+di, nj = j+dj;
      if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      if (s[ni][nj] == '.') continue;
      self(self,ni,nj);
    }
    return;
  };

  int ans = 0;
  REP(i,h) REP(j,w) {
    if (s[i][j] == '.' || visited[i][j]) continue;
    dfs(dfs,i,j);
    ans++;
  }

  cout << ans << endl;
  return 0;
}