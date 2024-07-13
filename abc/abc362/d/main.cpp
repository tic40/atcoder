#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
using PL = pair<ll,int>;

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  vector g(n,vector<P>());
  REP(i,m) {
    int u,v,b; cin >> u >> v >> b;
    u--; v--;
    g[u].emplace_back(v,b);
    g[v].emplace_back(u,b);
  }

  priority_queue<PL, vector<PL>, greater<PL>> q;
  q.emplace(a[0],0);
  vector<ll> dist(n,1e18);
  dist[0] = a[0];

  while(q.size()) {
    auto [w,v] = q.top(); q.pop();
    if (dist[v] < w) continue;
    for(auto [nv,b]: g[v]) {
      ll ndist = dist[v] + b + a[nv];
      if (dist[nv] <= ndist) continue;

      q.emplace(ndist,nv);
      dist[nv] = ndist;
    }
  }

  for(int i = 1; i < n; i++) cout << dist[i] << " ";
  return 0;
}