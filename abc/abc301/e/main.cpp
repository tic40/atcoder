#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
const int INF = 1e9;
template<class T> void chmin(T& a, T b) { a = min(a,b); }
template<class T> void chmax(T& a, T b) { a = max(a,b); }

const vector<P> moves = { { 1,0 }, { -1,0 }, { 0,1 }, { 0,-1 } };
int main() {
  int h,w,t; cin >> h >> w >> t;
  vector<string> a(h);
  REP(i,h) cin >> a[i];
  vector<P> ps;
  REP(i,h) REP(j,w) if (a[i][j] == 'o') ps.emplace_back(i,j);
  REP(i,h) REP(j,w) if (a[i][j] == 'S') ps.emplace_back(i,j);
  REP(i,h) REP(j,w) if (a[i][j] == 'G') ps.emplace_back(i,j);

  int n = ps.size() - 2;
  vector dist(n+2, vector<int>(n+2,INF));

  auto bfs = [&](int i, int j) {
    vector d(h, vector<int>(w,INF));
    queue<P> q;
    d[i][j] = 0;
    q.emplace(i,j);
    while(q.size()) {
      auto [i,j] = q.front(); q.pop();
      for(auto [di,dj]: moves) {
        int ni = i+di, nj = j+dj;
        if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
        if (a[ni][nj] == '#') continue;
        if (d[ni][nj] != INF) continue;
        d[ni][nj] = d[i][j]+1;
        q.emplace(ni,nj);
      }
    }
    return d;
  };

  REP(si,n+2) {
    auto [i,j] = ps[si];
    auto d = bfs(i,j);
    REP(ti,n+2) {
      auto [i,j] = ps[ti];
      dist[si][ti] = d[i][j];
    }
  }

  int sv = n, tv = n+1;
  int n2 = 1<<n;
  // dp[i][j] := 集合 i を訪問済みで今いる場所が j のときに訪れているときの最小の移動回数
  vector dp(n2,vector<int>(n,INF));
  REP(i,n) dp[1<<i][i] = dist[sv][i];
  REP(s,n2) REP(v,n) {
    if (dp[s][v] == INF) continue;
    REP(u,n) {
      if (s >> u & 1) continue;
      chmin(dp[s|1<<u][u], dp[s][v] + dist[v][u]);
    }
  }

  if (dist[sv][tv] > t) { cout << -1 << endl; return 0; }
  int ans = 0;
  REP(s,n2) REP(v,n) {
    if (dp[s][v] + dist[v][tv] > t) continue;
    chmax(ans, __builtin_popcount(s));
  }
  cout << ans << endl;
  return 0;
}