#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<ll,ll>;

int main() {
  int n,a,b,c; cin >> n >> a >> b >> c;
  vector d(n,vector<ll>(n));
  REP(i,n) REP(j,n) cin >> d[i][j];

  vector g(n*2, vector<P>());
  REP(i,n) REP(j,n) if (i!=j) g[i].emplace_back(j,d[i][j]*a);
  REP(i,n) g[i].emplace_back(n+i,0);
  REP(i,n) REP(j,n) if (i!=j) g[n+i].emplace_back(n+j,d[i][j]*b+c);

  vector<ll> dist(g.size(), 1e18);
  priority_queue<P, vector<P>, greater<P>> q;
  dist[0] = 0;
  q.emplace(0,0);

  while(q.size()) {
    auto [cost,u] = q.top(); q.pop();
    if (dist[u] < cost) continue;
    for(auto [v,ncost]: g[u]) {
      if (dist[v] > cost + ncost) {
        dist[v] = cost + ncost;
        q.emplace(dist[v],v);
      }
    }
  }

  cout << min(dist[n-1],dist.back()) << endl;
  return 0;
}