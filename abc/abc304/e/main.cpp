#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n,m; cin >> n >> m;
  dsu uf(n);
  REP(i,m) {
    int u,v; cin >> u >> v;
    u--; v--;
    uf.merge(u,v);
  }

  set<P> st;
  int k; cin >> k;
  REP(i,k) {
    int x,y; cin >> x >> y;
    x--; y--;
    int l1 = uf.leader(x), l2 = uf.leader(y);
    if (l1 > l2) swap(l1,l2);
    st.emplace(l1,l2);
  }

  int q; cin >> q;
  REP(i,q) {
    int u,v; cin >> u >> v;
    u--; v--;
    int l1 = uf.leader(u), l2 = uf.leader(v);
    if (l1 > l2) swap(l1,l2);
    cout << (st.count({l1,l2}) ? "No" : "Yes") << endl;
  }
  return 0;
}