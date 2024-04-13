#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  vector<unordered_set<int>> st(n);
  int ans = n;
  REP(i,q) {
    int t; cin >> t;
    if (t == 1) {
      int u,v; cin >> u >> v;
      if (u > v) swap(u,v);
      u--; v--;
      if (st[u].size() == 0) ans--;
      if (st[v].size() == 0) ans--;
      st[u].insert(v);
      st[v].insert(u);
    } else {
      int v; cin >> v; v--;
      if (st[v].size()) {
        for(auto a: st[v]) {
          st[a].erase(v);
          if (st[a].size() == 0) ans++;
        }
        st[v] = unordered_set<int>();
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}