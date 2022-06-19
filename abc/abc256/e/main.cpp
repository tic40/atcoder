#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> x(n),c(n);
  REP(i,n) { cin >> x[i]; x[i]--; }
  REP(i,n) cin >> c[i];

  dsu uf(n);
  ll ans = 0;
  REP(i,n) {
    if (!uf.same(i,x[i])) {
      uf.merge(i,x[i]);
      continue;
    }

    int cur = c[i], v = i;
    while(1) {
      v = x[v];
      cur = min(cur,c[v]);
      if (v == i) break;
    }
    ans += cur;
  }
  cout << ans << endl;
  return 0;
}