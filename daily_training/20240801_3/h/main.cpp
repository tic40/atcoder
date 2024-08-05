#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using mint = modint998244353;

int main() {
  int n,m,k; cin >> n >> m >> k;

  fenwick_tree<mint> dp(m+1);
  for(int i = 1; i <= m; i++) dp.add(i,1);

  REP(_,n-1) {
    fenwick_tree<mint> p(m+1);
    swap(dp,p);
    for(int j = 1; j <= m; j++) {
      if (k == 0) {
        dp.add(j, p.sum(1,m+1));
      } else {
        dp.add(j, p.sum(1, max(1,j-k+1)));
        dp.add(j, p.sum(min(m+1,j+k), m+1));
      }
    }
  }

  cout << dp.sum(1,m+1).val() << endl;
  return 0;
}