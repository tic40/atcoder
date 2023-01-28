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
  REP(i,n) cnt[min(3,deg[i])]++;

  bool ok = uf.size(0) == n && cnt[1] == 2 && cnt[2] == n-2;
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}