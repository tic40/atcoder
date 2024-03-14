#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  dsu uf(n);
  REP(i,m) {
    int u,v; cin >> u >> v;
    u--; v--;
    uf.merge(u,v);
  }
  cout << uf.groups().size() << endl;
  return 0;
}