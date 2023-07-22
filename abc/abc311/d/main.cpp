#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

const vector<pair<int,int>> moves = { {-1,0}, {0,1}, {1,0}, {0,-1} };

int main() {
  int n,m; cin >> n >> m;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  // [i][j][k] := i,j マスで k 方向 への移動を試したかどうか
  vector seen(n,vector(m,vector<bool>(4)));
  // [i][j] := i,j マスを通過したかどうか
  vector visited(n,vector<int>(m));

  auto dfs = [&](auto self, int x, int y) -> void {
    REP(k,4) {
      if (seen[x][y][k]) continue;
      seen[x][y][k] = true;
      auto [dx,dy] = moves[k];
      int nx = x, ny = y;
      // 岩にぶつかるまで進む
      while(s[nx+dx][ny+dy] == '.') {
        nx += dx; ny += dy;
        visited[nx][ny] = 1;
      }
      self(self,nx,ny);
    }
  };

  visited[1][1] = true;
  dfs(dfs,1,1);
  int ans = 0;
  REP(i,n) REP(j,m) ans += visited[i][j];
  cout << ans << endl;
  return 0;
}