#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using mint = modint998244353;

int main() {
  int n,k; cin >> n >> k;
  vector<int> l(k),r(k);
  REP(i,k) cin >> l[i] >> r[i];

  vector<mint> dp(n+1), dpsum(n+1);
  dp[1] = 1;
  dpsum[1] = 1;

  // もらうDP
  for(int i = 2; i <= n; i++) {
    REP(j,k) {
      int li = max(1, i - r[j]);
      int ri = i - l[j];
      if (ri < 0) continue;

      dp[i] += dpsum[ri] - dpsum[li-1];
    }
    dpsum[i] = dpsum[i-1] + dp[i];
  }

  cout << dp[n].val() << endl;
  return 0;
}