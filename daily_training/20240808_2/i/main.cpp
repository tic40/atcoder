#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

const int m = 10;

int main() {
  int n,q; cin >> n >> q;
  // uf[i] := 辺の重みがすべて i 以上の dsu
  vector<dsu> uf(m+1,dsu(n));
  // num[i] :=　辺の重みが i 以上の連結になっている辺の数
  vector<int> num(m+1);

  auto add = [&](int u, int v, int w) -> void {
    for(int i = w; i <= m; i++) if (!uf[i].same(u,v)) {
      num[i]++;
      uf[i].merge(u,v);
    }
  };

  REP(i,n-1) {
    int a,b,c; cin >> a >> b >> c; a--; b--;
    add(a,b,c);
  }

  REP(_,q) {
    int u,v,w; cin >> u >> v >> w; u--; v--;
    add(u,v,w);

    // 最小全域木に含まれる辺の重みの和
    int ans = 0;
    for(int i = 1; i <= m; i++) ans += i * (num[i] - num[i-1]);
    cout << ans << endl;
  }
  return 0;
}