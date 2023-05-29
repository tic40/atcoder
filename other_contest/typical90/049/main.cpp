#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

struct Edge {
  int c,l,r;
  bool operator<(const Edge& o) const { return c < o.c; }
  Edge(int c, int l, int r): c(c),l(l),r(r) {}
};

int main() {
  int n,m; cin >> n >> m;
  vector<Edge> es;
  REP(i,m) {
    int c,l,r; cin >> c >> l >> r;
    l--; r--;
    es.emplace_back(c,l,r);
  }

  // クラスカル
  sort(es.begin(),es.end());
  dsu uf(n+1);
  ll ans = 0;
  for(auto [c,l,r]: es) {
    if (uf.same(l,r+1)) continue;
    uf.merge(l,r+1);
    ans += c;
  }

  cout << (uf.size(0) != n+1 ? -1 : ans) << endl;
  return 0;
}