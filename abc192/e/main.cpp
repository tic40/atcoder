#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const ll INF = 1e18;

using P = pair<ll,ll>;
using Edge = struct { ll to; ll cost; ll k; };

int n,m,x,y;
vector<vector<Edge>> g;

vector<ll> dijkstra(int s) {
  vector<ll> dist(g.size(), INF);
  priority_queue<P, vector<P>, greater<P>> q;
  auto push = [&](ll nx, int to) {
    if (nx < dist[to]) {
      dist[to] = nx;
      q.emplace(dist[to], to);
    }
  };
  push(0,s);

  while (!q.empty()) {
    P p = q.top(); q.pop();
    auto d = p.first, v = p.second;
    if (dist[v] < d) continue;

    for (Edge e: g[v]) {
      ll nx = (dist[v] + e.k-1) / e.k * e.k + e.cost;
      push(nx, e.to);
    }
  }

  return dist;
}

int main() {
  cin >> n >> m >> x >> y;
  x--; y--;
  g.resize(n);
  REP(i,m) {
    int a,b,t,k;
    cin >> a >> b >> t >> k;
    a--; b--;
    g[a].emplace_back( (Edge){ b, t, k } );
    g[b].emplace_back( (Edge){ a, t, k } );
  }

  vector<ll> dist = dijkstra(x);
  ll ans = dist[y] == INF ? -1 : dist[y];
  cout << ans << endl;
  return 0;
}