#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<int>());
  dsu uf(n);
  vector<int> deg(n);
  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    deg[a]++; deg[b]++;
    uf.merge(a,b);
  }

  ll ans = 0;
  for(auto group: uf.groups()) {
    int sz = group.size();
    ll now = (ll)sz * (sz - 1) / 2;
    int edges = 0;
    for(auto v: group) edges += deg[v];
    ans += now - edges / 2;
  }
  cout << ans << endl;
  return 0;
}