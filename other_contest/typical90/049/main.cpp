#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

struct Edge {
  int c; int l; int r;
  bool operator<(const Edge& o) const { return c < o.c; }
};

int main() {
  int n,m; cin >> n >> m;
  vector<Edge> edges(m);
  REP(i,m) {
    int c,l,r; cin >> c >> l >> r;
    l--; r--;
    edges[i] = {c,l,r};
  }


  ll ans = 0;
  dsu uf(n+1); // N+1頂点

  // クラスカル
  // costの昇順にソート
  sort(edges.begin(), edges.end());
  for(auto [c,l,r]: edges) {
    if (uf.same(l,r+1)) continue;
    uf.merge(l,r+1);
    ans += c;
  }

  if (uf.size(0) != n+1) ans = -1;
  cout << ans << endl;
  return 0;
}