#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
using mint = modint;
using Edge = pair<int, P>;

int f(int x, int y) {
  return (mint(x).pow(y) + mint(y).pow(x)).val();
}

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  mint::set_mod(m);

  vector<Edge> edges;
  REP(i,n) REP(j,i) {
    edges.emplace_back(f(a[i],a[j]), P(i,j));
  }

  sort(edges.rbegin(), edges.rend());
  dsu uf(n);
  ll ans = 0;
  for(auto [w,e]: edges) {
    auto [a,b] = e;
    if (uf.same(a,b)) continue;
    uf.merge(a,b);
    ans += w;
  }
  cout << ans << endl;
  return 0;
}