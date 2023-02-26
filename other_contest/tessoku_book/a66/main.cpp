#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  dsu uf(n);
  REP(_,q) {
    int t,u,v; cin >> t >> u >> v;
    u--; v--;
    if (t == 1) uf.merge(u,v);
    else cout << (uf.same(u,v) ? "Yes" : "No") << endl;
  }
  return 0;
}