#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;
using Edge = struct { int to; int cost; };
const int INF = 1e9;

vector<int> a,b,c;
int n,m;
vector<vector<Edge>> g;

// s: スタート位置
vector<int> dijkstra(int s) {
  vector<int> dist(g.size(), INF);
  dist[s] = 0;

  priority_queue<P, vector<P>, greater<P>> q;
  q.emplace(0, s); // [現在位置のコスト, 位置位置]

  while (!q.empty()) {
    P p = q.top(); q.pop();
    auto d = p.first, v = p.second;
    if (dist[v] < d) continue;

    for (Edge e: g[v]) {
      if (dist[v]+e.cost < dist[e.to]) {
        dist[e.to] = dist[v] + e.cost;
        q.emplace(dist[e.to], e.to);
      }
    }
  }

  return dist;
}

void solve() {
  g.resize(n);
  REP(i,m) {
    Edge e = { b[i], c[i] };
    g[a[i]].emplace_back(e);
  }

  REP(i,n) {
    vector<int> d = dijkstra(i);

    int ans = INF;
    REP(j,n) {
      for(Edge e: g[j]) {
        if (e.to == i) ans = min(ans, d[j]+e.cost);
      }
    }

    cout << (ans == INF ? -1 : ans) << endl;
  }
}

int main() {
  cin >> n >> m;
  a.resize(m); b.resize(m); c.resize(m);
  REP(i,m) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--; b[i]--;
  }

  solve();
  return 0;
}