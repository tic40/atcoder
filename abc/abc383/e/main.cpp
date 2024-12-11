#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m,k; cin >> n >> m >> k;
  vector<tuple<int,int,int>> edges;
  REP(i,m) {
    int u,v,w; cin >> u >> v >> w; u--; v--;
    edges.emplace_back(w,u,v);
  }
  sort(edges.begin(),edges.end());

  vector<int> a(n),b(n);
  REP(i,k) { int x; cin >> x; x--; a[x]++; }
  REP(i,k) { int x; cin >> x; x--; b[x]++; }

  dsu uf(n);
  ll ans = 0;
  for(auto [w,u,v]: edges) if (!uf.same(u,v)) {
    u = uf.leader(u);
    v = uf.leader(v);
    if (!a[v] || !b[u]) swap(u,v); // u が a, v が b になるように swap

    // x = マッチングできる数。これは両者の min の数だけ
    int add = min(a[u],b[v]);
    ans += (ll)w * add;
    a[u] -= add; b[v] -= add;
    int sa = a[u]+a[v];
    int sb = b[u]+b[v];
    uf.merge(u,v);
    a[uf.leader(u)] = sa;
    b[uf.leader(u)] = sb;
  }
  cout << ans << endl;
  return 0;
}
