#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const ll LINF = 1e18;

int n,m;
vector<ll> h;
ll ans = 0;

using Edge = struct { int to; ll cost; };
vector<vector<Edge>> g;
using P = pair<ll,int>;

// s: スタート位置
vector<ll> dijkstra(int s) {
  vector<ll> dist(g.size(), LINF);
  priority_queue<P, vector<P>, greater<P>> q;

  // cost: toに移動するときのコスト, to: 移動先
  auto push = [&](ll cost, ll to) {
    if (dist[to] <= cost) return;
    dist[to] = cost;
    q.emplace(dist[to], to);
  };
  push(0, s); // [現在位置のコスト, 現在位置]

  while (q.size()) {
    auto [d,v] = q.top(); q.pop();
    // if (dist[v] != d) continue;
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
    int u,v; cin >> u >> v;
    u--; v--;

    g[u].emplace_back((Edge){v, max(0LL, h[v]-h[u]) });
    g[v].emplace_back((Edge){u, max(0LL, h[u]-h[v]) });
  }

  auto dist = dijkstra(0);

  ll ans = 0;
  REP(i,n) ans = max(ans, h[0]-h[i]-dist[i]);
  cout << ans << endl;
  return 0;
}