#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int n,m;
struct Edge {
  int c; int l; int r;
  bool operator<(const Edge& o) const { return c < o.c; }
};

int main() {
  cin >> n >> m;
  vector<Edge> edges;
  REP(i,m) {
    int c,l,r; cin >> c >> l >> r;
    edges.emplace_back(Edge{c,l-1,r});
  }

  sort(edges.begin(), edges.end());

  ll ans = 0;
  dsu uf(n+1);

  for(auto [c,l,r]: edges) {
    if (uf.same(l,r)) continue;

    uf.merge(l,r);
    ans += c;
  }

  if (uf.size(0)-1 != n) ans = -1;
  cout << ans << endl;
  return 0;
}