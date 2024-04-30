#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<int> deg(n);
  dsu uf(n);
  REP(i,m) {
    int u,v; cin >> u >> v;
    u--; v--;
    deg[u]++;
    deg[v]++;
    uf.merge(u,v);
  }

  vector<int> cnt(4);
  int one = 0, two = 0;
  REP(i,n) {
    if (deg[i] == 1) one++;
    if (deg[i] == 2) two++;
  }

  bool ok = uf.size(0) == n && one == 2 && two == n-2;
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}