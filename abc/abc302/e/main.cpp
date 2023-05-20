#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  vector g(n,unordered_set<int>());
  int now = n;
  REP(i,q) {
    int t; cin >> t;
    if (t == 1) {
      int u,v; cin >> u >> v;
      u--; v--;
      g[u].insert(v); g[v].insert(u);
      if ((int)g[u].size() == 1) now--;
      if ((int)g[v].size() == 1) now--;
    } else {
      int v; cin >> v; v--;
      if (g[v].size()) {
        for(auto x: g[v]) {
          g[x].erase(v);
          if (g[x].size() == 0) now++;
        }
        g[v].clear(); now++;
      }
    }
    cout << now << endl;
  }
  return 0;
}