#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const vector<int> di = {0,0,1,-1};
const vector<int> dj = {1,-1,0,0};

int main() {
  int h,w,k; cin >> h >> w >> k;
  vector<string> s(h);
  REP(i,h) cin >> s[i];
  int ans = 0;

  vector used(h,vector<int>(w));
  auto dfs = [&](auto self, int x, int y, int cnt) {
    if (cnt == k) { ans++; return; }
    REP(i,4) {
      int ni = di[i]+x, nj = dj[i]+y;
      if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      if (s[ni][nj] == '#') continue;
      if (used[ni][nj]) continue;
      used[ni][nj] = 1;
      self(self,ni,nj,cnt+1);
      used[ni][nj] = 0;
    }
  };

  REP(i,h) REP(j,w) if (s[i][j] == '.') {
    used = vector(h,vector<int>(w));
    used[i][j] = 1;
    dfs(dfs,i,j,0);
  }
  cout << ans << endl;
  return 0;
}