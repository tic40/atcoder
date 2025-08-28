#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  dsu uf(n);
  // col[i] := 頂点iの色が黒(1), 白(0)
  // cnt[i] := 頂点iを含むiとの連結している黒頂点の数
  vector<int> col(n),cnt(n);
  REP(_,q) {
    int t,v; cin >> t >> v; v--;

    if (t == 1) {
      int u; cin >> u; u--;
      u = uf.leader(u);
      v = uf.leader(v);
      if (u == v) continue;

      uf.merge(u,v);
      cnt[uf.leader(u)] = cnt[u]+cnt[v];
    }
    if (t == 2) {
      cnt[uf.leader(v)] -= col[v];
      col[v] ^= 1;
      cnt[uf.leader(v)] += col[v];
    }
    if (t == 3) {
      cout << (cnt[uf.leader(v)] > 0 ? "Yes" : "No") << endl;
    }
  }
  return 0;
}