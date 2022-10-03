#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();

struct Edge {
  int to, cost;
  Edge(int to, int cost) : to(to), cost(cost) {}
};
vector<vector<Edge>> g(1e5);

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
  // [現在位置のコスト, 現在位置] priority_queueでコストの小さい順にするためコストを入れる
  push(0, s);

  while (q.size()) {
    auto [cost,v] = q.top(); q.pop();
    if (dist[v] != cost) continue;
    for (Edge e: g[v]) {
      ll nc = dist[v]+e.cost;
      push(nc, e.to);
    }
  }

  return dist;
}

int main() {
  int n,m; cin >> n >> m;
  REP(i,m) {
    int a,b,c; cin >> a >> b >> c;
    a--; b--;
    g[a].emplace_back(b,c);
    g[b].emplace_back(a,c);
  }

  auto d1 = dijkstra(0);
  auto d2 = dijkstra(n-1);
  REP(i,n) {
    cout << d1[i] + d2[i] << endl;
  }
  return 0;
}