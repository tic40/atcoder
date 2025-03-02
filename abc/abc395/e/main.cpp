#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<ll,int>;
const ll LINF = numeric_limits<ll>::max();

int main() {
  int n,m,x; cin >> n >> m >> x;
  vector g(n*2,vector<P>());
  REP(i,m) {
    int u,v; cin >> u >> v; u--; v--;
    g[u].emplace_back(v,1);
    g[v+n].emplace_back(u+n,1);
  }
  REP(i,n) {
    g[i].emplace_back(i+n,x);
    g[i+n].emplace_back(i,x);
  }

  vector<ll> dist(n*2,LINF);
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.emplace(0,0);
  dist[0] = 0;

  while(pq.size()) {
    auto [cd,i] = pq.top(); pq.pop();
    if (dist[i] < cd) continue;

    for(auto [ni,cost]: g[i]) {
      ll ndist = dist[i]+cost;
      if (dist[ni] <= ndist) continue;
      dist[ni] = ndist;
      pq.emplace(ndist,ni);
    }
  }

  cout << min(dist[n-1],dist[n*2-1]) << endl;
  return 0;
}
