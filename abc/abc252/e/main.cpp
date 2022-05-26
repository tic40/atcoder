#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;
const ll LINF = 1e18+5;
struct Edge {
  int id,to,cost;
  Edge(int id, int to, int cost): id(id),to(to),cost(cost) {}
};
using P = pair<ll,int>;

int main() {
  int n,m; cin >> n >> m;
  vector<vector<Edge>> g(n);
  REP(i,m) {
    int a,b,c; cin >> a >> b >> c;
    a--; b--;
    g[a].emplace_back(i+1,b,c);
    g[b].emplace_back(i+1,a,c);
  }

  priority_queue<P, vector<P>, greater<P>> q;
  vector<ll> dist(n,LINF);
  vector<int> from(n);
  q.emplace(0,0);
  dist[0] = 0;

  while(q.size()) {
    auto [c,v] = q.top(); q.pop();
    if (dist[v] < c) continue;
    for(Edge e: g[v]) {
      ll nc = c + e.cost;
      if (nc < dist[e.to]) {
        dist[e.to] = nc;
        q.emplace(nc,e.to);
        from[e.to] = e.id;
      }
    }
  }

  for(int i = 1; i < n; i++) cout << from[i] << " ";
  cout << endl;
  return 0;
}
