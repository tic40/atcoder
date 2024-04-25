#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();
using P = pair<ll,int>;

int main() {
  int n,m; cin >> n >> m;
  vector<int> h(n);
  REP(i,n) cin >> h[i];
  vector g(n,vector<int>());
  REP(i,m) {
    int u,v; cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  priority_queue<P, vector<P>, greater<P>> q;
  q.emplace(0,0);
  vector<ll> dist(n,LINF);
  dist[0] = 0;

  while(q.size()) {
    auto [d,i] = q.top(); q.pop();
    for(auto v: g[i]) {
      ll nc = dist[i] + max(0, h[v]-h[i]);
      if (dist[v] <= nc) continue;
      q.emplace(nc,v);
      dist[v] = nc;
    }
  }

  ll ans = 0;
  REP(i,n) ans = max(ans, h[0] - h[i] - dist[i]);
  cout << ans << endl;

  return 0;
}