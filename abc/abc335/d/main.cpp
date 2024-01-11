#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector g(n,vector<int> (n,0));
  auto dfs = [&](auto self, int i, int j, P dir, int cnt) -> void {
    g[i][j] = cnt;
    int ni = i+dir.first;
    int nj = j+dir.second;
    bool ng = (ni < 0 || nj < 0 || ni >= n || nj >= n);
    ng = ng || (g[ni][nj] != 0);
    if (!ng) {
      self(self,ni,nj,dir,cnt+1);
      return;
    }

    // 90度方向転換
    if (dir.first == 1) dir = {0,-1};
    else if (dir.first == -1) dir = {0,1};
    else if (dir.second == 1) dir = {1,0};
    else if (dir.second == -1) dir = {-1,0};
    ni = i+dir.first;
    nj = j+dir.second;
    ng = (ni < 0 || nj < 0 || ni >= n || nj >= n);
    ng = ng || (g[ni][nj] != 0);
    if (!ng) self(self,ni,nj,dir,cnt+1);
    return;
  };
  dfs(dfs,0,0,{0,1},1);

  REP(i,n) {
    REP(j,n) {
      if (i == n/2 && j == n/2) cout << "T" << " ";
      else cout << g[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}