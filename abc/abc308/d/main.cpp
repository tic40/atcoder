#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

const vector<pair<int, int>> moves = { {1,0},{0,1},{-1,0},{0,-1} };
const string target = "snuke";
const int sz = 5;

int main() {
  int h,w; cin >> h >> w;
  vector<string> s(h);
  REP(i,h) cin >> s[i];

  vector visited(h,vector<bool>(w));
  auto dfs = [&](auto self, int x, int y, int i) -> void {
    if (s[x][y] != target[i % sz]) return;
    if (x == h-1 && y == w-1) { cout << "Yes" << endl; exit(0); }

    visited[x][y] = true;
    for(auto [dx,dy]: moves) {
      int nx = x + dx, ny = y + dy;
      if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
      if (visited[nx][ny]) continue;
      self(self,nx,ny,i+1);
    }
  };

  dfs(dfs,0,0,0);
  cout << "No" << endl;
  return 0;
}