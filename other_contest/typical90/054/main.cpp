#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
const int INF = 1e9;

int main() {
  int n,m; cin >> n >> m;
  vector<vector<int>> g(n+m);
  REP(i,m) {
    int k; cin >> k;
    REP(j,k) {
      int x; cin >> x;
      x--;
      g[x].push_back(n+i);
      g[n+i].push_back(x);
    }
  }

  queue<int> q;
  q.push(0);
  vector<int> dist(n+m,INF);
  dist[0] = 0;

  while(q.size()) {
    int v = q.front(); q.pop();
    for(int nv: g[v]) {
      int nd = dist[v]+1;
      if (nd < dist[nv]) {
        q.push(nv);
        dist[nv] = nd;
      }
    }
  }

  REP(i,n) {
    if (dist[i] == INF) cout << -1 << endl;
    else cout << dist[i]/2 << endl;
  }
  return 0;
}