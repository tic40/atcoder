#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector<pair<int,P>> es(n);
  REP(i,n-1) {
    int u,v,w; cin >> u >> v >> w;
    u--; v--;
    es[i] = {w, P(u,v)};
  }

  sort(es.begin(),es.end());
  dsu uf(n);

  ll ans = 0;
  for(auto [w,e]: es) {
    auto [a,b] = e;
    ans += (ll)w * uf.size(a) * uf.size(b);
    uf.merge(a,b);
  }

  cout << ans << endl;
  return 0;
}