#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<ll,int>;
const ll LINF = numeric_limits<ll>::max();

int main() {
  int n,m; ll x; cin >> n >> m >> x;

  auto id = [](int id, int state) { return id * 2 + state; };
  vector<vector<P>> g(2*n);
  REP(i,m) {
    int u,v; cin >> u >> v; u--; v--;
    g[id(u,0)].emplace_back(id(v,0),1);
    g[id(v,1)].emplace_back(id(u,1),1);
  }
  REP(i,n) {
    g[id(i,0)].emplace_back(id(i,1),x);
    g[id(i,1)].emplace_back(id(i,0),x);
  }

  priority_queue<P, vector<P>, greater<P>> pq;
  pq.emplace(0,id(0,0));

  vector<ll> dist(2*n,LINF);
  while(pq.size()) {
    auto [cd,i] = pq.top(); pq.pop();
    if (dist[i] < cd) continue;

    for(auto [nxt,cost]: g[i]) {
      ll nd = cd + cost;
      if (dist[nxt] > nd) {
        dist[nxt] = nd;
        pq.emplace(nd,nxt);
      }
    }
  }

  cout << min(dist[id(n-1,0)],dist[id(n-1,1)]) << endl;
  return 0;
}
