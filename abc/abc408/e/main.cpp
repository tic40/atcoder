#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<tuple<int,int,int>> edges;
  REP(i,m) {
    int u,v,w; cin >> u >> v >> w;
    u--; v--;
    edges.emplace_back(u,v,w);
  }

  int ans = 0;
  for(int i = 29; i >= 0; i--) {
    dsu uf(n);
    for(auto [u,v,c]: edges) {
      if (((c>>i)|(ans>>i)) != (ans>>i)) continue;
      uf.merge(u,v);
    }
    if (!uf.same(0,n-1)) ans |= 1<<i;
  }
  cout << ans << endl;
  return 0;
}