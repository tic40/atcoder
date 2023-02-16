#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();

void solve() {
  int n,m; cin >> n >> m;
  vector<int> c(n);
  REP(i,n) cin >> c[i];
  vector<vector<int>> g(n);
  REP(i,m) {
    int u,v; cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector dist(n,vector<int>(n,INF));
  queue<P> q;
  auto push = [&](int i, int j, int d) {
    if (dist[i][j] != INF) return;
    dist[i][j] = d;
    q.emplace(i,j);
  };

  push(0,n-1,0);
  while(q.size()) {
    auto [a,b] = q.front(); q.pop();
    int d = dist[a][b];
    for(int na: g[a]) for(int nb: g[b]) {
      if (c[na] == c[nb]) continue;
      push(na,nb,d+1);
    }
  }

  int ans = dist[n-1][0];
  cout << (ans == INF ? -1 : ans) << endl;
  return ;
}

int main() {
  int t; cin >> t;
  REP(_,t) solve();
  return 0;
}