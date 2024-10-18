#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = 1e18;
template<class T> void chmin(T&a, T b) { a = min(a,b); }

int main() {
  int n,m,q; cin >> n >> m >> q;
  vector<tuple<int,int,int>> edges;
  REP(i,m) {
    int u,v,t; cin >> u >> v >> t; u--; v--;
    edges.emplace_back(u,v,t);
  }

  vector<bool> blocked(m);
  vector<tuple<int,int,int>> qs;
  REP(_,q) {
    int t; cin >> t;
    if (t == 1) {
      int i; cin >> i; i--;
      blocked[i] = true;
      qs.emplace_back(t,i,-1);
    } else {
      int x,y; cin >> x >> y; x--; y--;
      qs.emplace_back(t,x,y);
    }
  }

  vector dist(n,vector<ll>(n,LINF));
  REP(i,n) dist[i][i] = 0;
  REP(i,m) if (!blocked[i]) {
    auto [u,v,cost] = edges[i];
    dist[u][v] = dist[v][u] = cost;
  }
  REP(k,n) REP(i,n) REP(j,n) chmin(dist[i][j],dist[i][k]+dist[k][j]);

  vector<ll> ans;
  reverse(qs.begin(),qs.end());
  for(auto [type,x,y]: qs) {
    if (type == 1) { // 道路の追加
      auto [u,v,cost] = edges[x];
      REP(i,n) REP(j,n) {
        chmin(dist[i][j], dist[i][u]+cost+dist[v][j]);
        chmin(dist[i][j], dist[i][v]+cost+dist[u][j]);
      }
    }
    if (type == 2) ans.push_back(dist[x][y]);
  }

  reverse(ans.begin(),ans.end());
  for(auto v: ans) cout << (v == LINF ? -1 : v) << endl;
  return 0;
}