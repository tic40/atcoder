#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  vector<tuple<int,int,int>> es(m);
  REP(i,m) {
    int a,b,c;
    cin >> a >> b >> c;
    a--; b--;
    es[i] = {c,a,b};
  }
  sort(es.begin(),es.end());

  dsu uf(n);
  ll ans = 0;
  for(auto [cost,from,to]: es) {
    if (uf.same(from,to)) continue;
    uf.merge(from,to);
    ans += cost;
  }
  cout << ans << endl;
  return 0;
}