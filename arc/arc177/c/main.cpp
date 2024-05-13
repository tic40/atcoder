#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
const int INF = numeric_limits<int>::max();

const vector<int> di = {-1,0,1,0};
const vector<int> dj = {0,1,0,-1};

int main() {
  int n; cin >> n;
  vector<string> c(n);
  REP(i,n) cin >> c[i];

  auto bfs = [&](P s, char col) {
    vector dist(n,vector<int>(n,INF));
    priority_queue<PP, vector<PP>, greater<PP>> q;
    q.emplace(0,s);
    dist[s.first][s.second] = 0;
    while(q.size()) {
      auto [cost, p] = q.top(); q.pop();
      auto [x,y] = p;
      if (dist[x][y] < cost) continue;
      REP(i,4) {
        int ni = x+di[i];
        int nj = y+dj[i];
        if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
        int ndist = c[ni][nj] == col ? dist[x][y] : dist[x][y]+1;
        if (dist[ni][nj] <= ndist) continue;
        dist[ni][nj] = ndist;
        q.emplace(ndist, P{ni,nj});
      }
    }
    return dist;
  };

  auto dist1 = bfs({0,0},'R');
  auto dist2 = bfs({0,n-1},'B');
  int ans = dist1[n-1][n-1] + dist2[n-1][0];
  cout << ans << endl;
  return 0;
}