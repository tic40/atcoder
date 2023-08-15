#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353;

int main() {
  int n,m,k; cin >> n >> m >> k;
  mint p = mint(1) / m;

  vector dp(k+1,vector<mint>(n+1));
  dp[0][0] = 1;
  REP(i,k) {
    REP(j,n) {
      if (dp[i][j] == 0) continue;
      for(int l = 1; l <= m; l++) {
        int nj = j+l <= n ? j+l : n-(j+l-n);
        dp[i+1][nj] += dp[i][j] * p;
      }
    }
    dp[i+1][n] += dp[i][n];
  }
  cout << dp[k][n].val() << endl;
  return 0;
}