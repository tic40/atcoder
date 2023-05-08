#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<P>());
  REP(i,m) {
    int a,b,c; cin >> a >> b >> c;
    a--; b--;
    g[a].emplace_back(c,b);
    g[b].emplace_back(c,a);
  }

  auto dijkstra = [&](int i) {
    vector<int> dist(n,INF);
    priority_queue<P, vector<P>, greater<P>> q;
    q.emplace(0,i);
    dist[i] = 0;

    while(q.size()) {
      auto [cost1,now] = q.top(); q.pop();
      if (dist[now] != cost1) continue;
      for(auto [cost2,to]: g[now]) {
        int nc = cost1 + cost2;
        if (dist[to] <= nc) continue;
        q.emplace(nc,to);
        dist[to] = nc;
      }
    }
    return dist;
  };

  auto d1 = dijkstra(0);
  auto d2 = dijkstra(n-1);
  REP(i,n) cout << d1[i] + d2[i] << endl;
  return 0;
}