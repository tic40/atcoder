#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using mint = modint998244353;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  mint ans = 0;
  for(int m = 1; m <= n; m++) {
    vector dp(n+1, vector(m+2, vector<mint>(m)));
    dp[0][0][0] = 1;
    REP(i,n) REP(j,m+1) REP(k,m) {
      dp[i+1][j][k] += dp[i][j][k];
      dp[i+1][j+1][ (k+a[i])%m ] += dp[i][j][k];
    }
    ans += dp[n][m][0];
  }

  cout << ans.val() << endl;
  return 0;
}