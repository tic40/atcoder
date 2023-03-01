#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
using P2 = pair<P,int>;
const int INF = numeric_limits<int>::max();

struct Edge {
  int to; P p;
  Edge(int to, P p): to(to), p(p) {}
};

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<Edge>());
  REP(i,m) {
    int a,b,c,d; cin >> a >> b >> c >> d;
    a--; b--;
    g[a].emplace_back(b,P{c,-d});
    g[b].emplace_back(a,P{c,-d});
  }

  priority_queue<P2, vector<P2>, greater<P2>> q;
  vector<P> dist(n,{INF,0});
  auto push = [&](int ndist, int ntree, int i) {
    if (dist[i].first < ndist) return;
    if (dist[i].first == ndist && dist[i].second <= ntree) return;
    dist[i] = { ndist, ntree };
    q.emplace(dist[i],i);
  };

  push(0,0,0);
  while(q.size()) {
    auto [p,i] = q.top(); q.pop();
    for(auto v: g[i]) {
      int ndist = p.first + v.p.first;
      int ntree = p.second + v.p.second;
      push(ndist,ntree,v.to);
    }
  }

  cout << dist[n-1].first << " " << -dist[n-1].second << endl;
  return 0;
}