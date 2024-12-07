#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using T = tuple<int,int,int>;
const vector<pair<int, int>> moves = { {-1,0},{0,1},{1,0},{0,-1} };

int main() {
  int h,w,d; cin >> h >> w >> d;
  vector<string> s(h);
  REP(i,h) cin >> s[i];

  vector dist(h,vector<int>(w,-1));
  priority_queue<T, vector<T>, less<T>> q;
  REP(i,h) REP(j,w) if (s[i][j] == 'H') {
    q.emplace(d,i,j);
    dist[i][j] = d;
  }

  while(q.size()) {
    auto [nd,i,j] = q.top(); q.pop();
    if (dist[i][j] > nd) continue;
    if (nd == 0) continue;
    for(auto [di,dj]: moves) {
      int ni = i+di;
      int nj = j+dj;
      if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      if (s[ni][nj] != '.') continue;
      if (dist[ni][nj] >= nd-1) continue;
      dist[ni][nj] = nd-1;
      q.emplace(nd-1,ni,nj);
    }
  }

  int ans = 0;
  REP(i,h) REP(j,w) if (dist[i][j] != -1) ans++;
  cout << ans << endl;
  return 0;
}