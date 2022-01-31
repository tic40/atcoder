#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
using P = pair<int,int>;
const int INF = 1e9;

int n,m;
vector<int> h;
struct Edge { int to; int cost; };
vector<vector<Edge>> g;

// s: スタート位置
vector<int> dijkstra(int s) {
  vector<int> dist(g.size(), INF);
  priority_queue<P, vector<P>, greater<P>> q;

  // cost: toに移動するときのコスト, to: 移動先
  auto push = [&](ll cost, ll to) {
    if (dist[to] <= cost) return;
    dist[to] = cost;
    q.emplace(dist[to], to);
  };

  // スタート位置をコスト0で追加
  push(0, s); // [現在位置のコスト, 現在位置]

  while (q.size()) {
    auto [_,v] = q.top(); q.pop();
    for (Edge e: g[v]) {
      ll cost = dist[v]+e.cost;
      push(cost, e.to);
    }
  }

  return dist;
}

int main() {
  cin >> n >> m;
  h.resize(n);
  g.resize(n);
  REP(i,n) cin >> h[i];
  REP(i,m) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    // 負の辺は扱えないため、いくらコストがかかるかを考える
    g[u].emplace_back((Edge){ v, max(0, h[v]-h[u]) });
    g[v].emplace_back((Edge){ u, max(0, h[u]-h[v]) });
  }

  auto dist = dijkstra(0);
  int ans = 0;
  REP(i,n) ans = max(ans, h[0] - h[i] - dist[i]);
  cout << ans << endl;

  return 0;
}