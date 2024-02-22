#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();
template<class T> void chmin(T& a, T b) { a = min(a,b); }

struct Edge {
  int to; ll cost;
  Edge(int to, ll cost ): to(to), cost(cost) {}
};

int main() {
  int n,m; ll k; cin >> n >> m >> k;
  vector g(n,vector<Edge>());
  REP(i,m) {
    int u,v; ll c;
    cin >> u >> v >> c;
    u--; v--;
    g[u].emplace_back(v,c);
    g[v].emplace_back(u,c);
  }

  auto dfs = [&](auto self, dsu d, int i, ll cost) -> ll {
    if (i == n-1) {
      return (d.size(0) == n) ? cost : LINF;
    }

    ll res = LINF;
    for(auto [to,c]: g[i]) {
      if (d.same(i,to)) {
        chmin(res, self(self,d,i+1,cost));
      } else {
        auto nd = d;
        nd.merge(i,to);
        chmin(res, self(self,nd,i+1,(cost+c) % k));
      }
    }
    return res;
  };

  cout << dfs(dfs,dsu(n),0,0) << endl;
  return 0;
}