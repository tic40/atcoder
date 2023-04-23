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

  vector dist(n, vector<int>(n,INF));
  REP(i,n) {
    queue<int> q;
    q.push(i);
    dist[i][i] = 0;
    while(q.size()) {
      int now = q.front(); q.pop();
      int nd = dist[i][now]+1;
      for(int v: g[now]) {
        if (dist[i][v] <= nd) continue;
        dist[i][v] = nd;
        q.push(v);
      }
    }
  }

  int k; cin >> k;
  vector<int> p(k),d(k);
  REP(i,k) { cin >> p[i] >> d[i]; p[i]--; }

  // 0: 白, 1: 黒
  vector<int> col(n,1);
  REP(i,k) REP(j,n) {
    if (dist[ p[i] ][j] < d[i]) col[j] = 0;
  }

  bool ok = true;
  REP(i,k) {
    int mind = INF;
    REP(j,n) if (col[j] == 1) mind = min(mind, dist[ p[i] ][j]);
    if (mind != d[i]) ok = false;
  }

  if (!ok) cout << "No" << endl;
  else {
    cout << "Yes" << endl;
    REP(i,n) cout << col[i];
  }
  return 0;
}