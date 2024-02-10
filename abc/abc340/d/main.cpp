#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<ll,int>;
const ll LINF = numeric_limits<ll>::max();

struct Edge {
  int to, cost;
  Edge(int to, int cost): to(to), cost(cost) {}
};

int main() {
  int n; cin >> n;
  vector g(n,vector<Edge>());
  REP(i,n-1) {
    int a,b,x; cin >> a >> b >> x;
    x--;
    g[i].emplace_back(i+1,a);
    g[i].emplace_back(x,b);
  }

  vector<ll> dist(n,LINF);
  priority_queue<P, vector<P>, greater<P>> q;
  auto push = [&](ll cost, int to) {
    if (dist[to] <= cost) return;
    dist[to] = cost;
    q.emplace(dist[to], to);
  };

  push(0,0);
  while (q.size()) {
    auto [cost,v] = q.top(); q.pop();
    if (dist[v] != cost) continue;
    for (Edge e: g[v]) push(dist[v]+e.cost, e.to);
  }

  cout << dist[n-1] << endl;
  return 0;
}