#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using mint = modint998244353;

mint dp[51][2501];
int main() {
  ll n,m,k; cin >> n >> m >> k;

  dp[0][0] = 1;
  REP(i,n) REP(j,k+1) {
    for(int t = j+1; t <= j+m; t++) dp[i+1][t] += dp[i][j];
  }

  mint ans = 0;
  REP(i,k+1) ans += dp[n][i];
  cout << ans.val() << endl;
  return 0;
}