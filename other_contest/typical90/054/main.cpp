#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

int main() {
  int n,m; cin >> n >> m;
  vector g(n+m,vector<int>());
  REP(i,m) {
    int k; cin >> k;
    REP(j,k) {
      int r; cin >> r; r--;
      g[n+i].push_back(r);
      g[r].push_back(n+i);
    }
  }

  auto bfs = [&]() {
    vector<int> dist(n+m,INF);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while(q.size()) {
      int v = q.front(); q.pop();
      for(auto nv: g[v]) {
        if (dist[nv] != INF) continue;
        q.push(nv);
        dist[nv] = dist[v]+1;
      }
    }
    return dist;
  };

  auto dist = bfs();
  REP(i,n) cout << (dist[i] == INF ? -1 : dist[i]/2) << endl;
  return 0;
}