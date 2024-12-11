#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
const vector<int> di = {-1,0,1,0};
const vector<int> dj = {0,1,0,-1};

int main() {
  int h,w,d; cin >> h >> w >> d;
  vector<string> s(h);
  REP(i,h) cin >> s[i];

  vector visited(h,vector<int>(w,-1));
  queue<P> q;
  REP(i,h) REP(j,w) if (s[i][j] == 'H') {
    q.emplace(i,j);
    visited[i][j] = d;
  }

  while(q.size()) {
    auto [x,y] = q.front(); q.pop();
    int nd = visited[x][y];
    REP(i,4) {
      int ni = x+di[i];
      int nj = y+dj[i];
      if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      if (s[ni][nj] == '#') continue;
      if (nd-1 > visited[ni][nj]) {
        visited[ni][nj] = nd-1;
        q.emplace(ni,nj);
      }
    }
  }

  int ans = 0;
  REP(i,h) REP(j,w) if (visited[i][j] >= 0) ans++;
  cout << ans << endl;
  return 0;
}