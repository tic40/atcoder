#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;

int n,m;
vector<ll> h;
ll ans = 0;

using Edge = struct { ll to; ll cost; };
vector<vector<Edge>> g;
using P = pair<ll,ll>;

// s: スタート位置
vector<ll> dijkstra(int s) {
  vector<ll> dist(g.size(), -INF);
  priority_queue<P, vector<P>, greater<P>> q;

  auto push = [&](ll nx, ll to) {
    if (dist[to] >= nx) return;
    dist[to] = nx;
    q.emplace(dist[to], to);
  };
  // スタート位置をコスト0で追加
  push(0, s); // [現在位置のコスト, 現在位置]

  while (!q.empty()) {
    P p = q.top(); q.pop();
    // auto d = p.first,
    auto v = p.second;
    for (Edge e: g[v]) {
      ll nx = dist[v]+e.cost;
      push(nx, e.to);
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
    int u,v; cin >> u >> v;
    u--; v--;

    int uv = 0;
    if (h[u] < h[v]) uv = -2*(h[v]-h[u]);
    if (h[v] < h[u]) uv = (h[u]-h[v]);

    int vu = 0;
    if (h[v] < h[u]) vu = -2*(h[u]-h[v]);
    if (h[u] < h[v]) vu = (h[v]-h[u]);

    g[u].emplace_back((Edge){v, uv});
    g[v].emplace_back((Edge){u, vu});
  }

  auto dist = dijkstra(0);
  ll ans = 0;
  for(auto v: dist) ans = max(ans, v);
  cout << ans << endl;
  return 0;
}