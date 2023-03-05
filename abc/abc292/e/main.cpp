#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const int INF = numeric_limits<int>::max();

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<int>());
  REP(i,m) {
    int u,v; cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
  }

  auto bfs = [&](int s) {
    queue<int> q;
    vector<int> dist(n,INF);
    auto push = [&](int i, int d) {
      if (d >= dist[i]) return;
      dist[i] = d;
      q.push(i);
    };

    push(s,0);
    while(q.size()) {
      int v = q.front(); q.pop();
      int nd = dist[v]+1;
      for(int nv: g[v]) push(nv,nd);
    }
    return dist;
  };

  ll ans = 0;
  REP(i,n) {
    auto dist = bfs(i);
    for(auto v: dist) if (v >= 2 && v != INF) ans++;
  }
  cout << ans << endl;
  return 0;
}