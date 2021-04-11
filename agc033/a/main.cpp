#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int h,w;
vector<string> a;
const vector<pair<int,int>> moves = { {1,0},{-1,0},{0,1},{0,-1} };

void solve() {
  int dist[h][w];
  REP(i,h) REP(j,w) dist[i][j]=-1;

  queue<pair<int,int>> q;

  REP(i,h) REP(j,w) {
    if (a[i][j]=='#') {
      dist[i][j]=0;
      q.push({i,j});
    }
  }

  while(q.size()) {
    auto v = q.front(); q.pop();
    int ci = v.first, cj = v.second;

    for(auto v: moves) {
      int ni = ci+v.first, nj = cj+v.second;
      if (0 <= ni && ni < h && 0 <= nj && nj < w) {
        if (dist[ni][nj] == -1) {
          dist[ni][nj] = max(dist[ci][cj]+1, dist[ni][nj]);
          q.push({ni, nj});
        }
      }
    }
  }

  int ans = 0;
  REP(i,h) REP(j,w) ans = max(ans,dist[i][j]);

  cout << ans << endl;
  return ;
}

int main() {
  cin >> h >> w;
  a.resize(h);
  REP(i,h) cin >> a[i];

  solve();
  return 0;
}