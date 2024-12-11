#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using T = tuple<int,int,int>;

int main() {
  int n,m,k; cin >> n >> m >> k;
  vector<T> edges;
  REP(i,m) {
    int u,v,w; cin >> u >> v >> w;
    u--; v--;
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
    if (a[v]) swap(u,v); // u が a, v が b になるように swap
    if (!a[u] || !b[v]) continue;

    // x = マッチングできる数。これは両者の min の数だけ
    int x = min(a[u],b[v]);
    ans += (ll)w * x;
    a[u] -= x; b[v] -= x;
    int suma = a[u]+a[v];
    int sumb = b[u]+b[v];
    uf.merge(u,v);
    a[uf.leader(u)] = suma;
    b[uf.leader(u)] = sumb;
  }
  cout << ans << endl;
  return 0;
}
