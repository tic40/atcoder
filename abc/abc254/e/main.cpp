#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9+5;

int main() {
  int n,m; cin >> n >> m;
  vector<vector<int>> g(n);
  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int q; cin >> q;
  REP(i,q) {
    int x,k; cin >> x >> k;
    x--;

    unordered_set<int> st = {x};
    vector<int> v = {x};
    int ans = x+1;
    REP(j,k) {
      vector<int> pv;
      swap(v,pv);
      for(int x: pv) for(int y: g[x]) {
        if (st.count(y)) continue;
        st.insert(y);
        v.push_back(y);
        ans += y+1;
      }
    }

    cout << ans << endl;
  }
  return 0;
}