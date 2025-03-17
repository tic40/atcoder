#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
const int INF = 1e9; //numeric_limits<int>::max();
const vector<int> di = {-1,0,1,0};
const vector<int> dj = {0,1,0,-1};
template<class T> void chmin(T& a, T b) { a = min(a,b); }

int main() {
  int h,w,t; cin >> h >> w >> t;
  vector<string> a(h);
  REP(i,h) cin >> a[i];
  vector<P> ps;
  REP(i,h) REP(j,w) if (a[i][j] == 'o') ps.emplace_back(i,j);
  REP(i,h) REP(j,w) if (a[i][j] == 'S') ps.emplace_back(i,j);
  REP(i,h) REP(j,w) if (a[i][j] == 'G') ps.emplace_back(i,j);

  int n = ps.size() - 2;

  auto bfs = [&](int i, int j) {
    vector dist(h,vector<int>(w,INF));
    queue<P> q;
    dist[i][j] = 0;
    q.emplace(i,j);
    while(q.size()) {
      auto [i,j] = q.front(); q.pop();
      REP(k,4) {
        int ni = i+di[k], nj = j+dj[k];
        if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
        if (a[ni][nj] == '#') continue;
        if (dist[ni][nj] != INF) continue;
        dist[ni][nj] = dist[i][j]+1;
        q.emplace(ni,nj);
      }
    }
    return dist;
  };

  // dist[i][j] := お菓子 i からお菓子 j への最短距離
  vector dist(n+2,vector<int>(n+2,INF));
  REP(si,n+2) {
    auto [i,j] = ps[si];
    auto d = bfs(i,j);
    REP(ti,n+2) {
      auto [i,j] = ps[ti];
      dist[si][ti] = d[i][j];
    }
  }

  int start = n, goal = n+1;
  int n2 = 1<<n;
  // dp[bit][i] := 集合 bit のお菓子を訪問済みで今いる場所が i のときに訪れているときの最小の移動回数
  vector dp(n2,vector<int>(n,INF));
  REP(i,n) dp[1<<i][i] = dist[start][i];
  REP(bit,n2) REP(from,n) if (dp[bit][from] != INF) {
    REP(to,n) {
      if (bit >> to & 1) continue;
      chmin(dp[bit|1<<to][to],dp[bit][from] + dist[from][to]);
    }
  }

  if (dist[start][goal] > t) { cout << -1 << endl; return 0; }
  int ans = 0;
  REP(bit,n2) REP(i,n) if (dp[bit][i] + dist[i][goal] <= t) {
    ans = max(ans,__builtin_popcount(bit));
  }
  cout << ans << endl;
  return 0;
}
