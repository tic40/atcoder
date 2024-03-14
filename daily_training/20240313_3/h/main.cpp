#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using mint = modint;

struct Edge {
  int from, to, cost;
  Edge(int from = -1, int to = -1, int cost = 0): from(from), to(to), cost(cost) {}
  bool operator<(const Edge& o) const { return cost < o.cost; }
};

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  mint::set_mod(m);
  auto f = [&](ll x, ll y) {
    mint res = ((mint)x).pow(y) + ((mint)y).pow(x);
    return res.val();
  };

  vector<Edge> edges;
  REP(i,n) REP(j,n) edges.emplace_back(i,j,f(a[i],a[j]));
  sort(edges.rbegin(),edges.rend());

  dsu uf(n);
  ll ans = 0;
  for(auto [from,to,cost]: edges) {
    if (uf.same(from,to)) continue;
    uf.merge(from,to);
    ans += cost;
  }

  cout << ans << endl;
  return 0;
}