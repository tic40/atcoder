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

  vector<int> cost(n+m,INF);
  queue<int> q({0});
  cost[0] = 0;

  while(q.size()) {
    int now = q.front(); q.pop();
    int nc = cost[now]+1;
    for(int v: g[now]) {
      if (nc < cost[v]) {
        cost[v] = nc;
        q.push(v);
      }
    }
  }

  REP(i,n) {
    if (cost[i] == INF) cout << -1;
    else cout << cost[i]/2;
    cout << endl;
  }
  return 0;
}