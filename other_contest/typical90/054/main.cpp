#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9;

int main() {
  int n,m; cin >> n >> m;
  vector<vector<int>> g(n+m);
  REP(i,m) {
    int k; cin >> k;
    REP(j,k) {
      int v; cin >> v;
      v--;
      g[v].push_back(n+i);
      g[n+i].push_back(v);
    }
  }

  queue<int> q({0});
  vector<int> dist(n+m,INF);
  dist[0] = 0;

  while(q.size()) {
    int now = q.front(); q.pop();
    int nd = dist[now]+1;
    for(int v: g[now]) {
      if (nd < dist[v]) {
        q.push(v);
        dist[v] = nd;
      }
    }
  }

  REP(i,n) cout << (dist[i] == INF ? -1 : dist[i]/2) << endl;
  return 0;
}