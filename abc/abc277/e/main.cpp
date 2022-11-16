#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();

struct Edge {
  int to,cost;
  Edge(int to, int cost): to(to), cost(cost) {}
};

int main() {
  int n,m,k; cin >> n >> m >> k;
  int n2 = n*2;
  vector<vector<Edge>> g(n2);
  REP(i,m) {
    int u,v,a; cin >> u >> v >> a;
    u--; v--;
    if (a == 1) {
      g[u].emplace_back(v,1);
      g[v].emplace_back(u,1);
    } else {
      g[n+u].emplace_back(n+v,1);
      g[n+v].emplace_back(n+u,1);
    }
  }

  REP(i,k) {
    int s; cin >> s;
    s--;
    g[s].emplace_back(n+s,0);
    g[n+s].emplace_back(s,0);
  }

  vector<int> dist(n2,INF);
  dist[0] = 0;
  deque<P> dq;
  dq.emplace_back(0,0);

  while(dq.size()) {
    auto [d,i] = dq.front();
    dq.pop_front();
    if (d != dist[i]) continue;

    for(auto e: g[i]) {
      int nd = d + e.cost;
      if (nd >= dist[e.to]) continue;
      dist[e.to] = nd;
      if (e.cost == 0) dq.emplace_front(nd,e.to);
      else dq.emplace_back(nd,e.to);
    }
  }

  int ans = min(dist[n-1], dist[n2-1]);
  cout << (ans == INF ? -1 : ans) << endl;
  return 0;
}