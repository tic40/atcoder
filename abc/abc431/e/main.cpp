#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using T = tuple<int,int,int,int>;
const int INF = numeric_limits<int>::max();
const vector<int> di = {-1,0,1,0};
const vector<int> dj = {0,1,0,-1};

void solve() {
  int h,w; cin >> h >> w;
  vector<string> s(h);
  REP(i,h) cin >> s[i];

  vector dist(h,vector(w,vector(4,INF)));
  priority_queue<T, vector<T>, greater<T>> q;

  q.emplace(0,0,0,1);
  dist[0][0][1] = 0;

  int ans = INF;
  while(q.size()) {
    auto [d,i,j,dir] = q.top(); q.pop();
    if (dist[i][j][dir] < d) continue;

    auto push = [&](int ni, int nj, int nd, int ndir) -> void {
      if (ni == h-1 && nj == w) {
        ans = min(ans,nd);
        return;
      }
      if (ni < 0 || nj < 0 || ni >= h || nj >= w) return;
      if (dist[ni][nj][ndir] <= nd) return;
      dist[ni][nj][ndir] = nd;
      q.emplace(nd,ni,nj,ndir);
    };

    REP(k,3) {
      char nt = char('A' + k);
      int nd = d + (s[i][j] == nt ? 0 : 1);
      int ndir = dir;
      if (nt == 'B') {
        if (dir == 0) ndir = 3;
        if (dir == 1) ndir = 2;
        if (dir == 2) ndir = 1;
        if (dir == 3) ndir = 0;
      }
      if (nt == 'C') {
        if (dir == 0) ndir = 1;
        if (dir == 1) ndir = 0;
        if (dir == 2) ndir = 3;
        if (dir == 3) ndir = 2;
      }
      push(i+di[ndir], j+dj[ndir], nd, ndir);
    }
  }
  cout << ans << endl;
}

int main() {
  int t; cin >> t;
  REP(_,t) solve();
  return 0;
}