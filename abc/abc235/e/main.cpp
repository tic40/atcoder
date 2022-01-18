#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

struct Edge {
  int a,b,c,i;
  Edge(int a, int b, int c, int i = -1): a(a), b(b), c(c), i(i) {}
  bool operator<(const Edge& o) const {
    return c < o.c;
  }
};

int main() {
  int n,m,q;
  cin >> n >> m >> q;
  vector<Edge> es,ps;

  REP(i,m) {
    int a,b,c;
    cin >> a >> b >> c;
    a--; b--;
    es.emplace_back(a,b,c);
  }

  REP(i,q) {
    int u,v,w;
    cin >> u >> v >> w;
    u--; v--;
    ps.emplace_back(u,v,w,i);
  }

  sort(es.begin(),es.end());
  sort(ps.begin(),ps.end());
  vector<bool> ans(q);

  dsu d(n);
  int qi = 0;
  for(auto [a,b,c,_]: es) {
    while(qi < q && ps[qi].c < c) {
      auto [na,nb,nc,i] = ps[qi];
      ans[i] = !d.same(na,nb);
      qi++;
    }
    d.merge(a,b);
  }

  for(bool v: ans) cout << (v ? "Yes" : "No") << endl;
  return 0;
}