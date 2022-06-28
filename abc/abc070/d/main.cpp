#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;
const ll LINF = 1e18;

struct Edge {
  int to, cost;
  Edge(int to, int cost): to(to), cost(cost) {}
};

vector<vector<Edge>> g;
vector<ll> dist;

void dfs(int now, int p) {
  for(auto [nv,c]: g[now]) {
    if (nv == p) continue;
    dist[nv] = dist[now] + c;
    dfs(nv,now);
  }
  return;
}

int main() {
  int n; cin >> n;
  g.resize(n);
  dist.resize(n,LINF);
  REP(i,n-1) {
    int a,b,c; cin >> a >> b >> c;
    a--; b--;
    g[a].emplace_back(b,c);
    g[b].emplace_back(a,c);
  }

  int q,k; cin >> q >> k;
  k--;
  dist[k] = 0;
  dfs(k,-1);

  REP(i,q) {
    int x,y; cin >> x >> y;
    x--; y--;
    cout << dist[x] + dist[y] << endl;
  }
  return 0;
}