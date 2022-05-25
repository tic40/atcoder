#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;
const ll LINF = 1e18;
struct Edge { int id, to, cost; };
using P = pair<ll,int>;

int main() {
  int n,m; cin >> n >> m;
  vector<vector<Edge>> g(n);
  REP(i,m) {
    int a,b,c; cin >> a >> b >> c;
    a--; b--;
    g[a].emplace_back(Edge{i+1,b,c});
    g[b].emplace_back(Edge{i+1,a,c});
  }

  vector<ll> d(n, LINF);
  vector<int> from(n,-1);
  priority_queue<P, vector<P>, greater<P>> q;
  d[0] = 0;
  q.emplace(0,0);

  while(q.size()) {
    auto [c, v] = q.top(); q.pop();
    if (d[v] != c) continue;
    for(Edge edge: g[v]) {
      ll nc = c + edge.cost;
      if (d[edge.to] <= nc) continue;
      d[edge.to] = nc;
      from[edge.to] = edge.id;
      q.emplace(nc, edge.to);
    }
  }

  for(int i = 1; i < n; i++) cout << from[i] << " ";
  cout << endl;

  return 0;
}
