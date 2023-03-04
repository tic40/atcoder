#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  dsu uf(n);
  vector<int> deg(n);
  REP(i,m) {
    int u,v; cin >> u >> v;
    u--; v--;
    deg[u]++;
    uf.merge(v,u);
  }

  bool ans = true;
  for(auto g: uf.groups()) {
    int cnt = 0;
    for(int v: g) cnt += deg[v];
    if ((int)g.size() != cnt) ans = false;
  }

  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}