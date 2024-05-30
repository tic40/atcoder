#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

const int m = 10;

int main() {
  int n,q; cin >> n >> q;
  vector<dsu> uf(m+1,dsu(n));
  vector<int> num(m+1);

  auto add = [&](int u, int v, int w) -> void {
    for(int i = w; i <= m; i++) {
      if (uf[i].same(u,v)) continue;
      num[i]++;
      uf[i].merge(u,v);
    }
  };

  REP(i,n-1) {
    int a,b,c; cin >> a >> b >> c;
    a--; b--;
    add(a,b,c);
  }

  REP(i,q) {
    int u,v,w; cin >> u >> v >> w;
    u--; v--;
    add(u,v,w);

    int ans = 0;
    for(int i = 1; i <= m; i++) ans += i * (num[i] - num[i-1]);
    cout << ans << endl;
  }
  return 0;
}