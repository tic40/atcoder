#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<ll,ll>;
const int INF = 1e9;

struct Edge {
  int to, cost;
  Edge(int to, int cost): to(to), cost(cost) {}
};

/*
 @param int s 開始位置
 @param vector<vector<Edge>> g 隣接リスト
 @return vector<ll> dist 開始位置からの最短距離
*/
vector<ll> dijkstra(int s, vector<vector<Edge>> &g) {
  vector<ll> dist(g.size(), INF);
  priority_queue<P, vector<P>, greater<P>> q;

  auto push = [&](ll cost, ll to) {
    if (dist[to] <= cost) return;
    dist[to] = cost;
    q.emplace(dist[to], to);
  };

  push(0, s);
  while (q.size()) {
    auto [cost,v] = q.top(); q.pop();
    if (dist[v] != cost) continue;
    for (Edge e: g[v]) push(dist[v]+e.cost, e.to);
  }
  return dist;
}

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<Edge>());
  REP(i,m) {
    int a,b,c; cin >> a >> b >> c;
    a--; b--;
    g[a].emplace_back(b,c);
    g[b].emplace_back(a,c);
  }
  auto d1 = dijkstra(0,g);
  auto dn = dijkstra(n-1,g);

  int ans = 0;
  REP(i,n) if (d1[i] + dn[i] == d1[n-1]) ans++;
  cout << ans << endl;
  return 0;
}