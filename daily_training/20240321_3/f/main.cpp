#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353; // modint1000000007;

int main() {
  int n,m,k; cin >> n >> m >> k;
  vector dp(n+1,vector<mint>(k+1));
  dp[0][0] = 1;
  REP(i,n) REP(j,k) {
    if (dp[i][j] == 0) continue;
    for(int l = 1; l <= m; l++) {
      int nj = j+l;
      if (nj > k) break;
      dp[i+1][nj] += dp[i][j];
    }
  }
  mint ans = 0;
  REP(i,k+1) ans += dp[n][i];
  cout << ans.val() << endl;
  return 0;
}