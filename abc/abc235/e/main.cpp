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
  int from, to, cost, i;
  Edge(int from, int to, int cost, int i = -1): from(from), to(to), cost(cost), i(i) {}
  bool operator<(const Edge& o) const { // costで順序定義
    return cost < o.cost;
  }
};

int n,m,q;
vector<Edge> es, qs;

int main() {
  cin >> n >> m >> q;
  REP(i,m) {
    int a,b,c;
    cin >> a >> b >> c;
    a--; b--;
    es.emplace_back(a,b,c);
  }
  sort(es.begin(), es.end());

  REP(i,q) {
    int u,v,w;
    cin >> u >> v >> w;
    u--; v--;
    qs.emplace_back(u,v,w,i);
  }

  vector<bool> ans(q);
  sort(qs.begin(), qs.end());
  dsu t(n);

  int qi = 0;
  for(auto [from, to, cost, _]: es) {
    while(qi < q && qs[qi].cost < cost) {
      auto [nfrom, nto, ncost, i] = qs[qi];
      qi++;
      ans[i] = !t.same(nfrom, nto);
    }
    t.merge(from, to);
  }

  REP(i,q) cout << (ans[i] ? "Yes" : "No") << endl;
  return 0;
}