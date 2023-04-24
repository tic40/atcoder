#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<int>());
  REP(i,m) {
    int u,v; cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int k; cin >> k;
  vector<int> p(k),d(k);
  REP(i,k) { cin >> p[i] >> d[i]; p[i]--; }

  auto bfs = [&](int i) {
    vector<int> dist(n,INF);
    dist[i] = 0;
    queue<int> q;
    q.push(i);
    while(q.size()) {
      int now = q.front(); q.pop();
      int nd = dist[now]+1;
      for(int v: g[now]) {
        if (dist[v] <= nd) continue;
        dist[v] = nd;
        q.push(v);
      }
    }
    return dist;
  };

  vector dist(n,vector<int>(n));
  REP(i,n) dist[i] = bfs(i);

  vector<int> col(n,1);
  REP(i,k) REP(j,n) {
    if (dist[p[i]][j] < d[i]) col[j] = 0;
  }

  bool ok = true;
  REP(i,k) {
    int min_dist = INF;
    REP(j,n) if (col[j]) min_dist = min(min_dist,dist[p[i]][j]);
    if (min_dist != d[i]) ok = false;
  }

  if (!ok) cout << "No" << endl;
  else {
    cout << "Yes" << endl;
    for(int v: col) cout << v;
  }
  return 0;
}